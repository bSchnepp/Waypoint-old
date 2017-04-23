/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 */

/*
 *	Contributors:
 *		Brian Schnepp
 */

#ifndef _WAYBOOTMGR_H_
#define _WAYBOOTMGR_H_

#define _MULTIBOOT_KERNEL_ 0xE85250D6
#define _MULTIBOOT_BOOTER_ 0x36D76289


struct kernel
{
	int   kernel_name_length;
	int   kernel_version;
	int   kernel_subversion;
	int   kernel_subversion_patch;
	char* kernel_name;
	char* kernel_location;
}kernel;

struct boot_options
{
	struct kernel* kernel;
	char is_multiboot;
}boot_options;

struct kernel* CreateKernelEntry();
void DestroyKernelEntry();

void PushRam();

int CreateMenu();
int MoveSelection(char direction);
int LoadKernel(int selection);


#endif
