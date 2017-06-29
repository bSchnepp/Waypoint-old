#ifndef _FERAL_FERAL_OBJS_H_
#define _FERAL_FERAL_OBJS_H_

//typedef wchar_t* UNICODE_STRING;
//typedef enum { false, true } BOOLEAN;

#if defined(__x86_64__) || defined(__i386__)
typedef signed long int INT64;
typedef signed int INT32;
typedef signed short INT16;
typedef signed char INT8;

typedef unsigned long int UINT64;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;

#endif

#if defined(__aarch64__) || defined(__arm__)
//Common between aarch64 and arm32.

#endif

#if defined(__aarch64__)

#endif

#if defined(__arm__)

#endif


//TODO, port to ARM* (64 and 32, priority on Aarch64). Support for other CPUs would be great.
//We do this in case there's a weird CPU out there we want to port to that needs long long int for 64-bit integers and whatnot.

typedef enum
{
	NativeAPI = 0x0,	//Priority for now, defines the API that drivers, system services, etc. are expected to run on.
	OWaysys = 0x1,		//Small little layer on top, for "native" applications. Link into owaysys.dyn so this API remains stable even if kernel changes somewhat, or things removed from Native API.
	POSIX = 0x2,		//Compatibility with POSIX, port clang and whatnot over. Here we become self-hosting without any doubt or anything. Mainline clang ports over fine and all.
	ECMA234 = 0x3		//Dream that probably will never even get worked on.
}SubsystemID;

#endif
