/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */

/*
	NTFS volume is based on (sectors * factor of 2) == cluster.
	The first cluster starts at the very beginning of the partition,
	while it is duplicated to halfway through the disk. (because redundancy..?)

	0			     N/2       			   N
	[||||-------------------------||||-------------------------]
 */


#ifndef _FERAL_FS_NTFS_
#define _FERAL_FS_NTFS_

struct _BIOS_PARAM_BLOCK
{
	//TODO...
}BIOS_PARAM_BLOCK;

struct _BOOT_SECTOR
{
	//TODO...
	UINT8 JumpAddr[3];
	UINT8 OEM[8];
	//...
}BOOT_SECTOR;



#endif
