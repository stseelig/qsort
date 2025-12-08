/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/qsort_r.c                                                          //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <stddef.h>

#include "./common.h"
#include "./qsort.h"
#include "./swap.h"

/* //////////////////////////////////////////////////////////////////////// */

/**@fn qsort_r
 * @brief a more-thread-safe qsort(3); ($ man 3 qsort_r)
 *
 * @param base   - pointer to the beginning of the array to sort
 * @param nmemb  - number of items in the array
 * @param size   - size of each array item
 * @param compar - comparison function
 * @param arg    - third parameter for the comparison function
**/
BUILD_EXPORT
void
qsort_r(
	void *const base, const size_t nmemb, const size_t size,
	int (*const compar)(const void *, const void *, void *),
	/*@null@*/ void *const arg
)
/*@globals	gt_swap_N_size@*/
/*@modifies	*base,
		gt_swap_N_size
@*/
{
	size_t size_saved = 0;
	/* * */
	swap_fnptr swap;
	struct QSortFnPtrs qsfp;

	/* assuming that: (ASSUME() may make things slower)
	       - '(nmemb * size)' will not overflow
	*/

	if ( (nmemb < SIZE_C(2)) || (size == 0) ){
		return;
	}

	swap = swap_get((uintptr_t) base, size);
	if UNLIKELY ( swap == swap_Na1 ){
		/* the global needs to be saved/restored in case:
			- 'compar' calls qsort(3) for some reason
			- in a signal handler (qsort(3) is not guaranteed
		     AS-Safe per POSIX, but whatever)
		*/
		size_saved     = gt_swap_N_size;
		gt_swap_N_size = size;
	}

	qsfp.compar.fn	= compar;
	qsfp.compar.arg	= arg;
	qsfp.swap	= swap;

	if ( nmemb <= QSORT_SHELLSORT_MAX_NMEMB ){
		qsort_shellsort(base, nmemb, size, &qsfp);
	}
	else {	qsort_quicksort(base, nmemb, size, &qsfp); }

	if UNLIKELY ( size_saved != 0 ){
		gt_swap_N_size = size_saved;
	}
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
