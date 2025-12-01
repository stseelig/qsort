#ifndef H_QSORT_SWAP_SWAP_A4__C_H
#define H_QSORT_SWAP_SWAP_A4__C_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap/swap_a4._C.h                                                  //
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
swap_4a4(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint32_t *const RESTRICT a_x = a;
	uint32_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a_0, t_b_0;

	t_a_0   = a_x[0u];
	t_b_0   = b_x[0u];

	b_x[0u] = t_a_0;
	a_x[0u] = t_b_0;

	return;
}

QSORT_SWAP_ABI
static void
swap_8a4(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint32_t *const RESTRICT a_x = a;
	uint32_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a_0, t_a_1, t_b_0, t_b_1;

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
swap_12a4(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint32_t *const RESTRICT a_x = a;
	uint32_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a_0, t_a_1, t_a_2, t_b_0, t_b_1, t_b_2;

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
swap_16a4(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint32_t *const RESTRICT a_x = a;
	uint32_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a_0, t_a_1, t_a_2, t_a_3, t_b_0, t_b_1, t_b_2, t_b_3;

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

QSORT_SWAP_ABI
static void
swap_20a4(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint32_t *const RESTRICT a_x = a;
	uint32_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a_0, t_a_1, t_a_2, t_a_3, t_a_4;
	uint32_t t_b_0, t_b_1, t_b_2, t_b_3, t_b_4;

	t_a_0    = a_x[ 0u];
	t_a_1    = a_x[ 1u];
	t_a_2    = a_x[ 2u];
	t_a_3    = a_x[ 3u];
	t_a_4    = a_x[ 4u];
	t_b_0    = b_x[ 0u];
	t_b_1    = b_x[ 1u];
	t_b_2    = b_x[ 2u];
	t_b_3    = b_x[ 3u];
	t_b_4    = b_x[ 4u];

	b_x[ 0u] = t_a_0;
	b_x[ 1u] = t_a_1;
	b_x[ 2u] = t_a_2;
	b_x[ 3u] = t_a_3;
	b_x[ 4u] = t_a_4;
	a_x[ 0u] = t_b_0;
	a_x[ 1u] = t_b_1;
	a_x[ 2u] = t_b_2;
	a_x[ 3u] = t_b_3;
	a_x[ 4u] = t_b_4;

	return;
}

QSORT_SWAP_ABI
static void
swap_24a4(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint32_t *const RESTRICT a_x = a;
	uint32_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a_0, t_a_1, t_a_2, t_a_3, t_a_4, t_a_5;
	uint32_t t_b_0, t_b_1, t_b_2, t_b_3, t_b_4, t_b_5;

	t_a_0    = a_x[ 0u];
	t_a_1    = a_x[ 1u];
	t_a_2    = a_x[ 2u];
	t_a_3    = a_x[ 3u];
	t_a_4    = a_x[ 4u];
	t_a_5    = a_x[ 5u];
	t_b_0    = b_x[ 0u];
	t_b_1    = b_x[ 1u];
	t_b_2    = b_x[ 2u];
	t_b_3    = b_x[ 3u];
	t_b_4    = b_x[ 4u];
	t_b_5    = b_x[ 5u];

	b_x[ 0u] = t_a_0;
	b_x[ 1u] = t_a_1;
	b_x[ 2u] = t_a_2;
	b_x[ 3u] = t_a_3;
	b_x[ 4u] = t_a_4;
	b_x[ 5u] = t_a_5;
	a_x[ 0u] = t_b_0;
	a_x[ 1u] = t_b_1;
	a_x[ 2u] = t_b_2;
	a_x[ 3u] = t_b_3;
	a_x[ 4u] = t_b_4;
	a_x[ 5u] = t_b_5;

	return;
}

QSORT_SWAP_ABI
static void
swap_28a4(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint32_t *const RESTRICT a_x = a;
	uint32_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a_0, t_a_1, t_a_2, t_a_3, t_a_4, t_a_5, t_a_6;
	uint32_t t_b_0, t_b_1, t_b_2, t_b_3, t_b_4, t_b_5, t_b_6;

	t_a_0    = a_x[ 0u];
	t_a_1    = a_x[ 1u];
	t_a_2    = a_x[ 2u];
	t_a_3    = a_x[ 3u];
	t_a_4    = a_x[ 4u];
	t_a_5    = a_x[ 5u];
	t_a_6    = a_x[ 6u];
	t_b_0    = b_x[ 0u];
	t_b_1    = b_x[ 1u];
	t_b_2    = b_x[ 2u];
	t_b_3    = b_x[ 3u];
	t_b_4    = b_x[ 4u];
	t_b_5    = b_x[ 5u];
	t_b_6    = b_x[ 6u];

	b_x[ 0u] = t_a_0;
	b_x[ 1u] = t_a_1;
	b_x[ 2u] = t_a_2;
	b_x[ 3u] = t_a_3;
	b_x[ 4u] = t_a_4;
	b_x[ 5u] = t_a_5;
	b_x[ 6u] = t_a_6;
	a_x[ 0u] = t_b_0;
	a_x[ 1u] = t_b_1;
	a_x[ 2u] = t_b_2;
	a_x[ 3u] = t_b_3;
	a_x[ 4u] = t_b_4;
	a_x[ 5u] = t_b_5;
	a_x[ 6u] = t_b_6;

	return;
}

QSORT_SWAP_ABI
static void
swap_32a4(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	uint32_t *const RESTRICT a_x = a;
	uint32_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a_0, t_a_1, t_a_2, t_a_3, t_a_4, t_a_5, t_a_6, t_a_7;
	uint32_t t_b_0, t_b_1, t_b_2, t_b_3, t_b_4, t_b_5, t_b_6, t_b_7;

	t_a_0    = a_x[ 0u];
	t_a_1    = a_x[ 1u];
	t_a_2    = a_x[ 2u];
	t_a_3    = a_x[ 3u];
	t_a_4    = a_x[ 4u];
	t_a_5    = a_x[ 5u];
	t_a_6    = a_x[ 6u];
	t_a_7    = a_x[ 7u];
	t_b_0    = b_x[ 0u];
	t_b_1    = b_x[ 1u];
	t_b_2    = b_x[ 2u];
	t_b_3    = b_x[ 3u];
	t_b_4    = b_x[ 4u];
	t_b_5    = b_x[ 5u];
	t_b_6    = b_x[ 6u];
	t_b_7    = b_x[ 7u];

	b_x[ 0u] = t_a_0;
	b_x[ 1u] = t_a_1;
	b_x[ 2u] = t_a_2;
	b_x[ 3u] = t_a_3;
	b_x[ 4u] = t_a_4;
	b_x[ 5u] = t_a_5;
	b_x[ 6u] = t_a_6;
	b_x[ 7u] = t_a_7;
	a_x[ 0u] = t_b_0;
	a_x[ 1u] = t_b_1;
	a_x[ 2u] = t_b_2;
	a_x[ 3u] = t_b_3;
	a_x[ 4u] = t_b_4;
	a_x[ 5u] = t_b_5;
	a_x[ 6u] = t_b_6;
	a_x[ 7u] = t_b_7;

	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_SWAP_A4__C_H */
