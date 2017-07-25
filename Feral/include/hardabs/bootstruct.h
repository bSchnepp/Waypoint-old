#ifndef _FERAL_MULTIBOOT_H_
#define _FERAL_MULTIBOOT_H_

#include <feral/feralobjs.h>


/* 
	This is a portable boot header. We translate from multiboot/EFI/etc to this. 
	How we actually do that is uhhhh...? We might have to end up calling Kernel_Main indirectly.
*/

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
