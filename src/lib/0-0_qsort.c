/* ///////////////////////////////////////////////////////////////////////////
//                                                                          //
// qsort/qsort.c                                                            //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
// Copyright (C) 2025, Shane Seelig                                         //
// SPDX-License-Identifier: GPL-3.0-or-later                                //
//                                                                          //
/////////////////////////////////////////////////////////////////////////// */

#include "./common.h"

/* //////////////////////////////////////////////////////////////////////// */

#if 0	/* arch-type */

/* ------------------------------------------------------------------------ */

/* arm */

#elif (defined(__aarch__) && defined(__unix__)) \
 && (defined(__GNUC__) && defined(HAS_ATTRIBUTE_NAKED))
#include "./qsort/qsort.arm32-base.aapcs32-generic.h"

#elif (defined(__aarch64__) && defined(__unix__)) \
 && (defined(__GNUC__) && defined(HAS_ATTRIBUTE_NAKED))
#include "./qsort/qsort.arm64-base.aapcs64-generic.h"

/* ------------------------------------------------------------------------ */

/* ppc */

#elif ((defined(__powerpc__) || defined(__powerpc64__)) \
 && defined(__unix__)) \
 && (defined(__GNUC__) && defined(HAS_ATTRIBUTE_NAKED))
#include "./qsort/qsort.ppc-base.ppc-generic.h"

/* ------------------------------------------------------------------------ */

/* x86 */

#elif (defined(__i386__) && (defined(__unix__) || defined(__WIN32__))) \
 && (defined(__GNUC__) && defined(HAS_ATTRIBUTE_NAKED))
#include "./qsort/qsort.x86-multi.cdecl-generic.h"

#elif (defined(__x86_64__) && defined(__unix__)) \
 && (defined(__GNUC__) && defined(HAS_ATTRIBUTE_NAKED))
#include "./qsort/qsort.amd64-base.sysv-generic.h"

#elif (defined(__x86_64__) && defined(__WIN64__)) \
 && (defined(__GNUC__) && defined(HAS_ATTRIBUTE_NAKED))
#include "./qsort/qsort.amd64-base.msx64-generic.h"

/* ------------------------------------------------------------------------ */

#else
#include "./qsort/qsort._C.h"

#endif	/* arch-type */

/* EOF //////////////////////////////////////////////////////////////////// */
