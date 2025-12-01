#ifndef H_QSORT_QSORT_QSORT_AMD64_BASE_MSX64_GENERIC_H
#define H_QSORT_QSORT_QSORT_AMD64_BASE_MSX64_GENERIC_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/qsort/qsort.amd64-base.msx64-generic.h                             //
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
	".set FRAME_ALIGN,	 8				\n"
	".set SHADOW_SPACE,	32				\n"
	".set FRAME_SIZE,	FRAME_ALIGN + SHADOW_SPACE	\n"

		"subq	$FRAME_SIZE, %rsp	\n"
		"callq	qsort_r			\n"
		"addq	$FRAME_SIZE, %rsp	\n"
		"retq				\n"
	);
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_QSORT_QSORT_AMD64_BASE_MSX64_GENERIC_H */
