#ifndef H_QSORT_SWAP_SWAP_A16__C_H
#define H_QSORT_SWAP_SWAP_A16__C_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap/swap_a16._C.h                                                 //
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

#include "./align.h"

/* //////////////////////////////////////////////////////////////////////// */

QSORT_SWAP_ABI
static void
swap_16a16(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(UINT64_MAX)
	SWAP_X_BODY_STDINT(16u, 16u, uint64_t)
#elif defined(UINT32_MAX)
	SWAP_X_BODY_STDINT(16u, 16u, uint32_t)
#else
	SWAP_X_BODY(16u, 16u);
#endif
}

QSORT_SWAP_ABI
static void
swap_32a16(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(UINT64_MAX)
	SWAP_X_BODY_STDINT(32u, 16u, uint64_t)
#elif defined(UINT32_MAX)
	SWAP_X_BODY_STDINT(32u, 16u, uint32_t)
#else
	SWAP_X_BODY(32u, 16u);
#endif
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_SWAP_A16__C_H */
