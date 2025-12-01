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
ALWAYS_INLINE void shell_items_loop(
	uintptr_t, size_t, size_t, const struct QSortFnPtrs *RESTRICT,
	size_t , uint8_t *curr, size_t
)
/*@modifies	*curr@*/
;

#undef curr
#undef next
ALWAYS_INLINE void shell_cmp_loop(
	uint8_t *curr, uint8_t *next, uintptr_t, size_t,
	const struct QSortFnPtrs *RESTRICT
)
/*@modifies	*curr,
		*next
@*/
;

/* //////////////////////////////////////////////////////////////////////// */

/* shellsort */
BUILD_HIDDEN
QSORT_SWAP_ABI
NOINLINE void
qsort_shellsort(
	uint8_t *const RESTRICT base, const size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp
)
/*@modifies	*base@*/
{
	/* assuming that: (ASSUME() may make things slower)
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

/* loop through each set within a gap */
ALWAYS_INLINE void
shell_sets_loop(
	uint8_t *RESTRICT base, const size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp, const size_t gap
)
/*@modifies	*base@*/
{
	const size_t gap_size = gap * size;
	const size_t limit    = (nmemb - gap < gap ? nmemb - gap : gap);
	/* * */
	uint8_t *curr;
	size_t set_idx = 0;

	ASSUME(nmemb > gap);	/* helpful */

	do {	curr = base;
		base = &base[size];	/* base is now the index-1 address */
		shell_items_loop(
			(uintptr_t) base, nmemb, gap_size, qsfp,
			gap, curr, set_idx
		);
	} while ( ++set_idx < limit );

	return;
}

/* loop through each item within a set */
ALWAYS_INLINE void
shell_items_loop(
	const uintptr_t idx1_p, const size_t nmemb, const size_t gap_size,
	const struct QSortFnPtrs *const RESTRICT qsfp, const size_t gap,
	uint8_t *curr, size_t item_idx
)
/*@modifies	*curr@*/
{
	const size_t limit = nmemb - gap;
	/* * */
	uint8_t *next;

	for(;;) {
		next = &curr[gap_size];
		shell_cmp_loop(curr, next, idx1_p, gap_size, qsfp);
		if ( (item_idx += gap) < limit ){
			curr = next;
		}
		else {	break; }
	}
	return;
}

/* compare/insertion-sort the current item within its set */
ALWAYS_INLINE void
shell_cmp_loop(
	uint8_t *curr, uint8_t *next, const uintptr_t idx1_p,
	const size_t gap_size, const struct QSortFnPtrs *RESTRICT const qsfp
)
/*@modifies	*curr,
		*next
@*/
{
	#pragma unroll(3u)
	while ( QSFP_COMPAR(curr, next) > 0 ){
		QSFP_SWAP(curr, next, size);
		if ( idx1_p <= (uintptr_t) curr ){
			next = curr;
			curr = (uint8_t *) (((uintptr_t) curr) - gap_size);
		}
		else { break; }
	}
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
