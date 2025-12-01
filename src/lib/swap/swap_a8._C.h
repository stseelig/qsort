#ifndef H_QSORT_SWAP_SWAP_A8__C_H
#define H_QSORT_SWAP_SWAP_A8__C_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap/swap_a8._C.h                                                  //
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
swap_8a8(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint64_t *const RESTRICT a_x = a;
	uint64_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a_0, t_b_0;

	t_a_0   = a_x[0u];
	t_b_0   = b_x[0u];

	b_x[0u] = t_a_0;
	a_x[0u] = t_b_0;

	return;
}

QSORT_SWAP_ABI
static void
swap_16a8(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint64_t *const RESTRICT a_x = a;
	uint64_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a_0, t_a_1, t_b_0, t_b_1;

	t_a_0    = a_x[ 0u];
	t_a_1    = a_x[ 1u];
	t_b_0    = b_x[ 0u];
	t_b_1    = b_x[ 1u];

	b_x[ 0u] = t_a_0;
	b_x[ 1u] = t_a_1;
	a_x[ 0u] = t_b_0;
	a_x[ 1u] = t_b_1;

	return;
}

QSORT_SWAP_ABI
static void
swap_24a8(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint64_t *const RESTRICT a_x = a;
	uint64_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a_0, t_a_1, t_a_2, t_b_0, t_b_1, t_b_2;

	t_a_0    = a_x[ 0u];
	t_a_1    = a_x[ 1u];
	t_a_2    = a_x[ 2u];
	t_b_0    = b_x[ 0u];
	t_b_1    = b_x[ 1u];
	t_b_2    = b_x[ 2u];

	b_x[ 0u] = t_a_0;
	b_x[ 1u] = t_a_1;
	b_x[ 2u] = t_a_2;
	a_x[ 0u] = t_b_0;
	a_x[ 1u] = t_b_1;
	a_x[ 2u] = t_b_2;

	return;
}

QSORT_SWAP_ABI
static void
swap_32a8(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint64_t *const RESTRICT a_x = a;
	uint64_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a_0, t_a_1, t_a_2, t_a_3, t_b_0, t_b_1, t_b_2, t_b_3;

	t_a_0    = a_x[ 0u];
	t_a_1    = a_x[ 1u];
	t_a_2    = a_x[ 2u];
	t_a_3    = a_x[ 3u];
	t_b_0    = b_x[ 0u];
	t_b_1    = b_x[ 1u];
	t_b_2    = b_x[ 2u];
	t_b_3    = b_x[ 3u];

	b_x[ 0u] = t_a_0;
	b_x[ 1u] = t_a_1;
	b_x[ 2u] = t_a_2;
	b_x[ 3u] = t_a_3;
	a_x[ 0u] = t_b_0;
	a_x[ 1u] = t_b_1;
	a_x[ 2u] = t_b_2;
	a_x[ 3u] = t_b_3;

	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_SWAP_A8__C_H */
