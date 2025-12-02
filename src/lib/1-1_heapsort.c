/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/heapsort.c                                                         //
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

/* //////////////////////////////////////////////////////////////////////// */

/* returns the index of the last (largest index) non-leaf node */
#define HEAP_IDX_LASTBRANCH(x_nmemb)	(((x_nmemb) / 2u) - 1u)

/* returns the would-be index of a node's left child */
#define HEAP_IDX_LEFTCHILD(x_parent)	((2u * (x_parent)) + 1u)

/* returns a pointer to the last node */
#define HEAP_PTR_LASTNODE(x_base, x_nmemb, x_size) ( \
	&(x_base)[((x_nmemb) - 1u) * (x_size)] \
)

/* ======================================================================== */

#undef base
ALWAYS_INLINE void heap_heapify(
	uint8_t *RESTRICT base, size_t, size_t,
	const struct QSortFnPtrs *RESTRICT
)
/*@modifies	*base@*/
;

#undef base
ALWAYS_INLINE void heap_sort(
	uint8_t *RESTRICT base, size_t, size_t,
	const struct QSortFnPtrs *RESTRICT
)
/*@modifies	*base@*/
;

#undef node
ALWAYS_INLINE void heap_siftdown(
	uint8_t *, size_t, size_t,
	const struct QSortFnPtrs *RESTRICT , struct Item node
)
/*@modifies	*node.ptr@*/
;

/* //////////////////////////////////////////////////////////////////////// */

/* heapsort */
BUILD_HIDDEN
QSORT_SWAP_ABI
NOINLINE void
qsort_heapsort(
	uint8_t *const RESTRICT base, const size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp
)
/*@modifies	*base@*/
{
	/* assuming that: (ASSUME() may make things slower)
	       - (nmemb > SIZE_C(1))
	       - (size  > 0)
	       - '(nmemb * size)' will not overflow
	*/

	heap_heapify(base, nmemb, size, qsfp);
	heap_sort(base, nmemb, size, qsfp);

	return;
}

/* ------------------------------------------------------------------------ */

/* transform an (unsorted) array into a binary max-heap */
ALWAYS_INLINE void
heap_heapify(
	uint8_t *const RESTRICT base, const size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp
)
/*@modifies	*base@*/
{
	struct Item node = ITEM_BUILD(base, HEAP_IDX_LASTBRANCH(nmemb), size);

	ASSUME(nmemb > SIZE_C(1));

	/* walk the array backwards from the last branch to index-0 */
	do {	heap_siftdown(base, nmemb, size, qsfp, node);
		node.ptr = (uint8_t *) (((uintptr_t) node.ptr) - size);
	}
	while ( node.idx-- != 0 );

	return;
}

/* transform a binary max-heap into a sorted array */
ALWAYS_INLINE void
heap_sort(
	uint8_t *const RESTRICT base, size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp
)
/*@modifies	*base@*/
{
	const struct Item root  = ITEM_BUILD(base, SIZE_C(0), size);
	const struct Item left  = ITEM_BUILD(base, SIZE_C(1), size);
	const struct Item right = ITEM_BUILD(base, SIZE_C(2), size);
	/* * */
	struct Item branch;
	uintptr_t last = (uintptr_t) HEAP_PTR_LASTNODE(base, nmemb, size);
	int cmp;

	ASSUME(nmemb > SIZE_C(1));

	/* 2x sift loop (I tried a 3x sift loop, but it was slower) */
	while ( nmemb > SIZE_C(3) ){
		QSFP_SWAP((void *) last, base);

		cmp    = QSFP_COMPAR(left.ptr, right.ptr);
		branch = (cmp >= 0 ? left : right);
		last  -= size;
		QSFP_SWAP((void *) last, branch.ptr);

		nmemb -= 2u;
		heap_siftdown(base, nmemb, size, qsfp, branch);
		heap_siftdown(base, nmemb, size, qsfp, root);
		last  -= size;
	}

	/* tail: 2 or 3 items left */
	QSFP_SWAP((void *) last, base);
	if ( (last -= size) != (uintptr_t) base ){
		if ( QSFP_COMPAR((void *) last, base) < 0 ){
			QSFP_SWAP((void *) last, base);
		}
	}
	return;
}

/* (partially) restore a binary max-heap by sifting a node down */
ALWAYS_INLINE void
heap_siftdown(
	uint8_t *const base, const size_t nmemb, const size_t size,
	const struct QSortFnPtrs *const RESTRICT qsfp, struct Item node
)
/*@modifies	*node.ptr@*/
{
	const size_t nmemb_0 = nmemb - 1u;
	/* * */
	uint8_t *root_ptr    = node.ptr;
	uint8_t *twin_ptr;

	ASSUME(nmemb > 0);

	for(;;) {
		node.idx = HEAP_IDX_LEFTCHILD(node.idx);
		node.ptr = &base[node.idx * size];

		/* break at either a leaf node or an only child (last node) */
		if ( node.idx >  nmemb_0 ){
			break;
		}
		if ( node.idx == nmemb_0 ){
			if ( QSFP_COMPAR(node.ptr, root_ptr) > 0 ){
				QSFP_SWAP(node.ptr, root_ptr);
			}
			break;
		}

		twin_ptr = &node.ptr[size];
		if ( QSFP_COMPAR(twin_ptr, root_ptr) > 0 ){
			if ( QSFP_COMPAR(twin_ptr, node.ptr) >= 0 ){
				node.ptr  = twin_ptr;
				node.idx += 1u;
			}
		}
		else {	if ( QSFP_COMPAR(node.ptr, root_ptr) <= 0 ){
				break;
			}
		}
		QSFP_SWAP(node.ptr, root_ptr);
		root_ptr = node.ptr;
	}
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
