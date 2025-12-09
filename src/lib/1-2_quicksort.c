/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/quicksort.c                                                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <stddef.h>
#include <stdint.h>

#include "./common.h"
#include "./lzcnt.h"
#include "./qsort.h"

/* //////////////////////////////////////////////////////////////////////// */

#define QUICKSORT_DEPTH_MAX_MAX		(2u * (SIZE_BITS - 1u))

struct QuickSort_Level {
	struct Item lo;
	struct Item hi;
};

struct QuickSort_Stack {
	unsigned int		depth_max;
	unsigned int		depth;
	struct QuickSort_Level	level[QUICKSORT_DEPTH_MAX_MAX + 1u];
};

/* ------------------------------------------------------------------------ */

/**@fn QUICKSORT_DEPTH_MAX
 * @return maximum depth that quicksort will operate before calling a fallback
 *
 * @param nmemb - number of items in the array
**/
#define QUICKSORT_DEPTH_MAX(x_nmemb) ( \
	2u * (SIZE_BITS - lzcnt_usize(x_nmemb) - 1u) \
)

/* //////////////////////////////////////////////////////////////////////// */

/**@fn IDX_MID
 * @return index of the middle item (without overflowing)
 *
 * @param lo - index of the lowest (first) item
 * @param hi - index of the highest (last) item
**/
#define IDX_MID(x_lo, x_hi)	((x_lo) + (((x_hi) - (x_lo)) / 2u))

/* ======================================================================== */

#undef base
#undef lo
#undef hi
ALWAYS_INLINE struct Item quick_partition(
	uint8_t *RESTRICT base, size_t, const struct QSortFnPtrs *RESTRICT,
	struct Item lo, struct Item hi
)
/*@modifies	*base,
		*lo.ptr,
		*hi.ptr

@*/
;

ALWAYS_INLINE struct Item quick_pivot_select(
	uint8_t *RESTRICT, size_t, const struct QSortFnPtrs *RESTRICT,
	struct Item, struct Item
)
/*@*/
;

/* //////////////////////////////////////////////////////////////////////// */

/**@fn qsort_quicksort
 * @brief an iterative, hybrid quicksort (modified introsort)
 *
 * @param base  - pointer to the beginning of the array to sort
 * @param nmemb - number of items in the array
 * @param size  - size of each array item
 * @param qsfp  - pointer to the 'compar' and 'swap' functions
**/
BUILD_HIDDEN
QSORT_SWAP_ABI
NOINLINE void
qsort_quicksort(
	uint8_t *const RESTRICT base, size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp
)
/*@modifies	*base@*/
{
	struct QuickSort_Stack stack;
	struct QuickSort_Level level;
	struct Item pivot, pivot_lo, pivot_hi;

	/* assuming that: (ASSUME() may make things slower)
	       - (nmemb > SIZE_C(1))
	       - (size  > 0)
	       - '(nmemb * size)' will not overflow
	*/

	stack.depth_max   = QUICKSORT_DEPTH_MAX(nmemb);
	stack.depth       = 0;
	stack.level[0].lo = ITEM_BUILD(base, 0, size);
	stack.level[0].hi = ITEM_BUILD(base, nmemb - 1u, size);

	for(;;) {

		level = stack.level[stack.depth];
		nmemb = level.hi.idx - level.lo.idx + 1u;

		if UNLIKELY ( nmemb < SIZE_C(2) ){
			if ( stack.depth-- > 0 ){
				continue;
			}
			else {	break; }
		}
		else if ( nmemb <= QSORT_SHELLSORT_MAX_NMEMB ){
			qsort_shellsort(level.lo.ptr, nmemb, size, qsfp);
			if ( stack.depth-- > 0 ){
				continue;
			}
			else {	break; }
		}
		else if UNLIKELY ( stack.depth > stack.depth_max ){
			qsort_heapsort(level.lo.ptr, nmemb, size, qsfp);
			if ( stack.depth-- > 0 ){
				continue;
			}
			else {	break; }
		} else{;}

		pivot = quick_partition(base, size, qsfp, level.lo, level.hi);

		/* the current partition is overwritten with the new 'hi', and
		     the 'lo' partition will be pushed to the top of the stack
		     (next); working low to high through memory
		*/
		ITEM_NEXT(pivot_hi, pivot, size);
		stack.level[stack.depth].lo = pivot_hi;
		stack.level[stack.depth].hi = level.hi;
		if ( pivot.idx > 0 ){
			stack.depth += 1u;
			ITEM_PREV(pivot_lo, pivot, size);
			stack.level[stack.depth].lo = level.lo;
			stack.level[stack.depth].hi = pivot_lo;
		}
	}
	return;
}

/* ------------------------------------------------------------------------ */

/**@fn quick_partition
 * @brief selects a pivot item, then organizes the partition accordingly
 *
 * @return pivot item struct
 *
 * @param base - pointer to the beginning of the array to sort
 * @param size - size of each array item
 * @param qsfp - pointer to the 'compar' and 'swap' functions
 * @param lo   - lowest (first) item in the partition
 * @param hi   - highest (last) item in the partition
**/
ALWAYS_INLINE struct Item
quick_partition(
	uint8_t *const RESTRICT base, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp,
	struct Item lo, struct Item hi
)
/*@modifies	*base,
		*lo.ptr,
		*hi.ptr

@*/
{
	struct Item pivot, sec;

	/* assuming that: (ASSUME() may make things slower)
	       - '(hi.idx - lo.idx > SIZE_C(1))'; ie., at least 3 items
	*/

	/* choose a pivot then swap it to index-0 (lo)
	   the second item (sec) is used to prevent a comparison/swap between
	     lo and pivot (qsfp->swap() parameters may not alias)
	*/
	ITEM_NEXT(sec, lo, size);
	pivot = quick_pivot_select(base, size, qsfp, sec, hi);
	QSFP_SWAP(lo.ptr, pivot.ptr);
	pivot = lo;
	lo    = sec;

	/* check if each item is <= the pivot */
	#pragma unroll(2u)
	while LIKELY ( lo.idx <= hi.idx ){
		if ( QSFP_COMPAR(lo.ptr, pivot.ptr) <= 0 ){
			ITEM_NEXT(lo, lo, size);
			if UNLIKELY ( lo.idx > hi.idx ){
				QSFP_SWAP(hi.ptr, pivot.ptr);
				return hi;
			}
		}
		else {	break; }
	}

	/* main compare/swap loop */
	goto loop_entr;
	do {	QSFP_SWAP(lo.ptr, hi.ptr);

		/* find the next leftmost item > the pivot */
		while ( QSFP_COMPAR(lo.ptr, pivot.ptr) <= 0 ){
			ITEM_NEXT(lo, lo, size);
			if ( lo.idx >= hi.idx ){
				goto loop_exit;
			}
		}
loop_entr:
		/* find the next rightmost item <= the pivot */
		while ( QSFP_COMPAR(hi.ptr, pivot.ptr) >  0 ){
			ITEM_PREV(hi, hi, size);
			if ( lo.idx >= hi.idx ){
				goto loop_exit;
			}
		}
	} while LIKELY ( lo.idx < hi.idx );
loop_exit:

	/* swap the pivot into place */
	ITEM_PREV(lo, lo, size);
	if LIKELY ( lo.idx != pivot.idx ){
		QSFP_SWAP(lo.ptr, pivot.ptr);
	}
	return lo;
}

/**@fn quick_pivot_select
 * @brief selects the median of the lo, hi, and mid items to be the pivot
 *
 * @return pivot item struct
 *
 * @param base - pointer to the beginning of the array to sort
 * @param size - size of each array item
 * @param qsfp - pointer to the 'compar' and 'swap' functions
 * @param lo   - lowest (first) item in the partition
 * @param hi   - highest (last) item in the partition
**/
ALWAYS_INLINE struct Item
quick_pivot_select(
	uint8_t *const RESTRICT base, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp,
	const struct Item lo, const struct Item hi
)
/*@*/
{
	struct Item mid = ITEM_BUILD(base, IDX_MID(lo.idx, hi.idx), size);

	if ( QSFP_COMPAR(lo.ptr, hi.ptr) <= 0 ){
		if ( QSFP_COMPAR(lo.ptr, mid.ptr) > 0 ){
			mid = lo;
		}
	}
	else {	if ( QSFP_COMPAR(hi.ptr, mid.ptr) > 0 ){
			mid = hi;
		}
	}
	return mid;
}

/* EOF //////////////////////////////////////////////////////////////////// */
