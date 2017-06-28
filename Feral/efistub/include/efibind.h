/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

/*
	Bindings to relevant platforms.
	Ensure that correct definitions go into correct sections.
	(Aarch64, x86-64, etc.)
 */

#ifndef _LIBRE_EFI_BIND_INCLUDE_
#define _LIBRE_EFI_BIND_INCLUDE_

#if defined(__x86_64__) || defined(__i386__)
typedef signed char       int8_t;
typedef unsigned char     uint8_t;
typedef signed short      int16_t;
typedef unsigned short    uint16_t;
typedef signed int        int32_t;
typedef unsigned int      uint32_t;
typedef signed long int   int64_t;
typedef unsigned long int uint64_t;

typedef int64_t INTN;
typedef uint64_t UINTN;

#define BITSHIFT_LEFT_NUM 63
#define BAD_POINTER 0xFBFBFBFBFBFBFBFB
#define MAX_ADDRESS 0xFFFFFFFFFFFFFFFF

#define MIN_ALIGNMENT_SIZE 4

#if defined(HAVE_USE_MS_ABI)		//Unsure if we still need this, since clang can compile PE fine.
	#define uefi_call_wrapper(func, va_bum, ...) func(__VA_ARGS__)
#else

//Macro magic!!!!
#define __VA_NARG__(...)	\
	__VA_NARG_(_0, ## __VA_ARGS__, __RSEQ_N())

#define __VA_NARG_(...)	\
	__VA_ARG_N(__VA_ARGS__)

#define __VA_ARG_N(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,N,...) N
#define __RSEQ_N() 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
	

#define __VA_ARG_NSUFFIX__(prefix, ...)	\
	__VA_ARG_NSUFFIX_N(prefix, __VA_NARG__(__VA_ARGS__))

#define __VA_ARG_NSUFFIX_N(prefix, nargs)	\
	__VA_ARG_NSUFFIX_N_(prefix, nargs)


#define __VA_ARG_NSUFFIX_N_(prefix, nargs)	\
	prefix ## nargs


#endif
















#if defined(__arm__) || defined(__aarch64__)
//TODO...
#endif















#ifndef __WCHAR_TYPE__
#define __WCHAR_TYPE__ int16_t
#endif

#define VOLATILE volatile
#endif

#define TRUE  ((uint8_t)1)
#define FALSE ((uint8_t)0)

typedef uint64_t UINT64;
typedef int64_t   INT64;

typedef uint32_t UINT32;
typedef int32_t   INT32;

typedef uint16_t UINT16;
typedef int16_t   INT16;

typedef uint8_t   UINT8;
typedef int8_t     INT8;

typedef __WCHAR_TYPE__ WCHAR;
typedef WCHAR CHAR16;
typedef uint8_t CHAR8;
typedef UINT8 BOOLEAN;


#undef VOID
#define VOID void

#define EFI_ERROR_MASK 0x8000000000000000

#define EFIERR(v) (EFI_ERROR_MASK | v)
#define EFIERR_OEM(v) (0xC000000000000000 | a)

#define BREAKPOINT() while(TRUE);

#define EFI_SIGNATURE_16(A, B) ((A) | (B << 8))
#define EFI_SIGNATURE_32(A, B, C, D) (EFI_SIGNATURE_16(A, B) | (EFI_SIGNATURE_16(C, D) << 16))
#define EFI_SIGNATURE_64(A,B,C,D,E,F,G,H) (EFI_SIGNATURE_32(A,B,C,D) | ((UINT64)(EFI_SIGNATURE_32(E,F,G,H)) << 32))

#endif
