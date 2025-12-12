/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/test_perf.c                                                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* ======================================================================== */

/* qsort_r: stuffing a size_t into the 'arg' pointer */
#if UINTPTR_MAX < SIZE_MAX
#error "UINTPTR_MAX < SIZE_MAX"
#endif

/* //////////////////////////////////////////////////////////////////////// */

#if SIZE_MAX == UINT16_MAX
#define SIZE_C(x_x)	UINT16_C(x_x)
#elif SIZE_MAX == UINT32_MAX
#define SIZE_C(x_x)	UINT32_C(x_x)
#elif SIZE_MAX == UINT64_MAX
#define SIZE_C(x_x)	UINT64_C(x_x)
#else
#error "SIZE_MAX"
#endif	/* SIZE_MAX */

#if defined(__clang__)
#define PRAGMA_NOUNROLL		_Pragma("nounroll")
#elif defined(__GNUC__)
#define PRAGMA_NOUNROLL		_Pragma("GCC unroll(0)")
#else
#define PRAGMA_NOUNROLL
#endif	/* PRAGMA_NOUNROLL */

#ifndef __GNUC__
/*@-namechecks@*/
#define __attribute__(x_x)
/*@=namechecks@*/
#endif	/* __GNUC__ */

/* //////////////////////////////////////////////////////////////////////// */

#undef base
extern void qsort_r(
	void *base, size_t, size_t,
	int(*)(const void *, const void *, void *), /*@null@*/ void *
)
/*@modifies	*base@*/
;

/*@only@*/ /*@null@*/
extern void *aligned_alloc(size_t, size_t)
/*@globals	internalState@*/
/*@modifies	internalState@*/
;

/* ======================================================================== */

static void test_multi(size_t, size_t, size_t ,size_t)
/*@globals	fileSystem,
		internalState
@*/
/*@modifies	fileSystem,
		internalState
@*/
;

static void test_single(size_t, size_t, size_t)
/*@globals	fileSystem,
		internalState
@*/
/*@modifies	fileSystem,
		internalState
@*/
;

static size_t size_aligned_extra(size_t, size_t, size_t) /*@*/;

#undef base
static void array_init(uint8_t *base, size_t)
/*@globals	internalState@*/
/*@modifies	internalState,
		*base
@*/
;

static int compar(const void *, const void *, void *) /*@*/;

/*@maynotreturn@*/
static void array_sort_check(const uint8_t *, size_t, size_t)
/*@globals	fileSystem@*/
/*@modifies	fileSystem@*/
;

/* //////////////////////////////////////////////////////////////////////// */

int
main(void)
/*@globals	fileSystem,
		internalState
@*/
/*@modifies	fileSystem,
		internalState
@*/
{
	/*@unused@*/ __attribute__((unused))
	static const size_t nice_size_table[] = {
		 SIZE_C( 1), SIZE_C( 2), SIZE_C( 3), SIZE_C( 4), SIZE_C( 5),
		 SIZE_C( 6), SIZE_C( 7), SIZE_C( 8), SIZE_C( 9), SIZE_C(10),
		 SIZE_C(11), SIZE_C(12), SIZE_C(13), SIZE_C(14), SIZE_C(15),
		 SIZE_C(16), SIZE_C(20), SIZE_C(24), SIZE_C(28), SIZE_C(32),
		 0
	};
	/*@unused@*/ __attribute__((unused))
	static const size_t pow2_size_table[] = {
		SIZE_C(  1), SIZE_C(  2), SIZE_C(  4), SIZE_C(  8),
		SIZE_C( 16), SIZE_C( 32), SIZE_C( 64), SIZE_C(128),
		0
	};
	size_t size;
	/*@unused@*/ __attribute__((unused))
	unsigned int i;

	srand(0x6969u);

#if 0
	PRAGMA_NOUNROLL
	for ( size = SIZE_C(1); size <= SIZE_C(75); ++size ){
#else
	PRAGMA_NOUNROLL
	for ( i = 0; 0==0 /* gcc */; ++i ){
#if 1
		size = nice_size_table[i];
#else
		size = pow2_size_table[i];
#endif
		if ( size == 0 ){
			break;
		}
#endif
		test_multi(size, SIZE_C(1), SIZE_C(100), SIZE_C(1));

		test_multi(size, SIZE_C(100), SIZE_C(10000), SIZE_C(100));

		test_multi(
			size, SIZE_C(10000), SIZE_C(100000), SIZE_C(10000)
		);
	}
	return 0;
}

/* ------------------------------------------------------------------------ */

static void
test_multi(
	const size_t size, const size_t start, const size_t limit,
	const size_t increment
)
/*@globals	fileSystem,
		internalState
@*/
/*@modifies	fileSystem,
		internalState
@*/
{
	size_t nmemb, align;

	PRAGMA_NOUNROLL
	for ( nmemb = start; nmemb <= limit; nmemb += increment ){
		PRAGMA_NOUNROLL
		for ( align = SIZE_C(1); align <= SIZE_C(32); align *= 2u ){
			test_single(nmemb, size, align);
		}
	}
	return;
}

static void
test_single(const size_t nmemb, const size_t size, const size_t align)
/*@globals	fileSystem,
		internalState
@*/
/*@modifies	fileSystem,
		internalState
@*/
{
	uint8_t *ptr, *base;

#if 0
	(void) printf(" size: %3zu, nmemb: %7zu, align: %2zu\r",
		size, nmemb, align
	);
	(void) fflush(stdout);
#endif

	/* each test gets its own allocation for valgrind */
	ptr  = aligned_alloc(align, size_aligned_extra(nmemb, size, align));
	assert(ptr != NULL);
	base = &ptr[align];

	array_init(base, nmemb * size);
	qsort_r(base, nmemb, size, compar, (void *) ((uintptr_t) size));
	array_sort_check(base, nmemb, size);

	free(ptr);

	return;
}

static size_t
size_aligned_extra(const size_t nmemb, const size_t size, const size_t align)
/*@*/
{
	const size_t size_a = (nmemb + (align / size) + 1u) * size;
	const size_t mod    = size_a % align;

	return size_a + (mod != 0 ? align - mod : 0);
}

static void
array_init(uint8_t *const base, const size_t size_array)
/*@globals	internalState@*/
/*@modifies	internalState,
		*base
@*/
{
	int r;
	size_t i;

	for ( i = 0; i + (sizeof r) <= size_array; i += (sizeof r) ){
		r = rand();
		(void) memcpy(&base[i], &r, (sizeof r));
	}
	if ( i < size_array ){
		r = rand();
		(void) memcpy(&base[i], &r, size_array - i);
	}
	return;
}

static int
compar(const void *a, const void *b, void *arg)
/*@*/
{
	return memcmp(a, b, (size_t) ((uintptr_t) arg));
}

/*@maynotreturn@*/
static void
array_sort_check(
	const uint8_t *const base, const size_t nmemb, const size_t size
)
/*@globals	fileSystem@*/
/*@modifies	fileSystem@*/
{
	int cmp;
	size_t i;

	for ( i = 0; i + 1u < nmemb; ++i ){
		cmp = memcmp(&base[i * size], &base[(i + 1u) * size], size);
		if ( cmp > 0 ){
			(void) printf("\n!!!   fail   !!!\n");
			abort();
		}
	}
	return;
}

/* EOF //////////////////////////////////////////////////////////////////// */
