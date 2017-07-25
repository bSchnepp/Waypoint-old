#ifndef _FERAL_FERALOBJS_H_
#define _FERAL_FERALOBJS_H_

#if defined(__x86_64__) || defined(__i386__)
typedef unsigned long  UINT64;
typedef unsigned int   UINT32;
typedef unsigned short UINT16;
typedef unsigned char  UINT8;
	
typedef signed long  INT64;
typedef signed int   INT32;
typedef signed short INT16;	
typedef signed char  INT8;
		
typedef UINT8 BOOLEAN;
typedef UINT8 BYTE;
#endif

#if defined(__arm__) || defined(__aarch64__)
typedef unsigned long  UINT64;
typedef unsigned int   UINT32;
typedef unsigned short UINT16;
typedef unsigned char  UINT8;
	
typedef signed long  INT64;
typedef signed int   INT32;
typedef signed short INT16;	
typedef signed char  INT8;
		
typedef UINT8 BOOLEAN;
typedef UINT8 BYTE;
//Are these correct? I have 2 little quad-core Acorn processor machines lying around to test on.
//Not sure if they're Aarch64 or if they're ARM32. No labelling or anything ): Will port + test sometime.
#endif

typedef void VOID;


/* This is for portability (to Waypoint) purposes. You shouldn't use these if you can avoid it.*/

typedef UINT64* PUINT64;
typedef UINT32* PUINT32;
typedef UINT16* PUINT16;
typedef UINT8*  PUINT8;

typedef INT64* PINT64;
typedef INT32* PINT32;
typedef INT16* PINT16;
typedef INT8*  PINT8;


typedef BOOLEAN*  PBOOLEAN;
typedef BYTE*     PBYTE;

typedef CHAR8     CCHAR, CHAR;

typedef VOID* PVOID, LPVOID;

typedef UINT32 DWORD;
typedef UINT64 DWORDLONG;

typedef float FLOAT;
typedef double DOUBLE;

typedef UINT32 INT;
typedef UINT32 LONG;
typedef UINT64 LONGLONG;

#define CONST const



#ifndef TRUE
#define TRUE ((BOOLEAN)1) 
#endif

#ifndef FALSE
#define FALSE ((BOOLEAN)0)
#endif

#if defined(__arm__) || defined(__i386__)

typedef UINT32 UINTN;
typedef INT32  INTN; 

#define UINTN_MAX ((1 << 32))
#define  INTN_MAX ((1 << 31) - 1)

#endif

#if defined(__aarch64__) || defined(__x86_64__) 

typedef UINT64 UINTN;
typedef  INT64  INTN; 

#define UINTN_MAX ((1 << 64))
#define  INTN_MAX ((1 << 63) - 1)

#endif




#endif


