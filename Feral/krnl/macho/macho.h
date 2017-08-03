#ifndef _LIB_NYX_MACHO_H_
#define _LIB_NYX_MACHO_H_

#include <feral/feralobjs.h>

/* Feral supports Mach-O just because. It's not a priority feature and really only exists because it's fun. */

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
