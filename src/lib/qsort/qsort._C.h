#ifndef H_QSORT_QSORT_QSORT__C_H
#define H_QSORT_QSORT_QSORT__C_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/qsort/qsort._C.h                                                   //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <stddef.h>
#include <stdint.h>

#include "../qsort.h"

/* //////////////////////////////////////////////////////////////////////// */

struct QSortRStub {
	int (*compar)(const void *, const void *);
};

/* //////////////////////////////////////////////////////////////////////// */

static int qsort_compar_stub(const void *, const void *, void *) /*@*/;

/* //////////////////////////////////////////////////////////////////////// */

/* $ man 3 qsort */
BUILD_EXPORT
void
qsort(
	void *const base, const size_t nmemb, const size_t size,
	int (*const compar)(const void *, const void *)
)
/*@modifies	*base@*/
{
	/* using a struct gets around ISO-C function-pointer UB */
	struct QSortRStub qsrs;

	qsrs.compar = compar;	/* -Wpedantic */

	qsort_r(base, nmemb, size, qsort_compar_stub, (void *) &qsrs);
	return;
}

/* ------------------------------------------------------------------------ */

static int
qsort_compar_stub(const void *const a, const void *const b, void *const arg)
/*@*/
{
	const struct QSortRStub qsrs = *((struct QSortRStub *) arg);

	return qsrs.compar(a, b);
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_QSORT_QSORT__C_H */
