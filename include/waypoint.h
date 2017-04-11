/*
Copyright (c) 2017 Brian Schnepp

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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
