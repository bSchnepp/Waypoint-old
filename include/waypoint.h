/*
 *	Copyright (c) 2017 Brian Schnepp
 *	LICENSE: Apache 2.0. Refer to 'LICENSE' in the root of this project.
 */


#ifndef __WAYPOINT__H__
#define __WAYPOINT__H__


#ifndef WAYPOINT_LEAN_AND_MEAN
		//Bloaty stuff we'll generally not need.
#endif

// This is the header for our userspace processes...
#include <string.h>

//Bind this into kernel later...
#include <Kernel/waypoint_kernel.h>


WayProcess* SpawnProcess(wchar_t* name);	//TODO for this... Child process is always dependant on parent, yada yada.
WayProcess* SpawnProcessAs(wchar_t* name, struct WayUser user);	//usually we'll have the user account created at install time, the Administrator permission group (which is a WayUser), and the user called WAY_SYSTEM, which is like 'root' on a UNIX.

void RetrieveDirectory(char* buffer, size_t size);
void CreateDirectory(char* parent, char* name, int permissions);	//We'll need to fix FreedomCore to adapt to this.



#endif
