/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 */

/*
 *	Contributors:
 *		Brian Schnepp
 */

#include "kdefs.h"

int mount_filesystems(void);

struct Drive
{
	int drive_size;
	//ROOT FOLDER, TODO!!
	unsigned char letter;
	unsigned char letter_depth;	//If we go over Z. So we can have 1Z:/, 2A:/, 4V:/, etc.
}Drive;

struct Partition
{
	unsigned int number;
	//TODO, mount partitions.
}Partition;

//TODO: Register objects, classes, etc.

void kernel_main()
{
	//Startup and mount filesystems.
}

int mount_filesystems(void)
{
	//Mount filesystems to the respective drives.
	Drive* drives;	//Allocate 24 spaces, for A - Z.
	// If we need more, then we'll have to create AA, AB, AC, AAA, AAB, etc. We'll ignore that problem for now. Or we can just go to numbers, with 1:/ after Z.
}

