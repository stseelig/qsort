/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/shellsort.c                                                        //
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
#include "./qsort.h"

/* //////////////////////////////////////////////////////////////////////// */

/* gaps optimized for small (~56 item) int32 arrays */
#define SHELL_GAP_B	SIZE_C(11)
#define SHELL_GAP_A	SIZE_C( 3)
#define SHELL_GAP_1	SIZE_C( 1)

/* //////////////////////////////////////////////////////////////////////// */

#undef base
ALWAYS_INLINE void shell_sets_loop(
	uint8_t *RESTRICT base, size_t, size_t,
	const struct QSortFnPtrs *RESTRICT, size_t
)
/*@modifies	*base@*/
;

#undef curr
/*@temp@*/
ALWAYS_INLINE uint8_t *shell_items_loop(
	uint8_t *RESTRICT curr, size_t, size_t,
	const struct QSortFnPtrs *RESTRICT, size_t, size_t
)
/*@modifies	*curr@*/
;

#undef curr
/*@temp@*/
ALWAYS_INLINE uint8_t *shell_cmp_loop(
	uint8_t *curr, uint8_t *, size_t, const struct QSortFnPtrs *RESTRICT
)
/*@modifies	*curr@*/
;

/* //////////////////////////////////////////////////////////////////////// */

/**@fn qsort_shellsort
 * @brief a simple, three-gap shellsort for small arrays
 *
 * @param base  - pointer to the beginning of the array to sort
 * @param nmemb - number of items in the array
 * @param size  - size of each array item
 * @param qsfp  - pointer to the 'compar' and 'swap' functions
**/
BUILD_HIDDEN
QSORT_SWAP_ABI
NOINLINE void
qsort_shellsort(
	uint8_t *const RESTRICT base, const size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp
)
/*@modifies	*base@*/
{
	ASSUME(nmemb <= QSORT_SHELLSORT_MAX_NMEMB);

	/* also assuming that: (ASSUME() may make things slower)
	       - (nmemb > SIZE_C(1))
	       - (size  > 0)
	       - '(nmemb * size)' will not overflow
	*/

	if ( nmemb > SHELL_GAP_B ){
		shell_sets_loop(base, nmemb, size, qsfp, SHELL_GAP_B);
	}
	if ( nmemb > SHELL_GAP_A ){
		shell_sets_loop(base, nmemb, size, qsfp, SHELL_GAP_A);
	}
	shell_sets_loop(base, nmemb, size, qsfp, SHELL_GAP_1);

	return;
}

/* ------------------------------------------------------------------------ */

/**@fn shell_sets_loop
 * @brief loop through each set within a gap
 *
 * @param base  - pointer to the beginning of the array to sort
 * @param nmemb - number of items in the array
 * @param size  - size of each array item
 * @param qsfp  - pointer to the 'compar' and 'swap' functions
 * @param gap   - number of items in the shellsort gap
**/
ALWAYS_INLINE void
shell_sets_loop(
	uint8_t *RESTRICT base, const size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp, const size_t gap
)
/*@modifies	*base@*/
{
	const size_t limit = (nmemb - gap < gap ? nmemb - gap : gap);
	/* * */
	size_t set_idx = 0;

	ASSUME(nmemb > gap);	/* helpful */

	do {	base = shell_items_loop(
			base, nmemb, size, qsfp, gap, set_idx
		);
	} while ( ++set_idx < limit );

	return;
}

/**@fn shell_items_loop
 * @brief loop through each item within a gap-set
 *
 * @return the next 'base' for shell_sets_loop()
 *
 * @param curr     - pointer to the current array item
 * @param nmemb    - number of items in the array
 * @param size     - size of each array item
 * @param qsfp     - pointer to the 'compar' and 'swap' functions
 * @param gap      - number of items in the shellsort gap
 * @param item_idx - index of 'curr' within the array
**/
/*@temp@*/
ALWAYS_INLINE uint8_t *
shell_items_loop(
	uint8_t *RESTRICT curr, const size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp, const size_t gap,
	size_t item_idx
)
/*@modifies	*curr@*/
{
	uint8_t *const idx1_p = ITEM_PTR_NEXT(curr, size);

	/* max 'nmemb' is very small, so the increment cannot overflow */
	while ( (item_idx += gap) < nmemb ){
		curr = shell_cmp_loop(curr, idx1_p, gap * size, qsfp);
	}
	return idx1_p;
}

/**@fn shell_cmp_loop
 * @brief compare/insertion-sort the current item within its gap-set
 *
 * @return the next 'curr' for shell_items_loop()
 *
 * @param curr     - pointer to the current array item
 * @param idx1_p   - pointer to the first item in the next gap-set
 * @param gap_size - number of bytes in the shellsort gap
 * @param qsfp     - pointer to the 'compar' and 'swap' functions
**/
/*@temp@*/
ALWAYS_INLINE uint8_t *
shell_cmp_loop(
	uint8_t *curr, uint8_t *const idx1_p, const size_t gap_size,
	const struct QSortFnPtrs *RESTRICT const qsfp
)
/*@modifies	*curr@*/
{
	uint8_t *const retval = ITEM_PTR_NEXT(curr, gap_size);
	/* * */
	uint8_t *next = retval;

	PRAGMA_UNROLL(3u)
	while ( QSFP_COMPAR(curr, next) > 0 ){
		QSFP_SWAP(curr, next);
		if ( (uintptr_t) curr >= (uintptr_t) idx1_p ){
			next = curr;
			curr = ITEM_PTR_PREV(curr, gap_size);
		}
		else { break; }
	}
	return retval;
}

/* EOF //////////////////////////////////////////////////////////////////// */
