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

/* $ man 3 qsort_r */
BUILD_EXPORT
void
qsort_r(
	void *const base, const size_t nmemb, const size_t size,
	int (*const compar)(const void *, const void *, void *),
	/*@null@*/ void *const arg
)
/*@modifies	*base@*/
{
	size_t size_saved = 0;
	/* * */
	sort_fnptr sort;
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

	if ( QSORT_SHELLSORT_CHECK(nmemb, size) ){
		sort = qsort_shellsort;
	}
	else if ( QSORT_HEAPSORT_CHECK(nmemb, size) ){
		sort = qsort_heapsort;
	}
	else {	sort = qsort_quicksort; }

	sort(base, nmemb, size, &qsfp);

	if UNLIKELY ( size_saved != 0 ){
		gt_swap_N_size = size_saved;
	}
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
