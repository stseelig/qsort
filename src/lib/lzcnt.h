#ifndef H_QSORT_LZCNT_H
#define H_QSORT_LZCNT_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/lzcnt.h                                                            //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <limits.h>
#include <stdint.h>

#include "./common.h"

/* //////////////////////////////////////////////////////////////////////// */

#ifdef __GNUC__

#define X_BUILTIN_GNUC_CLZ		__builtin_clz
#define X_BUILTIN_GNUC_CLZL		__builtin_clzl
#define X_BUILTIN_GNUC_CLZLL		__builtin_clzll

#else	/* ! defined(__GNUC__) */

#define X_BUILTIN_GNUC_CLZ		nil
#define X_BUILTIN_GNUC_CLZL		nil
#define X_BUILTIN_GNUC_CLZLL		nil

#endif	/* __GNUC__ */

/* ======================================================================== */

#if X_HAS_BUILTIN_GNUC(X_BUILTIN_GNUC_CLZ)
#define X_CLZ(x_x)	X_BUILTIN_GNUC_CLZ(x_x)
#endif	/* X_CLZ */

#if X_HAS_BUILTIN_GNUC(X_BUILTIN_GNUC_CLZL)
#define X_CLZL(x_x)	X_BUILTIN_GNUC_CLZL(x_x)
#endif	/* X_CLZL */

#if X_HAS_BUILTIN_GNUC(X_BUILTIN_GNUC_CLZLL)
#define X_CLZLL(x_x)	X_BUILTIN_GNUC_CLZLL(x_x)
#endif	/* X_CLZLL */

/* ------------------------------------------------------------------------ */

#if (UINT16_MAX == UINT_MAX) && defined(X_CLZ)
#define X_CLZ16(x_x)	X_CLZ(x_x)
#elif (UINT16_MAX == ULONG_MAX) && defined(X_CLZL)
#define X_CLZ16(x_x)	X_CLZL(x_x)
#elif (UINT16_MAX == ULLONG_MAX) && defined(X_CLZLL)
#define X_CLZ16(x_x)	X_CLZLL(x_x)
#endif	/* X_CLZ16 */

#if (UINT32_MAX == UINT_MAX) && defined(X_CLZ)
#define X_CLZ32(x_x)	X_CLZ(x_x)
#elif (UINT32_MAX == ULONG_MAX) && defined(X_CLZL)
#define X_CLZ32(x_x)	X_CLZL(x_x)
#elif (UINT32_MAX == ULLONG_MAX) && defined(X_CLZLL)
#define X_CLZ32(x_x)	X_CLZLL(x_x)
#endif	/* X_CLZ32 */

#if (UINT64_MAX == UINT_MAX) && defined(X_CLZ)
#define X_CLZ64(x_x)	X_CLZ(x_x)
#elif (UINT64_MAX == ULONG_MAX) && defined(X_CLZL)
#define X_CLZ64(x_x)	X_CLZL(x_x)
#elif (UINT64_MAX == ULLONG_MAX) && defined(X_CLZLL)
#define X_CLZ64(x_x)	X_CLZLL(x_x)
#endif	/* X_CLZ64 */

/* ------------------------------------------------------------------------ */

#ifdef UINT16_MAX

#if defined(X_CLZ16)
#define lzcnt_u16(x_x)	X_CLZ16(x_x)

#elif defined(X_CLZ32)
#define lzcnt_u16(x_x) 	X_CLZ32( \
	(uint32_t) (((uint32_t) (x_x)) << 16u) \
)

#elif defined(X_CLZ64)
#define lzcnt_u16(x_x)	X_CLZ64( \
	(uint64_t) (((uint64_t) (x_x)) << 48u) \
)

#else
CONST
INLINE unsigned int
lzcnt_u16(uint16_t x)
/*@*/
{
	unsigned int r = 0;

	if ( (x & UINT16_C(0xFF00)) != 0 ){ r |= 8u, x >>= 8u; }
	if ( (x & UINT16_C(0x00F0)) != 0 ){ r |= 4u, x >>= 4u; }
	if ( (x & UINT16_C(0x000C)) != 0 ){ r |= 2u, x >>= 2u; }
	if ( (x & UINT16_C(0x0002)) != 0 ){ r |= 1u, x >>= 1u; }

	return 15u - r;
}

#endif	/* lzcnt_u16 */

#endif	/* UINT16_MAX */

/* ------------------------------------------------------------------------ */

#ifdef UINT32_MAX

#if defined(X_CLZ32)
#define lzcnt_u32(x_x)	X_CLZ32(x_x)

#elif defined(X_CLZ64)
#define lzcnt_u32(x_x)	X_CLZ64( \
	(uint64_t) (((uint64_t) (x_x)) << 32u) \
)

#else
CONST
INLINE unsigned int
lzcnt_u32(uint32_t x)
/*@*/
{
	unsigned int r = 0;

	if ( (x & UINT32_C(0xFFFF0000)) != 0 ){ r |= 16u, x >>= 16u; }
	if ( (x & UINT32_C(0x0000FF00)) != 0 ){ r |=  8u, x >>=  8u; }
	if ( (x & UINT32_C(0x000000F0)) != 0 ){ r |=  4u, x >>=  4u; }
	if ( (x & UINT32_C(0x0000000C)) != 0 ){ r |=  2u, x >>=  2u; }
	if ( (x & UINT32_C(0x00000002)) != 0 ){ r |=  1u, x >>=  1u; }

	return 31u - r;
}

#endif	/* lzcnt_u32 */

#endif	/* UINT32_MAX */

/* ------------------------------------------------------------------------ */

#ifdef UINT64_MAX

#if defined(X_CLZ64)
#define lzcnt_u64(x_x)	X_CLZ64(x_x)

#else
CONST
INLINE unsigned int
lzcnt_u64(uint64_t x)
/*@*/
{
	unsigned int r = 0;

	if ( (x & UINT64_C(0xFFFFFFFF00000000)) != 0 ){ r |= 32u, x >>= 32u; }
	if ( (x & UINT64_C(0x00000000FFFF0000)) != 0 ){ r |= 16u, x >>= 16u; }
	if ( (x & UINT64_C(0x000000000000FF00)) != 0 ){ r |=  8u, x >>=  8u; }
	if ( (x & UINT64_C(0x00000000000000F0)) != 0 ){ r |=  4u, x >>=  4u; }
	if ( (x & UINT64_C(0x000000000000000C)) != 0 ){ r |=  2u, x >>=  2u; }
	if ( (x & UINT64_C(0x0000000000000002)) != 0 ){ r |=  1u, x >>=  1u; }

	return 63u - r;
}

#endif	/* lzcnt_u64 */

#endif	/* UINT64_MAX */

/* ------------------------------------------------------------------------ */

#if SIZE_MAX == UINT16_MAX
#define lzcnt_usize(x_x)	lzcnt_u16(x_x)
#elif SIZE_MAX == UINT32_MAX
#define lzcnt_usize(x_x)	lzcnt_u32(x_x)
#elif SIZE_MAX == UINT64_MAX
#define lzcnt_usize(x_x)	lzcnt_u64(x_x)
#else
#error "SIZE_MAX"
#endif	/* lzcnt_usize */

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_LZCNT_H */
