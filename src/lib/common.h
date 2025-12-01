#ifndef H_QSORT_COMMON_H
#define H_QSORT_COMMON_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/common.h                                                           //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <limits.h>
#include <stdint.h>

/* ======================================================================== */

#if CHAR_BIT != 8u
#error "CHAR_BIT"
#endif	/* CHAR_BIT */

/* //////////////////////////////////////////////////////////////////////// */

#if SIZE_MAX == UINT16_MAX
#define SIZE_BITS	16u
#define SIZE_C(x_x)	UINT16_C(x_x)

#elif SIZE_MAX == UINT32_MAX
#define SIZE_BITS	32u
#define SIZE_C(x_x)	UINT32_C(x_x)

#elif SIZE_MAX == UINT64_MAX
#define SIZE_BITS	64u
#define SIZE_C(x_x)	UINT64_C(x_x)

#else
#error "SIZE_MAX"
#endif	/* SIZE_MAX */

/* //////////////////////////////////////////////////////////////////////// */

#ifdef __GNUC__

#ifdef __has_attribute
#define X_HAS_ATTRIBUTE_GNUC(x)		__has_attribute(x)
#else
#define X_HAS_ATTRIBUTE_GNUC(x)		0
#endif	/* __has_attribute */

#define X_ATTRIBUTE_GNUC_ALWAYS_INLINE	always_inline
#define X_ATTRIBUTE_GNUC_NOINLINE	noinline
#define X_ATTRIBUTE_GNUC_FLATTEN	flatten
#define X_ATTRIBUTE_GNUC_CONST		const
#define X_ATTRIBUTE_GNUC_PURE		pure
#define X_ATTRIBUTE_GNUC_VISIBILITY	visibility
#define X_ATTRIBUTE_GNUC_UNUSED		unused

#define X_ATTRIBUTE_GNUC_NAKED		naked
#define X_ATTRIBUTE_GNUC_SYSV_ABI	sysv_abi
#define X_ATTRIBUTE_GNUC_REGPARM_ABI	regparm

#else	/* ! defined(__GNUC__) */

#define X_HAS_ATTRIBUTE_GNUC(x)		0

#define X_ATTRIBUTE_GNUC_ALWAYS_INLINE	nil
#define X_ATTRIBUTE_GNUC_NOINLINE	nil
#define X_ATTRIBUTE_GNUC_FLATTEN	nil
#define X_ATTRIBUTE_GNUC_CONST		nil
#define X_ATTRIBUTE_GNUC_PURE		nil
#define X_ATTRIBUTE_GNUC_VISIBILITY	nil
#define X_ATTRIBUTE_GNUC_UNUSED		nil

#define X_ATTRIBUTE_GNUC_NAKED		nil
#define X_ATTRIBUTE_GNUC_SYSV_ABI	nil
#define X_ATTRIBUTE_GNUC_REGPARM_ABI	nil

#endif	/* __GNUC__ */

/* ======================================================================== */

#if __STDC_VERSION__ >= 199901L
#define INLINE		/*@unused@*/ static inline
#elif defined(__GNUC__)
#define INLINE		/*@unused@*/ static __inline__
#else
#define INLINE		/*@unused@*/ static
#endif	/* INLINE */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_ALWAYS_INLINE)
#define ALWAYS_INLINE	INLINE __attribute__((X_ATTRIBUTE_GNUC_ALWAYS_INLINE))
#else
#define ALWAYS_INLINE	INLINE
#endif	/* ALWAYS_INLINE */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_NOINLINE)
#define NOINLINE	__attribute__((X_ATTRIBUTE_GNUC_NOINLINE))
#else
#define NOINLINE
#endif	/* NOINLINE */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_FLATTEN)
#define FLATTEN		__attribute__((X_ATTRIBUTE_GNUC_FLATTEN))
#else
#define FLATTEN
#endif	/* FLATTEN */

/* ------------------------------------------------------------------------ */

#if __STDC_VERSION__ >= 201112L
#define THREAD_LOCAL	_Thread_local
#elif defined(__GNUC__)
#define THREAD_LOCAL	__thread__
#else
#ifdef S_SPLINT_S
#define THREAD_LOCAL
#else
#error "THREAD_LOCAL; compile with '-std=c11'"
#endif	/* S_SPLINT_S */
#endif	/* THREAD_LOCAL */

#if __STDC_VERSION__ >= 199901L
#define RESTRICT	restrict
#elif defined(__GNUC__)
#define RESTRICT	__restrict__
#else
#define RESTRICT
#endif	/* RESTRICT */

/* ------------------------------------------------------------------------ */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_CONST)
#define CONST		__attribute__((X_ATTRIBUTE_GNUC_CONST))
#else
#define CONST
#endif	/* CONST */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_PURE)
#define PURE		__attribute__((X_ATTRIBUTE_GNUC_PURE))
#else
#define PURE
#endif	/* PURE */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_VISIBILITY)
#define X_HIDDEN	__attribute__((X_ATTRIBUTE_GNUC_VISIBILITY("hidden")))
#else
#define X_HIDDEN
#endif	/* X_HIDDEN */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_UNUSED)
#define UNUSED	/*@unused@*/ __attribute__((X_ATTRIBUTE_GNUC_UNUSED))
#else
#define UNUSED	/*@unused@*/
#endif	/* UNUSED */

/* ======================================================================== */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_NAKED)
#define NAKED		__attribute__((X_ATTRIBUTE_GNUC_NAKED))
#define HAS_ATTRIBUTE_NAKED
#else
#define NAKED
#endif	/* NAKED */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_SYSV_ABI)
#define X_SYSV_ABI	__attribute__((X_ATTRIBUTE_GNUC_SYSV_ABI))
#define HAS_ATTRIBUTE_SYSV_ABI
#endif	/* X_SYSV_ABI */

#if X_HAS_ATTRIBUTE_GNUC(X_ATTRIBUTE_GNUC_REGPARM_ABI)
#define X_REGPARM_ABI(x_num)	\
	__attribute__((X_ATTRIBUTE_GNUC_REGPARM_ABI(x_num)))
#define HAS_ATTRIBUTE_REGPARM_ABI
#endif	/* X_REGPARM_ABI */

/* ------------------------------------------------------------------------ */

#if defined(__i386__) && defined(HAS_ATTRIBUTE_REGPARM_ABI)
#define QSORT_SWAP_ABI		X_REGPARM_ABI(3u)

#elif !defined(QSORT_OPT_NO_ASM) \
 && (defined(__x86_64__) && defined(HAS_ATTRIBUTE_SYSV_ABI))
#define QSORT_SWAP_ABI		X_SYSV_ABI

#else
#define QSORT_SWAP_ABI

#endif	/* QSORT_SWAP_ABI*/

/* //////////////////////////////////////////////////////////////////////// */

#ifdef __GNUC__

#ifdef __has_builtin
#define X_HAS_BUILTIN_GNUC(x)		__has_builtin(x)
#else
#define X_HAS_BUILTIN_GNUC(x)		0
#endif	/* __has_builtin */

#define X_BUILTIN_GNUC_ASSUME		__builtin_assume
#define X_BUILTIN_GNUC_EXPECT		__builtin_expect

#else	/* ! defined(__GNUC__) */

#define X_HAS_BUILTIN_GNUC(x)		0

#define X_BUILTIN_GNUC_ASSUME		nil
#define X_BUILTIN_GNUC_EXPECT		nil

#endif	/* __GNUC__ */

/* ======================================================================== */

#if X_HAS_BUILTIN_GNUC(X_BUILTIN_GNUC_ASSUME)
#define ASSUME(x_cond)		X_BUILTIN_GNUC_ASSUME(x_cond)
#else
#define ASSUME(x_cond)
#endif	/* ASSUME */

#if X_HAS_BUILTIN_GNUC(X_BUILTIN_GNUC_EXPECT)
#define LIKELY(x_cond)		(X_BUILTIN_GNUC_EXPECT((x_cond), 0==0))
#define UNLIKELY(x_cond)	(X_BUILTIN_GNUC_EXPECT((x_cond), 0!=0))
#else
#define LIKELY(x_cond)		(x_cond)
#define UNLIKELY(x_cond)	(x_cond)
#endif	/* (UN)LIKELY */

/* //////////////////////////////////////////////////////////////////////// */

#ifdef C_QSORT_BUILD_C
#define BUILD_HIDDEN		static
#define BUILD_EXTERN		/*@external@*/ /*@unused@*/
#else
#define BUILD_HIDDEN		X_HIDDEN
#define BUILD_EXTERN		extern /*@external@*/ /*@unused@*/
#endif	/* C_QSORT_BUILD_C */

#define BUILD_EXPORT		/*@unused@*/

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_COMMON_H */
