#ifndef H_QSORT_SWAP_SWAP_A8_PPC32_BASE_PPC32_GENERIC_H
#define H_QSORT_SWAP_SWAP_A8_PPC32_BASE_PPC32_GENERIC_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap/swap_a8.ppc32-base.ppc32-generic.h                            //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// gcc-12 bugs:                                                             //
//     - will not recognize the float registers in the __asm__ clobbers     //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <stddef.h>
#include <stdint.h>

#include "../common.h"

/* //////////////////////////////////////////////////////////////////////// */

QSORT_SWAP_ABI
static void
swap_8a8(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lfd	%%f0, 0(%[a])		\n"
		"lfd	%%f1, 0(%[b])		\n"

		"stfd	%%f0, 0(%[b])		\n"
		"stfd	%%f1, 0(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory"
		/* gcc-12 bug
			,
			"%f0", "%f1"
		*/
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_16a8(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lfd	%%f0, 0(%[a])		\n"
		"lfd	%%f2, 8(%[a])		\n"
		"lfd	%%f1, 0(%[b])		\n"
		"lfd	%%f3, 8(%[b])		\n"

		"stfd	%%f0, 0(%[b])		\n"
		"stfd	%%f2, 8(%[b])		\n"
		"stfd	%%f1, 0(%[a])		\n"
		"stfd	%%f3, 8(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory"
		/* gcc-12 bug
			,
			"%f0", "%f1", "%f2", "%f3"
		*/
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_24a8(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lfd	%%f0,  0(%[a])		\n"
		"lfd	%%f2,  8(%[a])		\n"
		"lfd	%%f4, 16(%[a])		\n"
		"lfd	%%f1,  0(%[b])		\n"
		"lfd	%%f3,  8(%[b])		\n"
		"lfd	%%f5, 16(%[b])		\n"

		"stfd	%%f0,  0(%[b])		\n"
		"stfd	%%f2,  8(%[b])		\n"
		"stfd	%%f4, 16(%[b])		\n"
		"stfd	%%f1,  0(%[a])		\n"
		"stfd	%%f3,  8(%[a])		\n"
		"stfd	%%f5, 16(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory"
		/* gcc-12 bug
			,
			"%f0", "%f1", "%f2", "%f3", "%f4", "%f5"
		*/
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_32a8(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lfd	%%f0,  0(%[a])		\n"
		"lfd	%%f2,  8(%[a])		\n"
		"lfd	%%f4, 16(%[a])		\n"
		"lfd	%%f6, 24(%[a])		\n"
		"lfd	%%f1,  0(%[b])		\n"
		"lfd	%%f3,  8(%[b])		\n"
		"lfd	%%f5, 16(%[b])		\n"
		"lfd	%%f7, 24(%[b])		\n"

		"stfd	%%f0,  0(%[b])		\n"
		"stfd	%%f2,  8(%[b])		\n"
		"stfd	%%f4, 16(%[b])		\n"
		"stfd	%%f6, 24(%[b])		\n"
		"stfd	%%f1,  0(%[a])		\n"
		"stfd	%%f3,  8(%[a])		\n"
		"stfd	%%f5, 16(%[a])		\n"
		"stfd	%%f7, 24(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory"
		/* gcc-12 bug
			,
			"%f0", "%f1", "%f2", "%f3", "%f4", "%f5", "%f6", "%f7"
		*/
	);
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_SWAP_A8_PPC32_BASE_PPC32_GENERIC_H */
