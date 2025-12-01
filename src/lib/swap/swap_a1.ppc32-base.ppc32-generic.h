#ifndef H_QSORT_SWAP_SWAP_A1_PPC32_BASE_PPC32_GENERIC_H
#define H_QSORT_SWAP_SWAP_A1_PPC32_BASE_PPC32_GENERIC_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap/swap_a1.ppc32-base.ppc32-generic.h                            //
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
swap_1a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lbz	%%r5, 0(%[a])		\n"
		"lbz	%%r6, 0(%[b])		\n"

		"stb	%%r5, 0(%[b])		\n"
		"stb	%%r6, 0(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_2a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lhz	%%r5, 0(%[a])		\n"
		"lhz	%%r6, 0(%[b])		\n"

		"sth	%%r5, 0(%[b])		\n"
		"sth	%%r6, 0(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_3a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lhz	%%r5, 0(%[a])		\n"
		"lbz	%%r7, 2(%[a])		\n"
		"lhz	%%r6, 0(%[b])		\n"
		"lbz	%%r8, 2(%[b])		\n"

		"sth	%%r5, 0(%[b])		\n"
		"stb	%%r7, 2(%[b])		\n"
		"sth	%%r6, 0(%[a])		\n"
		"stb	%%r8, 2(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_4a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	%%r5, 0(%[a])		\n"
		"lwz	%%r6, 0(%[b])		\n"

		"stw	%%r5, 0(%[b])		\n"
		"stw	%%r6, 0(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_5a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	%%r5, 0(%[a])		\n"
		"lbz	%%r7, 4(%[a])		\n"
		"lwz	%%r6, 0(%[b])		\n"
		"lbz	%%r8, 4(%[b])		\n"

		"stw	%%r5, 0(%[b])		\n"
		"stb	%%r7, 4(%[b])		\n"
		"stw	%%r6, 0(%[a])		\n"
		"stb	%%r8, 4(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_6a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	%%r5, 0(%[a])		\n"
		"lhz	%%r7, 4(%[a])		\n"
		"lwz	%%r6, 0(%[b])		\n"
		"lhz	%%r8, 4(%[b])		\n"

		"stw	%%r5, 0(%[b])		\n"
		"sth	%%r7, 4(%[b])		\n"
		"stw	%%r6, 0(%[a])		\n"
		"sth	%%r8, 4(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_7a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	%%r5, 0(%[a])		\n"
		"lwz	%%r7, 3(%[a])		\n"
		"lwz	%%r6, 0(%[b])		\n"
		"lwz	%%r8, 3(%[b])		\n"

		"stw	%%r5, 0(%[b])		\n"
		"stw	%%r7, 3(%[b])		\n"
		"stw	%%r6, 0(%[a])		\n"
		"stw	%%r8, 3(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_8a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	%%r5, 0(%[a])		\n"
		"lwz	%%r7, 4(%[a])		\n"
		"lwz	%%r6, 0(%[b])		\n"
		"lwz	%%r8, 4(%[b])		\n"

		"stw	%%r5, 0(%[b])		\n"
		"stw	%%r7, 4(%[b])		\n"
		"stw	%%r6, 0(%[a])		\n"
		"stw	%%r8, 4(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_9a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5, 0(%[a])		\n"
		"lwz	 %%r7, 4(%[a])		\n"
		"lbz	 %%r9, 8(%[a])		\n"
		"lwz	 %%r6, 0(%[b])		\n"
		"lwz	 %%r8, 4(%[b])		\n"
		"lbz	%%r10, 8(%[b])		\n"

		"stw	 %%r5, 0(%[b])		\n"
		"stw	 %%r7, 4(%[b])		\n"
		"stb	 %%r9, 8(%[b])		\n"
		"stw	 %%r6, 0(%[a])		\n"
		"stw	 %%r8, 4(%[a])		\n"
		"stb	%%r10, 8(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "r9", "r10"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_10a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5, 0(%[a])		\n"
		"lwz	 %%r7, 4(%[a])		\n"
		"lhz	 %%r9, 8(%[a])		\n"
		"lwz	 %%r6, 0(%[b])		\n"
		"lwz	 %%r8, 4(%[b])		\n"
		"lhz	%%r10, 8(%[b])		\n"

		"stw	 %%r5, 0(%[b])		\n"
		"stw	 %%r7, 4(%[b])		\n"
		"sth	 %%r9, 8(%[b])		\n"
		"stw	 %%r6, 0(%[a])		\n"
		"stw	 %%r8, 4(%[a])		\n"
		"sth	%%r10, 8(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_11a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5, 0(%[a])		\n"
		"lwz	 %%r7, 4(%[a])		\n"
		"lwz	 %%r9, 7(%[a])		\n"
		"lwz	 %%r6, 0(%[b])		\n"
		"lwz	 %%r8, 4(%[b])		\n"
		"lwz	%%r10, 7(%[b])		\n"

		"stw	 %%r5, 0(%[b])		\n"
		"stw	 %%r7, 4(%[b])		\n"
		"stw	 %%r9, 7(%[b])		\n"
		"stw	 %%r6, 0(%[a])		\n"
		"stw	 %%r8, 4(%[a])		\n"
		"stw	%%r10, 7(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_12a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5, 0(%[a])		\n"
		"lwz	 %%r7, 4(%[a])		\n"
		"lwz	 %%r9, 8(%[a])		\n"
		"lwz	 %%r6, 0(%[b])		\n"
		"lwz	 %%r8, 4(%[b])		\n"
		"lwz	%%r10, 8(%[b])		\n"

		"stw	 %%r5, 0(%[b])		\n"
		"stw	 %%r7, 4(%[b])		\n"
		"stw	 %%r9, 8(%[b])		\n"
		"stw	 %%r6, 0(%[a])		\n"
		"stw	 %%r8, 4(%[a])		\n"
		"stw	%%r10, 8(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_13a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5,  0(%[a])		\n"
		"lwz	 %%r7,  4(%[a])		\n"
		"lwz	 %%r9,  8(%[a])		\n"
		"lbz	%%r11, 12(%[a])		\n"
		"lwz	 %%r6,  0(%[b])		\n"
		"lwz	 %%r8,  4(%[b])		\n"
		"lwz	%%r10,  8(%[b])		\n"
		"lbz	%%r12, 12(%[b])		\n"

		"stw	 %%r5,  0(%[b])		\n"
		"stw	 %%r7,  4(%[b])		\n"
		"stw	 %%r9,  8(%[b])		\n"
		"stb	%%r11, 12(%[b])		\n"
		"stw	 %%r6,  0(%[a])		\n"
		"stw	 %%r8,  4(%[a])		\n"
		"stw	%%r10,  8(%[a])		\n"
		"stb	%%r12, 12(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10", "%r11",
			"%r12"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_14a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5,  0(%[a])		\n"
		"lwz	 %%r7,  4(%[a])		\n"
		"lwz	 %%r9,  8(%[a])		\n"
		"lhz	%%r11, 12(%[a])		\n"
		"lwz	 %%r6,  0(%[b])		\n"
		"lwz	 %%r8,  4(%[b])		\n"
		"lwz	%%r10,  8(%[b])		\n"
		"lhz	%%r12, 12(%[b])		\n"

		"stw	 %%r5,  0(%[b])		\n"
		"stw	 %%r7,  4(%[b])		\n"
		"stw	 %%r9,  8(%[b])		\n"
		"sth	%%r11, 12(%[b])		\n"
		"stw	 %%r6,  0(%[a])		\n"
		"stw	 %%r8,  4(%[a])		\n"
		"stw	%%r10,  8(%[a])		\n"
		"sth	%%r12, 12(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10", "%r11",
			"%r12"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_15a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5,  0(%[a])		\n"
		"lwz	 %%r7,  4(%[a])		\n"
		"lwz	 %%r9,  8(%[a])		\n"
		"lwz	%%r11, 11(%[a])		\n"
		"lwz	 %%r6,  0(%[b])		\n"
		"lwz	 %%r8,  4(%[b])		\n"
		"lwz	%%r10,  8(%[b])		\n"
		"lwz	%%r12, 11(%[b])		\n"

		"stw	 %%r5,  0(%[b])		\n"
		"stw	 %%r7,  4(%[b])		\n"
		"stw	 %%r9,  8(%[b])		\n"
		"stw	%%r11, 11(%[b])		\n"
		"stw	 %%r6,  0(%[a])		\n"
		"stw	 %%r8,  4(%[a])		\n"
		"stw	%%r10,  8(%[a])		\n"
		"stw	%%r12, 11(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10", "%r11",
			"%r12"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_16a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5,  0(%[a])		\n"
		"lwz	 %%r7,  4(%[a])		\n"
		"lwz	 %%r9,  8(%[a])		\n"
		"lwz	%%r11, 12(%[a])		\n"
		"lwz	 %%r6,  0(%[b])		\n"
		"lwz	 %%r8,  4(%[b])		\n"
		"lwz	%%r10,  8(%[b])		\n"
		"lwz	%%r12, 12(%[b])		\n"

		"stw	 %%r5,  0(%[b])		\n"
		"stw	 %%r7,  4(%[b])		\n"
		"stw	 %%r9,  8(%[b])		\n"
		"stw	%%r11, 12(%[b])		\n"
		"stw	 %%r6,  0(%[a])		\n"
		"stw	 %%r8,  4(%[a])		\n"
		"stw	%%r10,  8(%[a])		\n"
		"stw	%%r12, 12(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10", "%r11",
			"%r12"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_20a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5,  0(%[a])		\n"
		"lwz	 %%r7,  4(%[a])		\n"
		"lwz	 %%r9,  8(%[a])		\n"
		"lwz	%%r11, 12(%[a])		\n"
		"lwz	 %%r6,  0(%[b])		\n"
		"lwz	 %%r8,  4(%[b])		\n"
		"lwz	%%r10,  8(%[b])		\n"
		"lwz	%%r12, 12(%[b])		\n"

		"stw	 %%r5,  0(%[b])		\n"
		"stw	 %%r7,  4(%[b])		\n"
		"stw	 %%r9,  8(%[b])		\n"
		"stw	%%r11, 12(%[b])		\n"
		"stw	 %%r6,  0(%[a])		\n"
		"stw	 %%r8,  4(%[a])		\n"
		"stw	%%r10,  8(%[a])		\n"
		"stw	%%r12, 12(%[a])		\n"

		"lwz	 %%r5, 16(%[a])		\n"
		"lwz	 %%r6, 16(%[b])		\n"

		"stw	 %%r5, 16(%[b])		\n"
		"stw	 %%r6, 16(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10", "%r11",
			"%r12"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_24a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5,  0(%[a])		\n"
		"lwz	 %%r7,  4(%[a])		\n"
		"lwz	 %%r9,  8(%[a])		\n"
		"lwz	%%r11, 12(%[a])		\n"
		"lwz	 %%r6,  0(%[b])		\n"
		"lwz	 %%r8,  4(%[b])		\n"
		"lwz	%%r10,  8(%[b])		\n"
		"lwz	%%r12, 12(%[b])		\n"

		"stw	 %%r5,  0(%[b])		\n"
		"stw	 %%r7,  4(%[b])		\n"
		"stw	 %%r9,  8(%[b])		\n"
		"stw	%%r11, 12(%[b])		\n"
		"stw	 %%r6,  0(%[a])		\n"
		"stw	 %%r8,  4(%[a])		\n"
		"stw	%%r10,  8(%[a])		\n"
		"stw	%%r12, 12(%[a])		\n"

		"lwz	 %%r5, 16(%[a])		\n"
		"lwz	 %%r7, 20(%[a])		\n"
		"lwz	 %%r6, 16(%[b])		\n"
		"lwz	 %%r8, 20(%[b])		\n"

		"stw	 %%r5, 16(%[b])		\n"
		"stw	 %%r7, 20(%[b])		\n"
		"stw	 %%r6, 16(%[a])		\n"
		"stw	 %%r8, 20(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10", "%r11",
			"%r12"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_28a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5,  0(%[a])		\n"
		"lwz	 %%r7,  4(%[a])		\n"
		"lwz	 %%r9,  8(%[a])		\n"
		"lwz	%%r11, 12(%[a])		\n"
		"lwz	 %%r6,  0(%[b])		\n"
		"lwz	 %%r8,  4(%[b])		\n"
		"lwz	%%r10,  8(%[b])		\n"
		"lwz	%%r12, 12(%[b])		\n"

		"stw	 %%r5,  0(%[b])		\n"
		"stw	 %%r7,  4(%[b])		\n"
		"stw	 %%r9,  8(%[b])		\n"
		"stw	%%r11, 12(%[b])		\n"
		"stw	 %%r6,  0(%[a])		\n"
		"stw	 %%r8,  4(%[a])		\n"
		"stw	%%r10,  8(%[a])		\n"
		"stw	%%r12, 12(%[a])		\n"

		"lwz	 %%r5, 16(%[a])		\n"
		"lwz	 %%r7, 20(%[a])		\n"
		"lwz	 %%r9, 24(%[a])		\n"
		"lwz	 %%r6, 16(%[b])		\n"
		"lwz	 %%r8, 20(%[b])		\n"
		"lwz	%%r10, 24(%[b])		\n"

		"stw	 %%r5, 16(%[b])		\n"
		"stw	 %%r7, 20(%[b])		\n"
		"stw	 %%r9, 24(%[b])		\n"
		"stw	 %%r6, 16(%[a])		\n"
		"stw	 %%r8, 20(%[a])		\n"
		"stw	%%r10, 24(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10", "%r11",
			"%r12"
	);
	return;
}

QSORT_SWAP_ABI
static void
swap_32a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"lwz	 %%r5,  0(%[a])		\n"
		"lwz	 %%r7,  4(%[a])		\n"
		"lwz	 %%r9,  8(%[a])		\n"
		"lwz	%%r11, 12(%[a])		\n"
		"lwz	 %%r6,  0(%[b])		\n"
		"lwz	 %%r8,  4(%[b])		\n"
		"lwz	%%r10,  8(%[b])		\n"
		"lwz	%%r12, 12(%[b])		\n"

		"stw	 %%r5,  0(%[b])		\n"
		"stw	 %%r7,  4(%[b])		\n"
		"stw	 %%r9,  8(%[b])		\n"
		"stw	%%r11, 12(%[b])		\n"
		"stw	 %%r6,  0(%[a])		\n"
		"stw	 %%r8,  4(%[a])		\n"
		"stw	%%r10,  8(%[a])		\n"
		"stw	%%r12, 12(%[a])		\n"

		"lwz	 %%r5, 16(%[a])		\n"
		"lwz	 %%r7, 20(%[a])		\n"
		"lwz	 %%r9, 24(%[a])		\n"
		"lwz	%%r11, 28(%[a])		\n"
		"lwz	 %%r6, 16(%[b])		\n"
		"lwz	 %%r8, 20(%[b])		\n"
		"lwz	%%r10, 24(%[b])		\n"
		"lwz	%%r12, 28(%[b])		\n"

		"stw	 %%r5, 16(%[b])		\n"
		"stw	 %%r7, 20(%[b])		\n"
		"stw	 %%r9, 24(%[b])		\n"
		"stw	%%r11, 28(%[b])		\n"
		"stw	 %%r6, 16(%[a])		\n"
		"stw	 %%r8, 20(%[a])		\n"
		"stw	%%r10, 24(%[a])		\n"
		"stw	%%r12, 28(%[a])		\n"
		:
		:
			[a] "r" (a),	/* %r3 */
			[b] "r" (b)	/* %r4 */
		:
			"memory",
			"%r5", "%r6", "%r7", "%r8", "%r9", "%r10", "%r11",
			"%r12"
	);
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_SWAP_A1_PPC32_BASE_PPC32_GENERIC_H */
