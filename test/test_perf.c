
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#if UINTPTR_MAX < SIZE_MAX
#error "UINTPTR_MAX < SIZE_MAX"
#endif

#define X_STRINGIFY(x_x)	#x_x
#define STRINGIFY(x_x)		X_STRINGIFY(x_x)

#if defined(__clang__)
#define PRAGMA_NOUNROLL		_Pragma(STRINGIFY(nounroll))
#elif defined(__GNUC__)
#define PRAGMA_NOUNROLL		_Pragma(STRINGIFY(GCC unroll(0)))
#else
#define PRAGMA_NOUNROLL
#endif	/* PRAGMA_NOUNROLL */

extern void qsort_r(
	void *, size_t, size_t,
	int(*)(const void *, const void *, void *), void *
);

static void
array_init(uint8_t *const base, const size_t size_array)
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

static void
array_sort_check(
	const uint8_t *const base, const size_t nmemb, const size_t size
)
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

static int
compar(const void *a, const void *b, void *arg)
/*@*/
{
	return memcmp(a, b, (size_t) ((uintptr_t) arg));
}

static void
test_single(const size_t nmemb, const size_t size, const size_t align)
{
	uint8_t *ptr, *base;

#if 0
	(void) printf(" size: %3zu, nmemb: %7zu, align: %2zu\r",
		size, nmemb, align
	);
	(void) fflush(stdout);
#endif

	/* each test gets its own allocation for valgrind */
	ptr  = aligned_alloc(align, (nmemb + (align / size) + 1u) * size);
	assert(ptr != NULL);
	base = &ptr[align];

	array_init(base, nmemb * size);
	qsort_r(base, nmemb, size, compar, (void *) ((uintptr_t) size));
	array_sort_check(base, nmemb, size);

	free(ptr);

	return;
}


int
main(void)
{
	__attribute__((unused))
	static const size_t nice_size_table[] = {
		 1u,  2u,  3u,  4u,  5u,  6u,  7u,  8u,
		 9u, 10u, 11u, 12u, 13u, 14u, 15u, 16u,
		20u, 24u, 28u, 32u,
		 0u
	};
	__attribute__((unused))
	static const size_t pow2_size_table[] = {
		1u, 2u, 4u, 8u, 16u, 32u, 64u, 128u,
		0u
	};
	size_t nmemb, size, align;
	__attribute__((unused))
	unsigned int i;

	srand(0x6969u);

#if 0
	PRAGMA_NOUNROLL
	for ( size = 1u; size <= 75u; ++size ){
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

#if 1
		PRAGMA_NOUNROLL
		for ( nmemb = 1u; nmemb <= 100u; ++nmemb ){
			PRAGMA_NOUNROLL
			for ( align = 1u; align <= 32u; align *= 2u ){
				test_single(nmemb, size, align);
			}
		}
#endif
#if 1
		PRAGMA_NOUNROLL
		for ( nmemb = 100u; nmemb <= 10000u; nmemb += 100u ){
			PRAGMA_NOUNROLL
			for ( align = 1u; align <= 32u; align *= 2u ){
				test_single(nmemb, size, align);
			}
		}
#endif
#if 1
		PRAGMA_NOUNROLL
		for ( nmemb = 10000uL; nmemb <= 100000uL; nmemb += 10000uL ){
			PRAGMA_NOUNROLL
			for ( align = 1u; align <= 32u; align *= 2u ){
				test_single(nmemb, size, align);
			}
		}
#endif
	}
	return 0;
}
