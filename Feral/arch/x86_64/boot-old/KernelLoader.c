/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */


#include "multiboot.h"
#include "mbstdio.h"

#include <hardabs/bootstruct.h>
#include <feral/feralobjs.h>


/* 
	Ripped from the old FeralBoot. 
 
	Here, we assume we're trying to load an ELF64
	executable simply because that's what I'm 
	using it for, and don't want to bloat
	the final image by having stuff everywhere.	
 */
#define E_IDENTC 16

struct ElfHeader
{
	UINT8 e_ident[E_IDENTC];

	UINT16 e_type;
	UINT16 e_machine;

	UINT32 e_version;

	UINT64 e_entry;
	UINT64 e_phoff;
	UINT64 e_shoff;

	UINT32 e_flags;

	UINT16 e_ehsize;
	UINT16 e_phentsize;
	UINT16 e_phnum;
	UINT16 e_shentsize;
	UINT16 e_shnum;
	UINT16 e_shstrndx;
}ElfHeader;

struct ElfProgramHeader
{
	UINT32 p_type;
	UINT32 p_flags;
	
	UINT64  p_offset;
	UINT64  p_vaddr;
	UINT64  p_paddr;
	UINT64  p_filesz;
	UINT64  p_memsz;
	UINT64  p_align;
}ElfProgramHeader;

struct ElfSectionHeader
{
	UINT32 sh_name;
	UINT32 sh_type;
	
	UINT64  sh_flags;
	UINT64  sh_addr;
	UINT64  sh_offset;
	UINT64  sh_size;

	UINT32 sh_link;
	UINT32 sh_info;

	UINT64  sh_addralign;
	UINT64  sh_entsize;
}ElfSectionHeader;

enum ElfType
{
	ET_NONE = 0,
	ET_REL = 1,
	ET_EXEC = 2,
	ET_SHARED = 3,	
	ET_CORE = 4	//This is used for program memory dumps
};
/////////////////////////////////////////////////////////////////////

///
/*
	To boot the real kernel, we need to embed a mini "fake kernel" into here,
	It just needs to be able to allocate memory, read an ext4 or FAT32 partition or something,
	load the kernel, and then pretend that it doesn't exist.
 */



///

#if 0
typedef struct _FeralBoot_Header
{
	UINTN  RamAmount;
	
	UINTN  ScreenWidth;
	UINTN  ScreenHeight;
	UINT8  isTextMode;

	VOID*  VideoMemAddr;
	CHAR8* KernelArguments;

	//TODO...
}FeralBoot_Header;
#endif

/* Kernel loader. */
ElfHeader        elf_header;
FeralBoot_Header frl_header;

void KElfLoader(MultibootInfo* header)
{
	//Load it up!
	//We have no malloc() or free(), so we have to do everything on the stack.

	// The kernel is expected to be just an ordinary ELF64 shared object named 'floskrnl'.
	// Something we'll do later is add encryption protection and all that.

	// We might have to redo all of this, since we'll probably need a 32-bit GDT and all.

	UINT32 mb_flags = header->Flags;
	if (MULTIBOOT_INFO_MODS & mb_glags)
	{
		UINT32 ModsCount = header->ModsCount;
		UINT32 ModsEntry = header->ModsAddress;

		for (UINTN i = 0; i < ModsCount; i++)
		{
			size_t sz_MBModStruct = sizeof(Module);
			Module* mod = (Module*)(ModsAddress + (i * sz_MBModStruct));	/* Loop through all the modules */
			//TODO: Do something with them!
		}

	}
	
	VOID* Kernel_Main;	// Entry into the kernel.

	MemoryMap* map = header->MemMapAddress;
	//I think this is how that works?
	frl_header->RamAmount = ((map->LengthHigh << 32) | (LengthLow));
	
	//Inline ASM to switch to 64-bit, prep the kernel, load!
	return;
}




