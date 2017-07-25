/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

#include <error/stop_error.h>


VOID DefaultStopErrorFunction(UINTN error_code, UINT8* string_to_display)
{
	//Paint the screen blue... TODO
	//Shutdown the kernel's internal graphics manager. TODO.
	//Go back to VGA mode. TODO.

	UINT8* StartingString = "Your computer has encountered a critical error and needs to shutdown.\
				\nWe're sorry!\n\n\
				\nError:";

	//Print each character to the system terminal. TODO. (Requires printk implementation!!!)

	UINT8 EndingString = "\nWe're going to protect your computer by halting it.\
			      \nPlease restart your computer.";
	
	for (;;){};	//Essentially 'kill' the system.	
}

static struct StopErrorMgr* CreateSystemMgr(VOID* Func, UINTN** ErrorCodes, UINT8** Strings)
{
	static struct StopErrorMgr mgr;	//We're going to need a kmalloc or something. Agh!!!
	mgr.StopErrorFunc = &DefaultStopErrorFunction;
	mgr.ArrayOfErrorCodes = {{0}};
	mgr.ArrayOfStringsToDisplayOnError = {{"Unspecified error!"}};
}
