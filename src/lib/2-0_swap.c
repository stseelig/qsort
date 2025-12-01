/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap.c                                                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <stddef.h>
#include <stdint.h>

#include "./common.h"
#include "./qsort.h"
#include "./swap.h"

#include "./swap/align.h"

/* //////////////////////////////////////////////////////////////////////// */

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_1a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_2a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_3a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_4a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_5a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_6a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_7a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_8a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_9a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_10a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_11a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_12a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_13a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_14a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_15a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_16a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_20a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_24a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_28a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_32a1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

/* ------------------------------------------------------------------------ */

#ifdef SWAP_ALIGN_4_VERSIONS

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_4a4(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_8a4(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_12a4(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_16a4(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_20a4(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_24a4(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_28a4(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_32a4(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#endif	/* SWAP_ALIGN_4_VERSIONS */

/* ------------------------------------------------------------------------ */

#ifdef SWAP_ALIGN_8_VERSIONS

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_8a8(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_16a8(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_24a8(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_32a8(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#endif	/* SWAP_ALIGN_8_VERSIONS */

/* ------------------------------------------------------------------------ */

#ifdef SWAP_ALIGN_16_VERSIONS

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_16a16(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#undef a
#undef b
QSORT_SWAP_ABI
static void swap_32a16(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

#endif	/* SWAP_ALIGN_16_VERSIONS */

/* ======================================================================== */

/*@-redef@*/

/*@unchecked@*/
BUILD_HIDDEN
const swap_fnptr swap_a1_table[32u] = {
	swap_1a1  , swap_2a1  , swap_3a1  , swap_4a1  ,
	swap_5a1  , swap_6a1  , swap_7a1  , swap_8a1  ,
	swap_9a1  , swap_10a1 , swap_11a1 , swap_12a1 ,
	swap_13a1 , swap_14a1 , swap_15a1 , swap_16a1 ,
	swap_Na1  , swap_Na1  , swap_Na1  , swap_20a1 ,
	swap_Na1  , swap_Na1  , swap_Na1  , swap_24a1 ,
	swap_Na1  , swap_Na1  , swap_Na1  , swap_28a1 ,
	swap_Na1  , swap_Na1  , swap_Na1  , swap_32a1
};

#ifdef SWAP_ALIGN_4_VERSIONS
/*@unchecked@*/
BUILD_HIDDEN
const swap_fnptr swap_a4_table[8u] = {
	swap_4a4  , swap_8a4  , swap_12a4 , swap_16a4 ,
	swap_20a4 , swap_24a4 , swap_28a4 , swap_32a4
};
#endif	/* SWAP_ALIGN_4_VERSIONS */

#ifdef SWAP_ALIGN_8_VERSIONS
/*@unchecked@*/
BUILD_HIDDEN
const swap_fnptr swap_a8_table[4u]  = {
	swap_8a8  , swap_16a8 , swap_24a8 , swap_32a8
};
#endif /* SWAP_ALIGN_8_VERSIONS */

#ifdef SWAP_ALIGN_16_VERSIONS
/*@unchecked@*/
BUILD_HIDDEN
const swap_fnptr swap_a16_table[2u] = {
	swap_16a16, swap_32a16
};
#endif	/* SWAP_ALIGN_16_VERSIONS */

/*@=redef@*/

/* //////////////////////////////////////////////////////////////////////// */

#if !defined(QSORT_OPT_NO_ASM) \
 && (defined(__powerpc__) && defined(__GNUC__) && defined(__unix__))
#include "./swap/swap_a1.ppc32-base.ppc32-generic.h"

#elif !defined(QSORT_OPT_NO_ASM) \
 && (defined(__x86_64__) && defined(__GNUC__)) \
 && (defined(__unix__) || defined(HAS_ATTRIBUTE_SYSV_ABI))
#include "./swap/swap_a1.amd64-multi.sysv-generic.h"

#else
#include "./swap/swap_a1._C.h"

#endif	/* QSORT_OPT_NO_ASM */

/* ------------------------------------------------------------------------ */

#ifdef SWAP_ALIGN_4_VERSIONS

#include "./swap/swap_a4._C.h"

#endif	/* SWAP_ALIGN_4_VERSIONS */

/* ------------------------------------------------------------------------ */

#ifdef SWAP_ALIGN_8_VERSIONS

#if !defined(QSORT_OPT_NO_ASM) \
 && (defined(__powerpc__) && defined(__GNUC__) && defined(__unix__))
#include "./swap/swap_a8.ppc32-base.ppc32-generic.h"

#else
#include "./swap/swap_a8._C.h"

#endif	/* QSORT_OPT_NO_ASM */

#endif	/* SWAP_ALIGN_8_VERSIONS */

/* ------------------------------------------------------------------------ */

#ifdef SWAP_ALIGN_16_VERSIONS

#if !defined(QSORT_OPT_NO_ASM) \
 && (defined(__powerpc__) && defined(__GNUC__) && defined(__unix__))
#include "./swap/swap_a16.ppc32-altivec.ppc32-generic.h"

#else
#include "./swap/swap_a16._C.h"

#endif	/* QSORT_OPT_NO_ASM */

#endif	/* SWAP_ALIGN_16_VERSIONS */

/* ======================================================================== */

/*@-redef@*/
BUILD_HIDDEN
THREAD_LOCAL size_t gt_swap_N_size = SIZE_MAX;
/*@=redef@*/

BUILD_HIDDEN
FLATTEN
QSORT_SWAP_ABI
void
swap_Na1(void *const RESTRICT a, void *const RESTRICT b)
/*@modifies	*a,
		*b
@*/
{

	uint8_t *const RESTRICT a_x = a;
	uint8_t *const RESTRICT b_x = b;
	/* * */
	size_t n = gt_swap_N_size;
	size_t i = 0;

	ASSUME(n > SIZE_C(16));

	#pragma nounroll
	for ( ; n >= SIZE_C(32); n -= 32u, i += 32u ){
		swap_32a1(&a_x[i], &b_x[i]);
	}
	#pragma nounroll
	for ( ; n >= SIZE_C( 8); n -=  8u, i +=  8u ){
		swap_8a1( &a_x[i], &b_x[i]);
	}
	#pragma nounroll
	for ( ; n >= SIZE_C( 2); n -=  2u, i +=  2u ){
		swap_2a1( &a_x[i], &b_x[i]);
	}
	if ( n != 0 ){
		swap_1a1( &a_x[i], &b_x[i]);
	}
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
