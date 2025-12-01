#ifndef H_QSORT_SWAP_SWAP_A16_PPC32_ALTIVEC_PPC32_GENERIC_H
#define H_QSORT_SWAP_SWAP_A16_PPC32_ALTIVEC_PPC32_GENERIC_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap/swap_a16.ppc32-altivec.ppc32-generic.h                        //
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

QSORT_SWAP_ABI
static void
swap_16a16(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lvx	%%v0, 0, %[a]		\n"
		"lvx	%%v1, 0, %[b]		\n"

		"stvx	%%v1, 0, %[a]		\n"
		"stvx	%%v0, 0, %[b]		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%v0", "%v1"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_32a16(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"li	%%r5, 16		\n"

		"lvx	%%v0,    0, %[a]	\n"
		"lvx	%%v2, %%r5, %[a]	\n"
		"lvx	%%v1,    0, %[b]	\n"
		"lvx	%%v3, %%r5, %[b]	\n"

		"stvx   %%v1,    0, %[a]	\n"
		"stvx	%%v3, %%r5, %[a]	\n"
		"stvx	%%v0,    0, %[b]	\n"
		"stvx	%%v2, %%r5, %[b]	\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5",
			"%v0", "%v1", "%v2", "%v3"
	);
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_SWAP_A16_PPC32_ALTIVEC_PPC32_GENERIC_H */
