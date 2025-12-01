#ifndef H_QSORT_SWAP_SWAP_A1_AMD64_MULTI_SYSV_GENERIC_H
#define H_QSORT_SWAP_SWAP_A1_AMD64_MULTI_SYSV_GENERIC_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap/swap_a1.amd64-multi.sysv-generic.h                            //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// gcc-12 bugs:                                                             //
//     - will insert unneccessary 'vzeroupper's                             //
//     - will not recognize some registers in the __asm__ clobbers (%r8w)   //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <stddef.h>
#include <stdint.h>

#include "../common.h"

/* //////////////////////////////////////////////////////////////////////// */

#ifdef __AVX__
#define	VEX	"v"
#else
#define VEX	""
#endif	/* __AVX__ */

/* //////////////////////////////////////////////////////////////////////// */

QSORT_SWAP_ABI
static void
swap_1a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	__asm__ __volatile__ __inline__ (
		"movb	(%[a]),  %%al		\n"
		"movb	(%[b]),  %%dl		\n"

		"movb	  %%al, (%[b])		\n"
		"movb	  %%dl, (%[a])		\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx"
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
		"movw	(%[a]),  %%ax		\n"
		"movw	(%[b]),  %%dx		\n"

		"movw	  %%ax, (%[b])		\n"
		"movw	  %%dx, (%[a])		\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx"
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
		"movw	 (%[a]),   %%ax		\n"
		"movb	2(%[a]),   %%cl		\n"
		"movw	 (%[b]),   %%dx		\n"
		"movb	2(%[b]),   %%ch		\n"

		"movw	   %%ax,  (%[b])	\n"
		"movb	   %%cl, 2(%[b])	\n"
		"movw	   %%dx,  (%[a])	\n"
		"movb	   %%ch, 2(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx"
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
		"movl	(%[a]), %%eax		\n"
		"movl	(%[b]), %%edx		\n"

		"movl	 %%eax, (%[b])		\n"
		"movl	 %%edx, (%[a])		\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx"
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
		"movl	 (%[a]),  %%eax		\n"
		"movb	4(%[a]),   %%cl		\n"
		"movl	 (%[b]),  %%edx		\n"
		"movb	4(%[b]),   %%ch		\n"

		"movl	  %%eax,  (%[b])	\n"
		"movb	   %%cl, 4(%[b])	\n"
		"movl	  %%edx,  (%[a])	\n"
		"movb	   %%ch, 4(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx"
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
		"movl	 (%[a]),  %%eax		\n"
		"movw	4(%[a]),   %%cx		\n"
		"movl	 (%[b]),  %%edx		\n"
		"movw	4(%[b]),  %%r8w		\n"

		"movl	  %%eax,  (%[b])	\n"
		"movw	   %%cx, 4(%[b])	\n"
		"movl	  %%edx,  (%[a])	\n"
		"movw	  %%r8w, 4(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx", "%r8"
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
		"movl	 (%[a]),  %%eax		\n"
		"movl	3(%[a]),  %%ecx		\n"
		"movl	 (%[b]),  %%edx		\n"
		"movl	3(%[b]),  %%r8d		\n"

		"movl	  %%eax,  (%[b])	\n"
		"movl	  %%ecx, 3(%[b])	\n"
		"movl	  %%edx,  (%[a])	\n"
		"movl	  %%r8d, 3(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx", "%r8"
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
		"movq	(%[a]), %%rax		\n"
		"movq	(%[b]), %%rdx		\n"

		"movq	 %%rax, (%[b])		\n"
		"movq	 %%rdx, (%[a])		\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx"
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
		"movq	 (%[a]), %%rax		\n"
		"movb	8(%[a]),  %%cl		\n"
		"movq	 (%[b]), %%rdx		\n"
		"movb	8(%[b]),  %%ch		\n"

		"movq	 %%rax,  (%[b])		\n"
		"movb	  %%cl, 8(%[b])		\n"
		"movq	 %%rdx,  (%[a])		\n"
		"movb	  %%ch, 8(%[a])		\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx"
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
		"movq	 (%[a]),  %%rax		\n"
		"movw	8(%[a]),   %%cx		\n"
		"movq	 (%[b]),  %%rdx		\n"
		"movw	8(%[b]),  %%r8w		\n"

		"movq	  %%rax,  (%[b])	\n"
		"movw	   %%cx, 8(%[b])	\n"
		"movq	  %%rdx,  (%[a])	\n"
		"movw	  %%r8w, 8(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx", "%r8"
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
		"movq	  (%[a]),  %%rax	\n"
		"movw	 8(%[a]),  %%r8w	\n"
		"movb	10(%[a]),   %%cl	\n"
		"movq	  (%[b]),  %%rdx	\n"
		"movw	 8(%[b]),  %%r9w	\n"
		"movb	10(%[b]),   %%ch	\n"

		"movq	  %%rax,   (%[b])	\n"
		"movw	  %%r8w,  8(%[b])	\n"
		"movb	   %%cl, 10(%[b])	\n"
		"movq	  %%rdx,   (%[a])	\n"
		"movw	  %%r9w,  8(%[a])	\n"
		"movb	   %%ch, 10(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx", "%r8", "%r9"
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
		"movq	 (%[a]),  %%rax		\n"
		"movl	8(%[a]),  %%ecx		\n"
		"movq	 (%[b]),  %%rdx		\n"
		"movl	8(%[b]),  %%r8d		\n"

		"movq	  %%rax,  (%[b])	\n"
		"movl	  %%ecx, 8(%[b])	\n"
		"movq	  %%rdx,  (%[a])	\n"
		"movl	  %%r8d, 8(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx", "%r8"
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
		"movq	  (%[a]),  %%rax	\n"
		"movl	 8(%[a]),  %%r8d	\n"
		"movb	12(%[a]),   %%cl	\n"
		"movq	  (%[b]),  %%rdx	\n"
		"movl	 8(%[b]),  %%r9d	\n"
		"movb	12(%[b]),   %%ch	\n"

		"movq	  %%rax,   (%[b])	\n"
		"movl	  %%r8d,  8(%[b])	\n"
		"movb	   %%cl, 12(%[b])	\n"
		"movq	  %%rdx,   (%[a])	\n"
		"movl	  %%r9d,  8(%[a])	\n"
		"movb	   %%ch, 12(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx", "%r8", "%r9"
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
		"movq	  (%[a]),   %%rax	\n"
		"movl	 8(%[a]),   %%ecx	\n"
		"movw	12(%[a]),   %%r9w	\n"
		"movq	  (%[b]),   %%rdx	\n"
		"movl	 8(%[b]),   %%r8d	\n"
		"movw	12(%[b]),  %%r10w	\n"

		"movq	   %%rax,   (%[b])	\n"
		"movl	   %%ecx,  8(%[b])	\n"
		"movw	   %%r9w, 12(%[b])	\n"
		"movq	   %%rdx,   (%[a])	\n"
		"movl	   %%r8d,  8(%[a])	\n"
		"movw	  %%r10w, 12(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx", "%r8", "%r9", "%r10"
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
		"movq	  (%[a]),   %%rax	\n"
		"movl	 8(%[a]),   %%ecx	\n"
		"movl	11(%[a]),   %%r9d	\n"
		"movq	  (%[b]),   %%rdx	\n"
		"movl	 8(%[b]),   %%r8d	\n"
		"movl	11(%[b]),  %%r10d	\n"

		"movq	   %%rax,   (%[b])	\n"
		"movl	   %%ecx,  8(%[b])	\n"
		"movl	   %%r9d, 11(%[b])	\n"
		"movq	   %%rdx,   (%[a])	\n"
		"movl	   %%r8d,  8(%[a])	\n"
		"movl	  %%r10d, 11(%[a])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx", "%r8", "%r9", "%r10"
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
		VEX"movdqu (%[a]), %%xmm0	\n"
		VEX"movdqu (%[b]), %%xmm1	\n"

		VEX"movdqu %%xmm1,  (%[a])	\n"
		VEX"movdqu %%xmm0,  (%[b])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%xmm0", "%xmm1"
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
		VEX"movdqu  (%[a]),  %%xmm0	\n"
		VEX"movdqu  (%[b]),  %%xmm1	\n"
		"movl	  16(%[b]),   %%edx	\n"
		"movl	  16(%[a]),   %%eax	\n"

		"movl	     %%edx, 16(%[a])	\n"
		"movl	     %%eax, 16(%[b])	\n"
		VEX"movdqu  %%xmm1,   (%[a])	\n"
		VEX"movdqu  %%xmm0,   (%[b])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx",
			"%xmm0", "%xmm1"
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
		VEX"movdqu  (%[a]),  %%xmm0	\n"
		VEX"movdqu  (%[b]),  %%xmm1	\n"
		"movq	  16(%[b]),   %%rdx	\n"
		"movq	  16(%[a]),   %%rax	\n"

		"movq	     %%rdx, 16(%[a])	\n"
		"movq	     %%rax, 16(%[b])	\n"
		VEX"movdqu  %%xmm1,   (%[a])	\n"
		VEX"movdqu  %%xmm0,   (%[b])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx",
			"%xmm0", "%xmm1"
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
		VEX"movdqu  (%[a]),  %%xmm0	\n"
		VEX"movdqu  (%[b]),  %%xmm1	\n"
		"movq	  16(%[b]),   %%rdx	\n"
		"movl	  24(%[b]),   %%r8d	\n"
		"movq	  16(%[a]),   %%rax	\n"
		"movl	  24(%[a]),   %%ecx	\n"

		"movq	     %%rdx, 16(%[a])	\n"
		"movl	     %%r8d, 24(%[a])	\n"
		"movq	     %%rax, 16(%[b])	\n"
		"movl	     %%ecx, 24(%[b])	\n"
		VEX"movdqu  %%xmm1,   (%[a])	\n"
		VEX"movdqu  %%xmm0,   (%[b])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%rax", "%rdx", "%rcx", "%r8",
			"%xmm0", "%xmm1"
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
		VEX"movdqu   (%[a]),  %%xmm0	\n"
		VEX"movdqu 16(%[a]),  %%xmm2	\n"
		VEX"movdqu   (%[b]),  %%xmm1	\n"
		VEX"movdqu 16(%[b]),  %%xmm3	\n"

		VEX"movdqu   %%xmm1,   (%[a])	\n"
		VEX"movdqu   %%xmm3, 16(%[a])	\n"
		VEX"movdqu   %%xmm0,   (%[b])	\n"
		VEX"movdqu   %%xmm2, 16(%[b])	\n"
		:
		:
			[a] "R" (a),	/* %rdi */
			[b] "R" (b)	/* %rsi */
		:
			"memory",
			"%xmm0", "%xmm1", "xmm2", "xmm3"
	);
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_SWAP_A1_AMD64_MULTI_SYSV_GENERIC_H */
