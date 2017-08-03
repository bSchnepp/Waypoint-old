/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */

#ifndef _FERAL_MULTIBOOT_H_
#define _FERAL_MULTIBOOT_H_

#include <feral/feralobjs.h>


/* 
	This is a portable boot header. We translate from multiboot/EFI/etc to this. 
	How we actually do that is uhhhh...? We might have to end up calling Kernel_Main indirectly.
*/

typedef struct _FeralBoot_Header
{
	UINT64  RamAmount;
	
	UINTN  ScreenWidth;
	UINTN  ScreenHeight;
	UINT8  isTextMode;

	VOID*  VideoMemAddr;
	CHAR8* KernelArguments;

	//TODO...
}FeralBoot_Header;

#endif
