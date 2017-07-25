/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */


#ifndef __FERAL_SYSTEM_CALLS_H_
#define __FERAL_SYSTEM_CALLS_H_

#include <nyx/size_abstract.h>

struct Kernel_Filesystem
{
	//TODO, define files and classes and whatnot...
}Kernel_Filesystem;

struct Kernel_Memory_Manager
{
	UINTN** KeAllocateMemory;
	VOID*  KeFreeMemory;

	//TODO...

}Kernel_Memory_Manager;

/* TODOs... */
static VOID   KeFreeMemory(UINTN* address);
static UINTN* KeAllocateMemory(UINTN size);

#endif
