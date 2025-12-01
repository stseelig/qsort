#ifndef H_QSORT_SWAP_H
#define H_QSORT_SWAP_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/swap.h                                                             //
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

#include "./swap/align.h"

/* ======================================================================== */

#ifdef QSORT_ARCH_ALIGN_4_MATTERS
#define SWAP_ALIGN_4_VERSIONS
#endif	/* QSORT_ARCH_ALIGN_4_MATTERS */

#ifdef QSORT_ARCH_ALIGN_8_MATTERS
#define SWAP_ALIGN_8_VERSIONS
#endif	/* QSORT_ARCH_ALIGN_8_MATTERS */

#ifdef QSORT_ARCH_ALIGN_16_MATTERS
#define SWAP_ALIGN_16_VERSIONS
#endif	/* QSORT_ARCH_ALIGN_16_MATTERS */

/* //////////////////////////////////////////////////////////////////////// */

#define SWAP_A1_NMEMB	SIZE_C(32)

/* ======================================================================== */

/*@-redef@*/

/*@unchecked@*/
BUILD_HIDDEN BUILD_EXTERN
const swap_fnptr swap_a1_table[SWAP_A1_NMEMB];

#ifdef SWAP_ALIGN_4_VERSIONS
/*@unchecked@*/
BUILD_HIDDEN BUILD_EXTERN
const swap_fnptr swap_a4_table[SWAP_A1_NMEMB  /  4u];
#endif	/* SWAP_ALIGN_4_VERSIONS */

#ifdef SWAP_ALIGN_8_VERSIONS
/*@unchecked@*/
BUILD_HIDDEN BUILD_EXTERN
const swap_fnptr swap_a8_table[SWAP_A1_NMEMB  /  8u];
#endif /* SWAP_ALIGN_8_VERSIONS */

#ifdef SWAP_ALIGN_16_VERSIONS
/*@unchecked@*/
BUILD_HIDDEN BUILD_EXTERN
const swap_fnptr swap_a16_table[SWAP_A1_NMEMB / 16u];
#endif	/* SWAP_ALIGN_16_VERSIONS */

/*@=redef@*/

/* //////////////////////////////////////////////////////////////////////// */

/*@-redef@*/
BUILD_HIDDEN BUILD_EXTERN
THREAD_LOCAL size_t gt_swap_N_size;
/*@=redef@*/

#undef a
#undef b
BUILD_HIDDEN BUILD_EXTERN
QSORT_SWAP_ABI
void swap_Na1(void *RESTRICT a, void *RESTRICT b)
/*@modifies	*a,
		*b
@*/
;

/* //////////////////////////////////////////////////////////////////////// */

/* returns a function pointer to a 'swap' function */
CONST
ALWAYS_INLINE swap_fnptr
swap_get(UNUSED const uintptr_t base, const size_t size)
/*@*/
{
	swap_fnptr retval;

	ASSUME(size > 0);

	if UNLIKELY ( size > SWAP_A1_NMEMB ){
		retval = swap_Na1;
	}

#ifdef SWAP_ALIGN_16_VERSIONS
	else if ( (size % 16u == 0) && (base % 16u == 0) ){
		retval = swap_a16_table[(size / 16u) - 1u];
	}
#endif	/* SWAP_ALIGN_16_VERSIONS */

#ifdef SWAP_ALIGN_8_VERSIONS
	else if ( (size %  8u == 0) && (base %  8u == 0) ){
		retval = swap_a8_table[(size / 8u) - 1u];
	}
#endif	/* SWAP_ALIGN_8_VERSIONS */

#ifdef SWAP_ALIGN_4_VERSIONS
	else if ( (size %  4u == 0) && (base %  4u == 0) ){
		retval = swap_a4_table[(size / 4u) - 1u];
	}
#endif	/* SWAP_ALIGN_4_VERSIONS */

	else {	retval = swap_a1_table[size - 1u]; }

	return retval;
}

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_SWAP_H */
