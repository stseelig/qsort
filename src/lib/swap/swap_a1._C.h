#ifndef H_QSORT_SWAP_SWAP_A1__C_H
#define H_QSORT_SWAP_SWAP_A1__C_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap/swap_a1._C.h                                                  //
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
swap_1a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
	SWAP_X_BODY(1u, 1u);
}

QSORT_SWAP_ABI
static void
swap_2a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_2_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint16_t t_a2, t_b2;

	t_a2 = *((uint16_t *) &a_x[0u]);
	t_b2 = *((uint16_t *) &b_x[0u]);

	*((uint16_t *) &b_x[0u]) = t_a2;
	*((uint16_t *) &a_x[0u]) = t_b2;

	return;

#else
	SWAP_X_BODY(2u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_3a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_2_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint16_t t_a2, t_b2;
	uint8_t  t_a1, t_b1;

	t_a2 = *((uint16_t *) &a_x[0u]);
	t_a1 = a_x[2u];
	t_b2 = *((uint16_t *) &b_x[0u]);
	t_b1 = b_x[2u];

	*((uint16_t *) &b_x[0u]) = t_a2;
	b_x[2u] = t_a1;
	*((uint16_t *) &a_x[0u]) = t_b2;
	a_x[2u] = t_b1;

	return;

#else
	SWAP_X_BODY(3u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_4a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4, t_b4;

	t_a4 = *((uint32_t *) &a_x[0u]);
	t_b4 = *((uint32_t *) &b_x[0u]);

	*((uint32_t *) &b_x[0u]) = t_a4;
	*((uint32_t *) &a_x[0u]) = t_b4;

	return;

#else
	SWAP_X_BODY(4u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_5a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4, t_b4;
	uint8_t  t_a1, t_b1;

	t_a4 = *((uint32_t *) &a_x[0u]);
	t_a1 = a_x[4u];
	t_b4 = *((uint32_t *) &b_x[0u]);
	t_b1 = b_x[4u];

	*((uint32_t *) &b_x[0u]) = t_a4;
	b_x[4u] = t_a1;
	*((uint32_t *) &a_x[0u]) = t_b4;
	a_x[4u] = t_b1;

	return;

#else
	SWAP_X_BODY(5u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_6a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_4_OK)

#if defined(QSORT_ARCH_UNALIGNED_2_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4, t_b4;
	uint16_t t_a2, t_b2;

	t_a4 = *((uint32_t *) &a_x[0u]);
	t_a2 = *((uint16_t *) &a_x[4u]);
	t_b4 = *((uint32_t *) &b_x[0u]);
	t_b2 = *((uint16_t *) &b_x[4u]);

	*((uint32_t *) &b_x[0u]) = t_a4;
	*((uint16_t *) &b_x[4u]) = t_a2;
	*((uint32_t *) &a_x[0u]) = t_b4;
	*((uint16_t *) &a_x[4u]) = t_b2;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4, t_b4;
	uint8_t t_a1_0, t_a1_1, t_b1_0, t_b1_1;

	t_a4   = *((uint32_t *) &a_x[0u]);
	t_a1_0 = a_x[4u];
	t_a1_1 = a_x[5u];
	t_b4   = *((uint32_t *) &b_x[0u]);
	t_b1_0 = b_x[4u];
	t_b1_1 = b_x[5u];

	*((uint32_t *) &b_x[0u]) = t_a4;
	b_x[4u] = t_a1_0;
	b_x[5u] = t_a1_1;
	*((uint32_t *) &a_x[0u]) = t_b4;
	a_x[4u] = t_b1_0;
	a_x[5u] = t_b1_1;

	return;

#endif /* QSORT_ARCH_UNALIGNED_2_OK */

#else
	SWAP_X_BODY(6u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_7a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_4_OK)

#if defined(QSORT_ARCH_UNALIGNED_2_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4, t_b4;
	uint16_t t_a2, t_b2;
	uint8_t  t_a1, t_b1;

	t_a4 = *((uint32_t *) &a_x[0u]);
	t_a2 = *((uint16_t *) &a_x[4u]);
	t_a1 = a_x[6u];
	t_b4 = *((uint32_t *) &b_x[0u]);
	t_b2 = *((uint16_t *) &b_x[4u]);
	t_b1 = b_x[6u];

	*((uint32_t *) &b_x[0u]) = t_a4;
	*((uint16_t *) &b_x[4u]) = t_a2;
	b_x[6u] = t_a1;
	*((uint32_t *) &a_x[0u]) = t_b4;
	*((uint16_t *) &a_x[4u]) = t_b2;
	a_x[6u] = t_b1;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4, t_b4;
	uint8_t  t_a1_0, t_a1_1, t_a1_2, t_b1_0, t_b1_1, t_b1_2;

	t_a4   = *((uint32_t *) &a_x[0u]);
	t_a1_0 = a_x[4u];
	t_a1_1 = a_x[5u];
	t_a1_2 = a_x[6u];
	t_b4   = *((uint32_t *) &b_x[0u]);
	t_b1_0 = b_x[4u];
	t_b1_1 = b_x[5u];
	t_b1_2 = b_x[6u];

	*((uint32_t *) &b_x[0u]) = t_a4;
	b_x[4u] = t_a1_0;
	b_x[5u] = t_a1_1;
	b_x[6u] = t_a1_2;
	*((uint32_t *) &a_x[0u]) = t_b4;
	a_x[4u] = t_b1_0;
	a_x[5u] = t_b1_1;
	a_x[6u] = t_b1_2;

	return;

#endif	/* QSORT_ARCH_UNALIGNED_2_OK */

#else
	SWAP_X_BODY(7u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_8a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;

	t_a8 = *((uint64_t *) &a_x[0u]);
	t_b8 = *((uint64_t *) &b_x[0u]);

	*((uint64_t *) &b_x[0u]) = t_a8;
	*((uint64_t *) &a_x[0u]) = t_b8;

	return;

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_b4_0, t_b4_1;

	t_a4_0 = *((uint32_t *) &a_x[0u]);
	t_a4_1 = *((uint32_t *) &a_x[4u]);
	t_b4_0 = *((uint32_t *) &b_x[0u]);
	t_b4_1 = *((uint32_t *) &b_x[4u]);

	*((uint32_t *) &b_x[0u]) = t_a4_0;
	*((uint32_t *) &b_x[4u]) = t_a4_1;
	*((uint32_t *) &a_x[0u]) = t_b4_0;
	*((uint32_t *) &a_x[4u]) = t_b4_1;

	return;

#else
	SWAP_X_BODY(8u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_9a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint8_t  t_a1, t_b1;

	t_a8 = *((uint64_t *) &a_x[0u]);
	t_a1 = a_x[8u];
	t_b8 = *((uint64_t *) &b_x[0u]);
	t_b1 = b_x[8u];

	*((uint64_t *) &b_x[0u]) = t_a8;
	b_x[8u] = t_a1;
	*((uint64_t *) &a_x[0u]) = t_b8;
	a_x[8u] = t_b1;

	return;

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_b4_0, t_b4_1;
	uint8_t  t_a1, t_b1;

	t_a4_0 = *((uint32_t *) &a_x[0u]);
	t_a4_1 = *((uint32_t *) &a_x[4u]);
	t_a1   = a_x[8u];
	t_b4_0 = *((uint32_t *) &b_x[0u]);
	t_b4_1 = *((uint32_t *) &b_x[4u]);
	t_b1   = b_x[8u];

	*((uint32_t *) &b_x[0u]) = t_a4_0;
	*((uint32_t *) &b_x[4u]) = t_a4_1;
	b_x[8u] = t_a1;
	*((uint32_t *) &a_x[0u]) = t_b4_0;
	*((uint32_t *) &a_x[4u]) = t_b4_1;
	a_x[8u] = t_b1;

	return;

#else
	SWAP_X_BODY(9u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_10a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK)

#if defined(QSORT_ARCH_UNALIGNED_2_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint16_t t_a2, t_b2;

	t_a8 = *((uint64_t *) &a_x[0u]);
	t_a2 = *((uint16_t *) &a_x[8u]);
	t_b8 = *((uint64_t *) &b_x[0u]);
	t_b2 = *((uint16_t *) &b_x[8u]);

	*((uint64_t *) &b_x[0u]) = t_a8;
	*((uint16_t *) &b_x[8u]) = t_a2;
	*((uint64_t *) &a_x[0u]) = t_b8;
	*((uint16_t *) &a_x[8u]) = t_b2;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint8_t  t_a1_0, t_a1_1, t_b1_0, t_b1_1;

	t_a8   = *((uint64_t *) &a_x[0u]);
	t_a1_0 = a_x[8u];
	t_a2_0 = a_x[9u];
	t_b8   = *((uint64_t *) &b_x[0u]);
	t_b1_0 = b_x[8u];
	t_b2_0 = b_x[9u];

	*((uint64_t *) &b_x[0u]) = t_a8;
	b_x[8u] = t_a1_0;
	b_x[9u] = t_a1_1;
	*((uint64_t *) &a_x[0u]) = t_b8;
	a_x[8u] = t_b1_0;
	a_x[9u] = t_b1_1;

	return;

#endif	/* QSORT_ARCH_UNALIGNED_2_OK */

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

#if defined(QSORT_ARCH_UNALIGNED_2_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_b4_0, t_b4_1;
	uint16_t t_a2, t_b2;

	t_a4_0 = *((uint32_t *) &a_x[0u]);
	t_a4_1 = *((uint32_t *) &a_x[4u]);
	t_a2   = *((uint16_t *) &a_x[8u]);
	t_b4_0 = *((uint32_t *) &b_x[0u]);
	t_b4_1 = *((uint32_t *) &b_x[4u]);
	t_b2   = *((uint16_t *) &b_x[8u]);

	*((uint32_t *) &b_x[0u]) = t_a4_0;
	*((uint32_t *) &b_x[4u]) = t_a4_1;
	*((uint16_t *) &b_x[8u]) = t_a2;
	*((uint32_t *) &a_x[0u]) = t_b4_0;
	*((uint32_t *) &a_x[4u]) = t_b4_1;
	*((uint16_t *) &a_x[8u]) = t_b2;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_b4_0, t_b4_1;
	uint8_t  t_a1_0, t_a1_1, t_b1_0, t_b1_1;

	t_a4_0 = *((uint32_t *) &a_x[0u]);
	t_a4_1 = *((uint32_t *) &a_x[4u]);
	t_a1_0 = a_x[8u];
	t_a1_1 = a_x[9u];
	t_b4_0 = *((uint32_t *) &b_x[0u]);
	t_b4_1 = *((uint32_t *) &b_x[4u]);
	t_b1_0 = b_x[8u];
	t_b1_1 = b_x[9u];

	*((uint32_t *) &b_x[0u]) = t_a4_0;
	*((uint32_t *) &b_x[4u]) = t_a4_1;
	b_x[8u] = t_a1_0;
	b_x[9u] = t_a1_1;
	*((uint32_t *) &a_x[0u]) = t_b4_0;
	*((uint32_t *) &a_x[4u]) = t_b4_1;
	a_x[8u] = t_b1_0;
	a_x[9u] = t_b1_1;

	return;

#endif	/* QSORT_ARCH_UNALIGNED_2_OK */

#else
	SWAP_X_BODY(10u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_11a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK)

#if defined(QSORT_ARCH_UNALIGNED_2_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint16_t t_a2, t_b2;
	uint8_t  t_a1, t_b1;

	t_a8 = *((uint64_t *) &a_x[ 0u]);
	t_a2 = *((uint16_t *) &a_x[ 8u]);
	t_a1 = a_x[10u];
	t_b8 = *((uint64_t *) &b_x[ 0u]);
	t_b2 = *((uint16_t *) &b_x[ 8u]);
	t_b1 = b_x[10u];

	*((uint64_t *) &b_x[ 0u]) = t_a8;
	*((uint16_t *) &b_x[ 8u]) = t_a2;
	b_x[10u] = t_a1;
	*((uint64_t *) &a_x[ 0u]) = t_b8;
	*((uint16_t *) &a_x[ 8u]) = t_b2;
	a_x[10u] = t_b1;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint8_t t_a1_0, t_a1_1, t_a1_2, t_b1_0, t_b1_1, t_b1_2;

	t_a8   = *((uint64_t *) &a_x[ 0u]);
	t_a1_0 = a_x[ 8u];
	t_a1_1 = a_x[ 9u];
	t_a1_2 = a_x[10u];
	t_b8   = *((uint64_t *) &b_x[ 0u]);
	t_b1_0 = b_x[ 8u];
	t_b1_1 = b_x[ 9u];
	t_b1_2 = b_x[10u];

	*((uint64_t *) &b_x[ 0u]) = t_a8;
	b_x[ 8u] = t_a1_0;
	b_x[ 9u] = t_a1_1;
	b_x[10u] = t_a1_2;
	*((uint64_t *) &a_x[ 0u]) = t_b8;
	a_x[ 8u] = t_b1_0;
	a_x[ 9u] = t_b1_1;
	a_x[10u] = t_b1_2;

	return;

#endif	/* QSORT_ARCH_UNALIGNED_2_OK */

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

#if defined(QSORT_ARCH_UNALIGNED_2_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_b4_0, t_b4_1;
	uint16_t t_a2, t_b2;
	uint8_t  t_a1, t_b1;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a2   = *((uint16_t *) &a_x[ 8u]);
	t_a1   = a_x[10u];
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b2   = *((uint16_t *) &b_x[ 8u]);
	t_b1   = b_x[10u];

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint16_t *) &b_x[ 8u]) = t_a2;
	b_x[10u] = t_a1;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint16_t *) &a_x[ 8u]) = t_b2;
	a_x[10u] = t_b1;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_b4_0, t_b4_1;
	uint8_t t_a1_0, t_a1_1, t_a1_2, t_b1_0, t_b1_1, t_b1_2;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a1_0 = a_x[ 8u];
	t_a1_1 = a_x[ 9u];
	t_a1_2 = a_x[10u];
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b1_0 = b_x[ 8u];
	t_b1_1 = b_x[ 9u];
	t_b1_2 = b_x[10u];

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	b_x[ 8u] = t_a1_0;
	b_x[ 9u] = t_a1_1;
	b_x[10u] = t_a1_2;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	a_x[ 8u] = t_b1_0;
	a_x[ 9u] = t_b1_1;
	a_x[10u] = t_b1_2;

	return;

#endif	/* QSORT_ARCH_UNALIGNED_2_OK */

#else
	SWAP_X_BODY(11u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_12a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK) && defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint32_t t_a4, t_b4;

	t_a8 = *((uint64_t *) &a_x[0u]);
	t_a4 = *((uint32_t *) &a_x[8u]);
	t_b8 = *((uint64_t *) &b_x[0u]);
	t_b4 = *((uint32_t *) &b_x[8u]);

	*((uint64_t *) &b_x[0u]) = t_a8;
	*((uint32_t *) &b_x[8u]) = t_a4;
	*((uint64_t *) &a_x[0u]) = t_b8;
	*((uint32_t *) &a_x[8u]) = t_b4;

	return;

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_b4_0, t_b4_1, t_b4_2;

	t_a4_0 = *((uint32_t *) &a_x[0u]);
	t_a4_1 = *((uint32_t *) &a_x[4u]);
	t_a4_2 = *((uint32_t *) &a_x[8u]);
	t_b4_0 = *((uint32_t *) &b_x[0u]);
	t_b4_1 = *((uint32_t *) &b_x[4u]);
	t_b4_2 = *((uint32_t *) &b_x[8u]);

	*((uint32_t *) &b_x[0u]) = t_a4_0;
	*((uint32_t *) &b_x[4u]) = t_a4_1;
	*((uint32_t *) &b_x[8u]) = t_a4_2;
	*((uint32_t *) &a_x[0u]) = t_b4_0;
	*((uint32_t *) &a_x[4u]) = t_b4_1;
	*((uint32_t *) &a_x[8u]) = t_b4_2;

	return;

#else
	SWAP_X_BODY(12u, 1u);
#endif
}


QSORT_SWAP_ABI
static void
swap_13a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK) && defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint32_t t_a4, t_b4;
	uint8_t  t_a1, t_b1;

	t_a8 = *((uint64_t *) &a_x[ 0u]);
	t_a4 = *((uint32_t *) &a_x[ 8u]);
	t_a1 = a_x[12u];
	t_b8 = *((uint64_t *) &b_x[ 0u]);
	t_b4 = *((uint32_t *) &b_x[ 8u]);
	t_b1 = b_x[12u];

	*((uint64_t *) &b_x[ 0u]) = t_a8;
	*((uint32_t *) &b_x[ 8u]) = t_a4;
	b_x[12u] = t_a1;
	*((uint64_t *) &a_x[ 0u]) = t_b8;
	*((uint32_t *) &a_x[ 8u]) = t_b4;
	a_x[12u] = t_b1;

	return;

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_b4_0, t_b4_1, t_b4_2;
	uint8_t  t_a1, t_b1;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a1   = a_x[12u];
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b1   = b_x[12u];

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	b_x[12u] = t_a1;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	a_x[12u] = t_b1;

	return;

#else
	SWAP_X_BODY(13u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_14a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK)			/* 0 */

#if defined(QSORT_ARCH_UNALIGNED_4_OK)			/* 1 */

#if defined(QSORT_ARCH_UNALIGNED_2_OK)			/* 2 */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint32_t t_a4, t_b4;
	uint16_t t_a2, t_b2;

	t_a8 = *((uint64_t *) &a_x[ 0u]);
	t_a4 = *((uint32_t *) &a_x[ 8u]);
	t_a2 = *((uint16_t *) &a_x[12u]);
	t_b8 = *((uint64_t *) &b_x[ 0u]);
	t_b4 = *((uint32_t *) &b_x[ 8u]);
	t_b2 = *((uint16_t *) &b_x[12u]);

	*((uint64_t *) &b_x[ 0u]) = t_a8;
	*((uint32_t *) &b_x[ 8u]) = t_a4;
	*((uint16_t *) &b_x[12u]) = t_a2;
	*((uint64_t *) &a_x[ 0u]) = t_b8;
	*((uint32_t *) &a_x[ 8u]) = t_b4;
	*((uint16_t *) &a_x[12u]) = t_b2;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */	/* 2 */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint32_t t_a4, t_b4;
	uint8_t  t_a1_0, t_a1_1, t_b1_0, t_b1_1;

	t_a8   = *((uint64_t *) &a_x[ 0u]);
	t_a4   = *((uint32_t *) &a_x[ 8u]);
	t_a1_0 = a_x[12u];
	t_a1_1 = a_x[13u];
	t_b8   = *((uint64_t *) &b_x[ 0u]);
	t_b4   = *((uint32_t *) &b_x[ 8u]);
	t_b1_0 = b_x[12u];
	t_b1_1 = b_x[13u];

	*((uint64_t *) &b_x[ 0u]) = t_a8;
	*((uint32_t *) &b_x[ 8u]) = t_a4;
	a_x[12u] = t_b1_0;
	a_x[13u] = t_b1_1;
	*((uint64_t *) &a_x[ 0u]) = t_b8;
	*((uint32_t *) &a_x[ 8u]) = t_b4;
	b_x[12u] = t_a1_0;
	b_x[13u] = t_a1_1;

	return;

#endif	/* QSORT_ARCH_UNALIGNED_2_OK */			/* 2 */

#else							/* 1 */
	SWAP_X_BODY(14u, 1u);

#endif	/* QSORT_ARCH_UNALIGNED_4_OK */			/* 1 */

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)		/* 0 */

#if defined(QSORT_ARCH_UNALIGNED_2_OK)			/* 1 */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_b4_0, t_b4_1, t_b4_2;
	uint16_t t_a2, t_b2;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a2   = *((uint16_t *) &a_x[12u]);
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b2   = *((uint16_t *) &b_x[12u]);

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	*((uint16_t *) &b_x[12u]) = t_a2;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	*((uint16_t *) &a_x[12u]) = t_b2;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */	/* 1 */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_b4_0, t_b4_1, t_b4_2;
	uint8_t  t_a1_0, t_a1_1, t_b1_0, t_b1_1;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a1_0 = a_x[12u];
	t_a1_1 = a_x[13u];
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b1_0 = b_x[12u];
	t_b1_1 = b_x[13u];

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	b_x[12u] = t_a1_0;
	b_x[12u] = t_a1_1;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	a_x[12u] = t_b1_0;
	a_x[12u] = t_b1_1;

	return;

#endif	/* QSORT_ARCH_UNALIGNED_4_OK */			/* 1 */

#else							/* 0 */
	SWAP_X_BODY(14u, 1u);
#endif							/* 0 */
}


QSORT_SWAP_ABI
static void
swap_15a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK)			/* 0 */

#if defined(QSORT_ARCH_UNALIGNED_4_OK)			/* 1 */

#if defined(QSORT_ARCH_UNALIGNED_2_OK)			/* 2 */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint32_t t_a4, t_b4;
	uint16_t t_a2, t_b2;
	uint8_t  t_a1, t_b1;

	t_a8 = *((uint64_t *) &a_x[ 0u]);
	t_a4 = *((uint32_t *) &a_x[ 8u]);
	t_a2 = *((uint16_t *) &a_x[12u]);
	t_a1 = a_x[14u];
	t_b8 = *((uint64_t *) &b_x[ 0u]);
	t_b4 = *((uint32_t *) &b_x[ 8u]);
	t_b2 = *((uint16_t *) &b_x[12u]);
	t_b1 = b_x[14u];

	*((uint64_t *) &b_x[ 0u]) = t_a8;
	*((uint32_t *) &b_x[ 8u]) = t_a4;
	*((uint16_t *) &b_x[12u]) = t_a2;
	b_x[14u] = t_a1;
	*((uint64_t *) &a_x[ 0u]) = t_b8;
	*((uint32_t *) &a_x[ 8u]) = t_b4;
	*((uint16_t *) &a_x[12u]) = t_b2;
	a_x[14u] = t_b1;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */	/* 2 */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8, t_b8;
	uint32_t t_a4, t_b4;
	uint8_t  t_a1_0, t_a1_1, t_a1_2, t_b1_0, t_b1_1, t_b1_2;

	t_a8   = *((uint64_t *) &a_x[ 0u]);
	t_a4   = *((uint32_t *) &a_x[ 8u]);
	t_a1_0 = a_x[12u];
	t_a1_1 = a_x[13u];
	t_a1_2 = a_x[14u];
	t_b8   = *((uint64_t *) &b_x[ 0u]);
	t_b4   = *((uint32_t *) &b_x[ 8u]);
	t_b1_0 = b_x[12u];
	t_b1_1 = b_x[13u];
	t_b1_2 = b_x[14u];

	*((uint64_t *) &b_x[ 0u]) = t_a8;
	*((uint32_t *) &b_x[ 8u]) = t_a4;
	a_x[12u] = t_b1_0;
	a_x[13u] = t_b1_1;
	a_x[14u] = t_b1_2;
	*((uint64_t *) &a_x[ 0u]) = t_b8;
	*((uint32_t *) &a_x[ 8u]) = t_b4;
	b_x[12u] = t_a1_0;
	b_x[13u] = t_a1_1;
	b_x[14u] = t_a1_2;

	return;

#endif	/* QSORT_ARCH_UNALIGNED_2_OK */			/* 2 */

#else							/* 1 */
	SWAP_X_BODY(14u, 1u);

#endif	/* QSORT_ARCH_UNALIGNED_4_OK */			/* 1 */

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)		/* 0 */

#if defined(QSORT_ARCH_UNALIGNED_2_OK)			/* 1 */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_b4_0, t_b4_1, t_b4_2;
	uint16_t t_a2, t_b2;
	uint8_t  t_a1, t_b1;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a2   = *((uint16_t *) &a_x[12u]);
	t_a1   = a_x[14u];
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b2   = *((uint16_t *) &b_x[12u]);
	t_b1   = b_x[14u];

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	*((uint16_t *) &b_x[12u]) = t_a2;
	b_x[14u] = t_a1;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	*((uint16_t *) &a_x[12u]) = t_b2;
	a_x[14u] = t_b1;

	return;

#else	/* ! defined(QSORT_ARCH_UNALIGNED_2_OK) */	/* 1 */

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_b4_0, t_b4_1, t_b4_2;
	uint8_t  t_a1_0, t_a1_1, t_a1_2, t_b1_0, t_b1_1, t_b1_2;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a1_0 = a_x[12u];
	t_a1_1 = a_x[13u];
	t_a1_2 = a_x[14u];
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b1_0 = b_x[12u];
	t_b1_1 = b_x[13u];
	t_b1_2 = b_x[14u];

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	b_x[12u] = t_a1_0;
	b_x[13u] = t_a1_1;
	b_x[14u] = t_a1_2;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	a_x[12u] = t_b1_0;
	a_x[13u] = t_b1_1;
	a_x[14u] = t_b1_2;

	return;

#endif	/* QSORT_ARCH_UNALIGNED_4_OK */			/* 1 */

#else							/* 0 */
	SWAP_X_BODY(15u, 1u);
#endif							/* 0 */
}

QSORT_SWAP_ABI
static void
swap_16a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8_0, t_a8_1, t_b8_0, t_b8_1;

	t_a8_0 = *((uint64_t *) &a_x[0u]);
	t_a8_1 = *((uint64_t *) &a_x[8u]);
	t_b8_0 = *((uint64_t *) &b_x[0u]);
	t_b8_1 = *((uint64_t *) &b_x[8u]);

	*((uint64_t *) &b_x[0u]) = t_a8_0;
	*((uint64_t *) &b_x[8u]) = t_a8_1;
	*((uint64_t *) &a_x[0u]) = t_b8_0;
	*((uint64_t *) &a_x[8u]) = t_b8_1;

	return;

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_a4_3;
	uint32_t t_b4_0, t_b4_1, t_b4_2, t_b4_3;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a4_3 = *((uint32_t *) &a_x[12u]);
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b4_3 = *((uint32_t *) &b_x[12u]);

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	*((uint32_t *) &b_x[12u]) = t_a4_3;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	*((uint32_t *) &a_x[12u]) = t_b4_3;

	return;

#else
	SWAP_X_BODY(16u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_20a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_4_OK) && defined(QSORT_ARCH_UNALIGNED_8_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8_0, t_a8_1, t_b8_0, t_b8_1;
	uint32_t t_a4, t_b4;

	t_a8_0 = *((uint64_t *) &a_x[ 0u]);
	t_a8_1 = *((uint64_t *) &a_x[ 8u]);
	t_a4   = *((uint32_t *) &a_x[16u]);
	t_b8_0 = *((uint64_t *) &b_x[ 0u]);
	t_b8_1 = *((uint64_t *) &b_x[ 8u]);
	t_b4   = *((uint32_t *) &b_x[16u]);

	*((uint64_t *) &b_x[ 0u]) = t_a8_0;
	*((uint64_t *) &b_x[ 8u]) = t_a8_1;
	*((uint32_t *) &b_x[16u]) = t_a4;
	*((uint64_t *) &a_x[ 0u]) = t_b8_0;
	*((uint64_t *) &a_x[ 8u]) = t_b8_1;
	*((uint32_t *) &a_x[16u]) = t_b4;

	return;

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_a4_3, t_a4_4;
	uint32_t t_b4_0, t_b4_1, t_b4_2, t_b4_3, t_b4_4;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a4_3 = *((uint32_t *) &a_x[12u]);
	t_a4_4 = *((uint32_t *) &a_x[16u]);
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b4_3 = *((uint32_t *) &b_x[12u]);
	t_b4_4 = *((uint32_t *) &b_x[16u]);

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	*((uint32_t *) &b_x[12u]) = t_a4_3;
	*((uint32_t *) &b_x[16u]) = t_a4_4;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	*((uint32_t *) &a_x[12u]) = t_b4_3;
	*((uint32_t *) &a_x[16u]) = t_b4_4;

	return;

#else
	SWAP_X_BODY(20u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_24a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8_0, t_a8_1, t_a8_2;
	uint64_t t_b8_0, t_b8_1, t_b8_2;

	t_a8_0 = *((uint64_t *) &a_x[ 0u]);
	t_a8_1 = *((uint64_t *) &a_x[ 8u]);
	t_a8_2 = *((uint64_t *) &a_x[16u]);
	t_b8_0 = *((uint64_t *) &b_x[ 0u]);
	t_b8_1 = *((uint64_t *) &b_x[ 8u]);
	t_b8_2 = *((uint64_t *) &b_x[16u]);

	*((uint64_t *) &b_x[ 0u]) = t_a8_0;
	*((uint64_t *) &b_x[ 8u]) = t_a8_1;
	*((uint64_t *) &b_x[16u]) = t_a8_2;
	*((uint64_t *) &a_x[ 0u]) = t_b8_0;
	*((uint64_t *) &a_x[ 8u]) = t_b8_1;
	*((uint64_t *) &a_x[16u]) = t_b8_2;

	return;

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_a4_3, t_a4_4, t_a4_5;
	uint32_t t_b4_0, t_b4_1, t_b4_2, t_b4_3, t_b4_4, t_b4_5;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a4_3 = *((uint32_t *) &a_x[12u]);
	t_a4_4 = *((uint32_t *) &a_x[16u]);
	t_a4_5 = *((uint32_t *) &a_x[20u]);
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b4_3 = *((uint32_t *) &b_x[12u]);
	t_b4_4 = *((uint32_t *) &b_x[16u]);
	t_b4_5 = *((uint32_t *) &b_x[20u]);

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	*((uint32_t *) &b_x[12u]) = t_a4_3;
	*((uint32_t *) &b_x[16u]) = t_a4_4;
	*((uint32_t *) &b_x[20u]) = t_a4_5;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	*((uint32_t *) &a_x[12u]) = t_b4_3;
	*((uint32_t *) &a_x[16u]) = t_b4_4;
	*((uint32_t *) &a_x[20u]) = t_b4_5;

	return;

#else
	SWAP_X_BODY(24u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_28a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_4_OK) && defined(QSORT_ARCH_UNALIGNED_8_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8_0, t_a8_1, t_a8_2, t_b8_0, t_b8_1, t_b8_2;
	uint32_t t_a4, t_b4;

	t_a8_0 = *((uint64_t *) &a_x[ 0u]);
	t_a8_1 = *((uint64_t *) &a_x[ 8u]);
	t_a8_2 = *((uint64_t *) &a_x[16u]);
	t_a4   = *((uint32_t *) &a_x[24u]);
	t_b8_0 = *((uint64_t *) &b_x[ 0u]);
	t_b8_1 = *((uint64_t *) &b_x[ 8u]);
	t_b8_2 = *((uint64_t *) &b_x[16u]);
	t_b4   = *((uint32_t *) &b_x[24u]);

	*((uint64_t *) &b_x[ 0u]) = t_a8_0;
	*((uint64_t *) &b_x[ 8u]) = t_a8_1;
	*((uint64_t *) &b_x[16u]) = t_a8_2;
	*((uint32_t *) &b_x[24u]) = t_a4;
	*((uint64_t *) &a_x[ 0u]) = t_b8_0;
	*((uint64_t *) &a_x[ 8u]) = t_b8_1;
	*((uint64_t *) &a_x[16u]) = t_b8_2;
	*((uint32_t *) &a_x[24u]) = t_b4;

	return;

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_a4_3, t_a4_4, t_a4_5, t_a4_6;
	uint32_t t_b4_0, t_b4_1, t_b4_2, t_b4_3, t_b4_4, t_b4_5, t_b4_6;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a4_3 = *((uint32_t *) &a_x[12u]);
	t_a4_4 = *((uint32_t *) &a_x[16u]);
	t_a4_5 = *((uint32_t *) &a_x[20u]);
	t_a4_6 = *((uint32_t *) &a_x[24u]);
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b4_3 = *((uint32_t *) &b_x[12u]);
	t_b4_4 = *((uint32_t *) &b_x[16u]);
	t_b4_5 = *((uint32_t *) &b_x[20u]);
	t_b4_6 = *((uint32_t *) &b_x[24u]);

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	*((uint32_t *) &b_x[12u]) = t_a4_3;
	*((uint32_t *) &b_x[16u]) = t_a4_4;
	*((uint32_t *) &b_x[20u]) = t_a4_5;
	*((uint32_t *) &b_x[24u]) = t_a4_6;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	*((uint32_t *) &a_x[12u]) = t_b4_3;
	*((uint32_t *) &a_x[16u]) = t_b4_4;
	*((uint32_t *) &a_x[20u]) = t_b4_5;
	*((uint32_t *) &a_x[24u]) = t_b4_6;

	return;

#else
	SWAP_X_BODY(28u, 1u);
#endif
}

QSORT_SWAP_ABI
static void
swap_32a1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{
#if defined(QSORT_ARCH_UNALIGNED_8_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint64_t t_a8_0, t_a8_1, t_a8_2, t_a8_3;
	uint64_t t_b8_0, t_b8_1, t_b8_2, t_b8_3;

	t_a8_0 = *((uint64_t *) &a_x[ 0u]);
	t_a8_1 = *((uint64_t *) &a_x[ 8u]);
	t_a8_2 = *((uint64_t *) &a_x[16u]);
	t_a8_3 = *((uint64_t *) &a_x[24u]);
	t_b8_0 = *((uint64_t *) &b_x[ 0u]);
	t_b8_1 = *((uint64_t *) &b_x[ 8u]);
	t_b8_2 = *((uint64_t *) &b_x[16u]);
	t_b8_3 = *((uint64_t *) &b_x[24u]);

	*((uint64_t *) &b_x[ 0u]) = t_a8_0;
	*((uint64_t *) &b_x[ 8u]) = t_a8_1;
	*((uint64_t *) &b_x[16u]) = t_a8_2;
	*((uint64_t *) &b_x[24u]) = t_a8_3;
	*((uint64_t *) &a_x[ 0u]) = t_b8_0;
	*((uint64_t *) &a_x[ 8u]) = t_b8_1;
	*((uint64_t *) &a_x[16u]) = t_b8_2;
	*((uint64_t *) &a_x[24u]) = t_b8_3;

	return;

#elif defined(QSORT_ARCH_UNALIGNED_4_OK)

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	uint32_t t_a4_0, t_a4_1, t_a4_2, t_a4_3, t_a4_4, t_a4_5, t_a4_6,
		t_a4_7;
	uint32_t t_b4_0, t_b4_1, t_b4_2, t_b4_3, t_b4_4, t_b4_5, t_b4_6,
		t_b4_7;

	t_a4_0 = *((uint32_t *) &a_x[ 0u]);
	t_a4_1 = *((uint32_t *) &a_x[ 4u]);
	t_a4_2 = *((uint32_t *) &a_x[ 8u]);
	t_a4_3 = *((uint32_t *) &a_x[12u]);
	t_a4_4 = *((uint32_t *) &a_x[16u]);
	t_a4_5 = *((uint32_t *) &a_x[20u]);
	t_a4_6 = *((uint32_t *) &a_x[24u]);
	t_a4_7 = *((uint32_t *) &a_x[28u]);
	t_b4_0 = *((uint32_t *) &b_x[ 0u]);
	t_b4_1 = *((uint32_t *) &b_x[ 4u]);
	t_b4_2 = *((uint32_t *) &b_x[ 8u]);
	t_b4_3 = *((uint32_t *) &b_x[12u]);
	t_b4_4 = *((uint32_t *) &b_x[16u]);
	t_b4_5 = *((uint32_t *) &b_x[20u]);
	t_b4_6 = *((uint32_t *) &b_x[24u]);
	t_b4_7 = *((uint32_t *) &b_x[28u]);

	*((uint32_t *) &b_x[ 0u]) = t_a4_0;
	*((uint32_t *) &b_x[ 4u]) = t_a4_1;
	*((uint32_t *) &b_x[ 8u]) = t_a4_2;
	*((uint32_t *) &b_x[12u]) = t_a4_3;
	*((uint32_t *) &b_x[16u]) = t_a4_4;
	*((uint32_t *) &b_x[20u]) = t_a4_5;
	*((uint32_t *) &b_x[24u]) = t_a4_6;
	*((uint32_t *) &b_x[28u]) = t_a4_7;
	*((uint32_t *) &a_x[ 0u]) = t_b4_0;
	*((uint32_t *) &a_x[ 4u]) = t_b4_1;
	*((uint32_t *) &a_x[ 8u]) = t_b4_2;
	*((uint32_t *) &a_x[12u]) = t_b4_3;
	*((uint32_t *) &a_x[16u]) = t_b4_4;
	*((uint32_t *) &a_x[20u]) = t_b4_5;
	*((uint32_t *) &a_x[24u]) = t_b4_6;
	*((uint32_t *) &a_x[28u]) = t_b4_7;

	return;

#else
	SWAP_X_BODY(32u, 1u);
#endif
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_SWAP_A1__C_H */
