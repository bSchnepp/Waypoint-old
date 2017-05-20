/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * TODO: Rework this so it's totally separate from the kernel. This is the header to include to create user-space processes and all.
 */


/*
 *	Contributors:
 *		Brian Schnepp
 */

#ifndef __WAYPOINT__H__
#define __WAYPOINT__H__


#ifndef _OWAYSYS_LEAN_AND_MEAN_

//Bloaty stuff we'll generally not need.
struct WayFrame
{
	wchar_t* window_name;
	unsigned int width;
	unsigned int length;

	unsigned int pos_x;
	unsigned int pos_y;
}WayFrame;

#endif

// This is the header for our userspace processes...
#include <string.h>

//Bind this into kernel later...
#include <canine.h>


WayProcess* SpawnProcess(wchar_t* name);	//TODO for this... Child process is always dependant on parent, yada yada.
WayProcess* SpawnProcessAs(wchar_t* name, struct WayUser user);	//usually we'll have the user account created at install time, the Administrator permission group (which is a WayUser), and the user called SYSTEM, which is like 'root' on a *NIX.

void RetrieveDirectory(char* buffer, size_t size);	//TODO: Return a FILE*, need to define that first, though.
void CreateDirectory(wchar_t* parent, wchar_t* name, int permissions);	//We'll need to fix FreedomCore to adapt to this.


WayProcess* Fork();	//For compatibility with *NIX systems.

#endif
