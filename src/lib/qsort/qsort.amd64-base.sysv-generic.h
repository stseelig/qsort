#ifndef H_QSORT_QSORT_QSORT_AMD64_BASE_SYSV_GENERIC_H
#define H_QSORT_QSORT_QSORT_AMD64_BASE_SYSV_GENERIC_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/qsort/qsort.amd64-base.sysv-generic.h                              //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <stddef.h>
#include <stdint.h>

#include "../common.h"

/* //////////////////////////////////////////////////////////////////////// */

BUILD_EXPORT
NAKED
void
qsort(
	UNUSED void *const base, UNUSED const size_t nmemb,
	UNUSED const size_t size,
	UNUSED int (*const compar)(const void *, const void *)
)
/*@modifies	*base@*/
{
	__asm__ __volatile__ __inline__ (
		"jmp	qsort_r			\n"
	);
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_QSORT_QSORT_AMD64_BASE_SYSV_GENERIC_H */
