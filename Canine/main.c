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
#include "panic.h"

int mount_filesystems(void);

struct Drive
{
	int drive_size;
	unsigned char letter;
	unsigned char letter_depth;	//If we go over Z. So we can have 1Z:/, 2A:/, 4V:/, etc.
}Drive;

struct Partition
{
	unsigned int number;
	//ROOT FOLDER, TODO!!
	//TODO, mount partitions.
}Partition;

//TODO: Register objects, classes, etc.

void assign_drive_letter(Drive* drive, char c)
{
	drive->letter = c;
	//TODO for this as well.
}

void setup_idt(void)
{
	//TODO
}

int probe_video_graphics(void)
{
	//Load up the VGA driver. Make sure we can do video and stuff.
}

void kernel_main()
{
	//Immediately set up IDT, kill whatever we don't need from EFI.
	setup_idt();

	if (probe_video_graphics())
	{
		//Should return 0, if not, stop error.
		stop_error(0xA);	//16 for it being video driver not available. Make a table later.
	}

	//Startup and mount filesystems.
}

int mount_filesystems(void)
{
	//Mount filesystems to the respective drives.
	Drive* drives;	//Allocate 24 spaces, for A - Z.
	// If we need more, then we'll have to create AA, AB, AC, AAA, AAB, etc. We'll ignore that problem for now. Or we can just go to numbers, with 1:/ after Z.
}

