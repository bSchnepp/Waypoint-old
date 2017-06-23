/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */

/*
	Bindings for libre-efi to relevant platforms.
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

#define BAD_POINTER 0xFBFBFBFBFBFBFBFB
#define MAX_ADDRESS 0xFFFFFFFFFFFFFFFF

#define MIN_ALIGNMENT_SIZE 4

#if defined(HAVE_USE_MS_ABI)
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


#undef VOID
#define VOID void

#define EFI_ERROR_MASK 0x8000000000000000

#define EFIERR(v) (EFI_ERROR_MASK | v)
#define EFIERR_OEM(v) (0xC000000000000000 | a)

#define BREAKPOINT() while(TRUE);

#define ALIGN_VARIABLE(Value, Adjustment) \
	(UINTN)Adjustment = 0;	\
	UINTN NVal = (UINTN)Value % MIN_ALIGNMENT_SIZE;	\
	if (NVal)	\
	{	\
		(UINTN)Adjustment = MIN_ALIGNMENT_SIZE - (NVal);	\
	}	\
	Value = (UINTN)Value + (UINTN)Adjustment

#define EFI_SIGNATURE_16(A, B) ((A) | (B << 8))
#define EFI_SIGNATURE_32(A, B, C, D) (EFI_SIGNATURE_16(A, B) | (EFI_SIGNATURE_16(C, D) << 16))
#define EFI_SIGNATURE_64(A,B,C,D,E,F,G,H) (EFI_SIGNATURE_32(A,B,C,D) | ((UINT64)(EFI_SIGNATURE_32(E,F,G,H)) << 32))


#define EXPORTAPI
#define BOOTSERVICE
#define RUNTIMESERVICE
#define RUNTIMEFUNCTION

#ifdef HAVE_USE_MS_ABI
	#define EFI_FUNCTION __attribute__((ms_abi))
#else
	#define EFI_FUNCTION
#endif

#ifndef EFIAPI
	#if defined(HAVE_USE_MS_ABI)
		#define EFIAPI __attribute__(ms_abi))
	#else
		#define EFIAPI 
	#endif
#endif

#define RUNTIME_CODE(a)		alloc_text("rtcode", a)

#define BEGIN_RUNTIME_DATA()	data_seg("rtdata")
#define END_RUNTIME_DATA()	data_seg("")
#define MEMORY_FENCE() 

#define EFI_DRIVER_ENTRY_POINT(InitFunction)	\
	UINTN InitializeDriver(VOID* ImageHandle, VOID* SystemTable)	\
	{	\
		return InitFunction(ImageHandle, SystemTable);\
	}	\
	\
	EFI_STATUS efi_main(EFI_HANDLE image, EFI_SYSTEM_TABLE* table) __attribute__((weak, alias \
("InitializeDriver")));

#define LOAD_INTERNAL_DRIVER(_if, type, name, entry)	\
	(_if)->LoadInternal(type, name, entry)


#define INTERFACE_DECL(x) struct x


/* Prototypes of internal stuff to play nice with MSABI. */
UINT64 efi_call0(void* func);
UINT64 efi_call1(void* func, UINT64 arg1);
UINT64 efi_call2(void* func, UINT64 arg1, UINT64 arg2);
UINT64 efi_call3(void* func, UINT64 arg1, UINT64 arg2, UINT64 arg3);
UINT64 efi_call4(void* func, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4);
UINT64 efi_call5(void* func, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4, UINT64 arg5);
UINT64 efi_call6(void* func, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4, UINT64 arg5, 
		 UINT64 arg6);
UINT64 efi_call7(void* func, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4, UINT64 arg5, 
		 UINT64 arg6, UINT64 arg7);
UINT64 efi_call8(void* func, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4, UINT64 arg5, 
		 UINT64 arg6, UINT64 arg7, UINT64 arg8);
UINT64 efi_call9(void* func, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4, UINT64 arg5, 
		 UINT64 arg6, UINT64 arg7, UINT64 arg8, UINT64 arg9);
UINT64 efi_call10(void* func, UINT64 arg1, UINT64 arg2, UINT64 arg3, UINT64 arg4, UINT64 arg5, 
		 UINT64 arg6, UINT64 arg7, UINT64 arg8, UINT64 arg9, UINT64 arg10);


/* Wrapper macros */
#define _cast64_efi_call10(func, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)	\
	efi_call10(func, (UINT64)a1, (UINT64)a2, (UINT64)a3, (UINT64)a4, (UINT64)a5, (UINT64)a6, \
 (UINT64)a7, (UINT64)a8, (UINT64)a9, (UINT64)a10)

#define _cast64_efi_call9(func, a1, a2, a3, a4, a5, a6, a7, a8, a9)	\
	efi_call9(func, (UINT64)a1, (UINT64)a2, (UINT64)a3, (UINT64)a4, (UINT64)a5, (UINT64)a6, \
 (UINT64)a7, (UINT64)a8, (UINT64)a9)

#define _cast64_efi_call8(func, a1, a2, a3, a4, a5, a6, a7, a8)	\
	efi_call8(func, (UINT64)a1, (UINT64)a2, (UINT64)a3, (UINT64)a4, (UINT64)a5, (UINT64)a6, \
 (UINT64)a7, (UINT64)a8)

#define _cast64_efi_call7(func, a1, a2, a3, a4, a5, a6, a7)	\
	efi_call7(func, (UINT64)a1, (UINT64)a2, (UINT64)a3, (UINT64)a4, (UINT64)a5, (UINT64)a6, \
 (UINT64)a7)

#define _cast64_efi_call6(func, a1, a2, a3, a4, a5, a6)	\
	efi_call6(func, (UINT64)a1, (UINT64)a2, (UINT64)a3, (UINT64)a4, (UINT64)a5, (UINT64)a6)

#define _cast64_efi_call5(func, a1, a2, a3, a4, a5)	\
	efi_call5(func, (UINT64)a1, (UINT64)a2, (UINT64)a3, (UINT64)a4, (UINT64)a5)

#define _cast64_efi_call4(func, a1, a2, a3, a4)	\
	efi_call4(func, (UINT64)a1, (UINT64)a2, (UINT64)a3, (UINT64)a4)

#define _cast64_efi_call3(func, a1, a2, a3)	\
	efi_call3(func, (UINT64)a1, (UINT64)a2, (UINT64)a3)

#define _cast64_efi_call2(func, a1, a2)	\
	efi_call2(func, (UINT64)a1, (UINT64)a2)

#define _cast64_efi_call1(func, a1)	\
	efi_call1(func, (UINT64)a1)

#define _cast64_efi_call0(func)	\
	efi_call0(func)

/* UEFI call wrapper, so we can actually use EFI. */
#define uefi_call_wrapper(func, va_num, ...)			\
	__VA_ARG_NSUFFIX__(_cast64_efi_call, __VA_ARGS__) (func, ##__VA_ARGS__)




#endif
