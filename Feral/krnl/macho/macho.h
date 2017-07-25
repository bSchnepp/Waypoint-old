#ifndef _LIB_NYX_MACHO_H_
#define _LIB_NYX_MACHO_H_

#include <nyx/size_abstract.h>

#pragma pack(1)
typedef struct _MachHeader
{
	UINT32 magic;	//MachO magic number...
	UINT32 cputype;
	UINT32 cpusubtype;
	UINT32 filetype;
	UINT32 ncmds;
	UINT32 sizeofcmds;
	UINT32 flags;
	UINT32 buffer;
}MachHeader;
#pragma pack(0)

#endif
