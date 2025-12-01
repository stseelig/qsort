#ifndef H_QSORT_QSORT_QSORT_X86_MULTI_CDECL_GENERIC_H
#define H_QSORT_QSORT_QSORT_X86_MULTI_CDECL_GENERIC_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/qsort/qsort.ppc.ppc-generic.h                                      //
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
#ifdef __SSE__

	__asm__ __volatile__ __inline__ (
	".set FRAME_ALIGN,	12			\n"
	".set FRAME_SIZE,	16 + FRAME_ALIGN	\n"
	".set OFFSET_P0,	FRAME_SIZE + 4		\n"

		"subl	$FRAME_SIZE, %esp	\n"
		"movups	OFFSET_P0(%esp), %xmm0	\n"
		"movups	%xmm0, (%esp)		\n"
		"calll	qsort_r			\n"
		"addl	$FRAME_SIZE, %esp	\n"
		"retl				\n"
	);

#else	/* ! defined(__SSE__) */

	__asm__ __volatile__ __inline__ (
	".set P0_BASE,		 0			\n"
	".set P0_NMEMB,		 4			\n"
	".set P0_SIZE,		 8			\n"
	".set P0_COMPAR,	12			\n"
	".set FRAME_ALIGN,	12			\n"
	".set FRAME_SIZE,	16 + FRAME_ALIGN	\n"
	".set OFFSET_P0,	FRAME_ALIGN + 4		\n"
	".set P1_BASE_p4,	OFFSET_P0 + P0_BASE + 4	\n"
	".set P1_NMEMB,		OFFSET_P0 + P0_NMEMB	\n"
	".set P1_SIZE,		OFFSET_P0 + P0_SIZE	\n"
	".set P1_COMPAR,	OFFSET_P0 + P0_COMPAR	\n"

		"subl	$FRAME_ALIGN, %esp	\n"
		"movl	P1_COMPAR(%esp), %eax	\n"
		"movl	P1_SIZE(%esp), %edx	\n"
		"movl	P1_NMEMB(%esp), %ecx	\n"
		"pushl	%eax			\n"
		"movl	P1_BASE_p4(%esp), %eax	\n"
		"pushl	%edx			\n"
		"pushl	%ecx			\n"
		"pushl	%eax			\n"
		"calll	qsort_r			\n"
		"addl	$FRAME_SIZE, %esp	\n"
		"retl				\n"
	);

#endif	/* __SSE__ */
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_QSORT_QSORT_X86_MULTI_CDECL_GENERIC_H */
