/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 */

/*
 *	Contributors:
 *		Brian Schnepp
 */

void stop_error(int errorcode)
{
	//Blue screen of death!
	//TODO: Blank out screen, make it blue, put up white text with error message.

	static char* error_msg_core = "An unexpected error has occured and Waypoint has been shut down to protect your computer.\n\
	If this is the first time this error has happened, try restarting your computer.\n\
	If this message appears repeatedly, check to make sure device drivers are properly set up and that the operating system \n\
	has not been corrupted. If it has, try reinstalling the operating system.\n\
	\nWe are sorry for this inconvenience.\n\
	Error code: \n");	

	static int error_crash;
	char text_color = 0xFF;
	char bg_color = 0x11;
	//Is that right? Check later.
	
	//Print out just the number after printing the message to the screen. 
	for (;;)
	{		
		error_crash = error_crash++;
	}	
}
