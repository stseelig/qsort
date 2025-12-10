/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/test_abi.c                                                         //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* //////////////////////////////////////////////////////////////////////// */

static int compare(const void *, const void *) /*@*/;

/* //////////////////////////////////////////////////////////////////////// */

int
main(void)
/*@globals	fileSystem@*/
/*@modifies	fileSystem@*/
{
	const char answer[] = "122333444455555666666777777788888888999999999";
	/* * */
	char test_array[]   = "895748759585671537882963784968349694789296967";

	#define ARRAY_SIZE	((sizeof test_array) - sizeof test_array[0])

	(void) puts(test_array);
	qsort(test_array, ARRAY_SIZE, sizeof test_array[0], compare);
	(void) puts(test_array);

	return (int) (memcmp(answer, test_array, ARRAY_SIZE) != 0);
}

/* ------------------------------------------------------------------------ */

static int
compare(const void *const a, const void *const b)
/*@*/
{
	return memcmp(a, b, sizeof(char));
}

/* EOF //////////////////////////////////////////////////////////////////// */
