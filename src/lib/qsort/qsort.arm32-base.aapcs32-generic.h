#ifndef H_QSORT_QSORT_QSORT_ARM32_BASE_AAPCS32_GENERIC_H
#define H_QSORT_QSORT_QSORT_ARM32_BASE_AAPCS32_GENERIC_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/qsort/qsort.arm32-base.aapcs32-generic.h                           //
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
		"push	{r0, lr}		\n"
		"bl	qsort_r			\n"
		"pop	{r0, pc}		\n"
	);
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_QSORT_QSORT_ARM32_BASE_AAPCS32_GENERIC_H */
