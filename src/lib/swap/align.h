#ifndef H_QSORT_SWAP_ALIGN_H
#define H_QSORT_SWAP_ALIGN_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap/align.h                                                       //
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

/* options:
#define QSORT_ARCH_ALIGN_4_MATTERS
#define QSORT_ARCH_ALIGN_8_MATTERS
#define QSORT_ARCH_ALIGN_16_MATTERS

#define QSORT_ARCH_UNALIGNED_2_OK
#define QSORT_ARCH_UNALIGNED_4_OK
#define QSORT_ARCH_UNALIGNED_8_OK
*/

/* ------------------------------------------------------------------------ */

/* arm */
#if defined(__aarch__) || defined(__aarch64__)

#define QSORT_ARCH_UNALIGNED_2_OK
#define QSORT_ARCH_UNALIGNED_4_OK

#ifdef __aarch64__
#define QSORT_ARCH_UNALIGNED_8_OK
#endif	/* __aarch64__ */

/* ------------------------------------------------------------------------ */

/* ppc */
#elif defined(__powerpc__) || defined(__powerpc64__)

#define QSORT_ARCH_UNALIGNED_2_OK
#define QSORT_ARCH_UNALIGNED_4_OK

#ifdef __powerpc64__
#define QSORT_ARCH_UNALIGNED_8_OK
#else
#define QSORT_ARCH_ALIGN_8_MATTERS	/* double-floats */
#endif	/* __powerpc64__ */

#if defined(__ALTIVEC__) && !defined(__VSX__)
#define QSORT_ARCH_ALIGN_16_MATTERS
#endif /* __ALTIVEC__ */

/* ------------------------------------------------------------------------ */

/* x86 */
#elif defined(__i386__) || defined(__x86_64__)

#define QSORT_ARCH_UNALIGNED_2_OK
#define QSORT_ARCH_UNALIGNED_4_OK

#ifdef __x86_64__
#define QSORT_ARCH_UNALIGNED_8_OK
#endif	/* __x86_64__ */

/* ------------------------------------------------------------------------ */

#endif	/* arch-type */

/* //////////////////////////////////////////////////////////////////////// */

#ifdef __GNUC__

#define X_BUILTIN_GNUC_ASSUME_ALIGNED	__builtin_assume_aligned

#else	/* ! defined(__GNUC__) */

#define X_BUILTIN_GNUC_ASSUME_ALIGNED	nil

#endif	/* __GNUC__ */

/* ======================================================================== */

#if X_HAS_BUILTIN_GNUC(X_BUILTIN_GNUC_ASSUME_ALIGNED)
#define ASSUME_ALIGNED(x_ptr, x_align)	\
	X_BUILTIN_GNUC_ASSUME_ALIGNED((x_ptr), (x_align))
#else
#define ASSUME_ALIGNED(x_ptr, x_align)	(x_ptr)
#endif	/* ASSUME_ALIGNED */

/* //////////////////////////////////////////////////////////////////////// */

#define SWAP_X_BODY(x_n, x_align) \
	uint8_t *const RESTRICT a_x = ASSUME_ALIGNED(a, (x_align)); \
	uint8_t *const RESTRICT b_x = ASSUME_ALIGNED(b, (x_align)); \
	/* * */ \
	uint8_t t_a, t_b; \
	unsigned int i; \
	\
	for ( i = 0; i < (x_n); ++i ){ \
		t_a    = a_x[i]; \
		t_b    = b_x[i]; \
		\
		b_x[i] = t_a; \
		a_x[i] = t_b; \
	} \
	return;

#define SWAP_X_BODY_STDINT(x_n, x_align, x_type) \
	x_type *const RESTRICT a_x = ASSUME_ALIGNED(a, (x_align)); \
	x_type *const RESTRICT b_x = ASSUME_ALIGNED(b, (x_align)); \
	/* * */ \
	x_type t_a, t_b; \
	unsigned int i; \
	\
	for ( i = 0; i < (x_n) / sizeof(x_type); ++i ){ \
		t_a    = a_x[i]; \
		t_b    = b_x[i]; \
		\
		b_x[i] = t_a; \
		a_x[i] = t_b; \
	} \
	return;

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_ALIGN_H */
