/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */

#ifndef _MULTIBOOT_H_
#define _MULTIBOOT_H_

#include <feral/feralobjs.h>


/* This is set if there's bootloader modules to worry about. */
#define MULTIBOOT_INFO_MODS		0x00000008


typedef struct _MemoryMap
{
	UINT32 Size;
	UINT32 BaseAddressLow;
	UINT32 BaseAddressHigh;
	UINT32 LengthLow;
	UINT32 LengthHigh;
	UINT32 Type;
}MemoryMap;

typedef struct _MultibootModule
{
	UINT32 ModStart;
	UINT32 ModEnd;
	UINT32 String;
	UINT32 Reserved;
}Module;

typedef struct _MultibootInfo
{
	UINT32 Flags;
	UINT32 MemLower;
	UINT32 MemUpper;
	UINT32 BootDevice;
	UINT32 CmdLine;
	UINT32 ModsCount;
	UINT32 ModsAddress;
	
	
	UINT32 buffer[4];	//We don't care about ELF or Aout section headers and all.

	UINT32 MemMapLength;
	UINT32 MemMapAddress;
}MultibootInfo;

#endif
