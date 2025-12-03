#ifndef H_QSORT_QSORT_H
#define H_QSORT_QSORT_H
/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/qsort.h                                                            //
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

/* //////////////////////////////////////////////////////////////////////// */

/* limits are optimized for the "nice" sizes */

#define QSORT_SHELLSORT_MAX_NMEMB	SIZE_C(  56)
#define QSORT_HEAPSORT_MAX_BYTES	SIZE_C(8192)

/* ------------------------------------------------------------------------ */

/**@fn QSORT_SHELLSORT_CHECK
 * @return whether shellsort should be used
 *
 * @param nmemb - number of items in the array
 * @param size  - (unused)
**/
#define QSORT_SHELLSORT_CHECK(x_nmemb, x_size)	( \
	(x_nmemb) <= QSORT_SHELLSORT_MAX_NMEMB \
)

/**@fn QSORT_HEAPSORT_CHECK
 * @return whether heapsort should be used
 *
 * @param nmemb - number of items in the array
 * @param size  - size of each array item
**/
#define QSORT_HEAPSORT_CHECK(x_nmemb, x_size)	( \
	(x_nmemb) * (x_size) <= QSORT_HEAPSORT_MAX_BYTES \
)

/* //////////////////////////////////////////////////////////////////////// */

typedef int (*x_compar_fnptr)(const void *, const void *, void *);
typedef /*@observer@*/ x_compar_fnptr			compar_fnptr;

typedef void (*x_swap_fnptr)(void *RESTRICT, void *RESTRICT);
typedef /*@observer@*/ QSORT_SWAP_ABI x_swap_fnptr	swap_fnptr;

struct QSortCompar {
	compar_fnptr	fn;	/* may not be PURE */
	/*@temp@*/ /*@null@*/
	void		*arg;
};

struct QSortFnPtrs {
	struct QSortCompar	compar;
	swap_fnptr		swap;
};

typedef void (*x_sort_fnptr)(
	uint8_t *RESTRICT, size_t, size_t, const struct QSortFnPtrs *RESTRICT
);
typedef /*@observer@*/ QSORT_SWAP_ABI x_sort_fnptr	sort_fnptr;

/* ------------------------------------------------------------------------ */

/**@fn QSFP_COMPAR
 * @brief wrapper for the indirect call to 'compar'
 *
 * @param a - pointer to the first item
 * @param b - pointer to the second item
**/
#define QSFP_COMPAR(x_a, x_b) ( \
	qsfp->compar.fn((x_a), (x_b), qsfp->compar.arg) \
)

/**@fn QSFP_SWAP
 * @brief wrapper for the indirect call to 'swap'
 *
 * @param a - pointer to the first item
 * @param b - pointer to the second item
**/
#define QSFP_SWAP(x_a, x_b) { \
	/*@-noeffectuncon@*/ \
	qsfp->swap((x_a), (x_b)); \
	/*@=noeffectuncon@*/ \
}

/* ======================================================================== */

struct Item {
	/*@temp@*/
	uint8_t	*ptr;
	size_t	idx;
};

/* ------------------------------------------------------------------------ */

/**@fn ITEM_BUILD
 * @return constructed array item
 *
 * @note This is a C89 -Wpedantic initializer workaround.
 *
 * @param base - pointer to the beginning of the array
 * @param idx  - index of the item in the array
 * @param size - size of an array item
**/
CONST
ALWAYS_INLINE struct Item
ITEM_BUILD(uint8_t *const base, const size_t idx, const size_t size)
/*@*/
{
	struct Item retval;

	retval.ptr = &base[idx * size];
	retval.idx = idx;

	return retval;
}

/**@fn ITEM_NEXT
 * @brief puts the item after 'src' into 'dest'
 *
 * @note Using a pure/const inline function (fp-style) tested slower.
 *
 * @param dest - destination item
 * @param src  - source item
 * @param size - size of an array item
**/
#define ITEM_NEXT(x_dest, x_src, x_size) { \
	(x_dest).ptr = &(x_src).ptr[(x_size)]; \
	(x_dest).idx = (x_src).idx + 1u; \
}

/**@fn ITEM_PREV
 * @brief puts the item before 'src' into 'dest'
 *
 * @note Using a pure/const inline function (fp-style) tested slower.
 *
 * @param dest - destination item
 * @param src  - source item
 * @param size - size of an array item
**/
#define ITEM_PREV(x_dest, x_src, x_size) { \
	(x_dest).ptr = (uint8_t *) (((uintptr_t) (x_src).ptr) - (x_size)); \
	(x_dest).idx = (x_src).idx - 1u; \
}

/* //////////////////////////////////////////////////////////////////////// */

/*@-redef@*/
BUILD_HIDDEN BUILD_EXTERN
THREAD_LOCAL size_t gt_swap_N_size;
/*@=redef@*/

/* //////////////////////////////////////////////////////////////////////// */

#undef base
/*@external@*/ /*@unused@*/
extern void qsort_r(
	void *base, size_t, size_t,
	int (*)(const void *, const void *, void *), /*@null@*/ void *
)
/*@globals	gt_swap_N_size@*/
/*@modifies	*base,
		gt_swap_N_size
@*/
;

/* ======================================================================== */

#undef base
BUILD_HIDDEN BUILD_EXTERN
QSORT_SWAP_ABI
NOINLINE void qsort_shellsort(
	uint8_t *RESTRICT base, size_t, size_t,
	const struct QSortFnPtrs *RESTRICT
)
/*@modifies	*base@*/
;

#undef base
BUILD_HIDDEN BUILD_EXTERN
QSORT_SWAP_ABI
NOINLINE void qsort_heapsort(
	uint8_t *RESTRICT base, size_t, size_t,
	const struct QSortFnPtrs *RESTRICT
)
/*@modifies	*base@*/
;

#undef base
BUILD_HIDDEN BUILD_EXTERN
QSORT_SWAP_ABI
NOINLINE void qsort_quicksort(
	uint8_t *RESTRICT base, size_t, size_t,
	const struct QSortFnPtrs *RESTRICT
)
/*@modifies	*base@*/
;

/* EOF //////////////////////////////////////////////////////////////////// */
#endif	/* H_QSORT_QSORT_H */
