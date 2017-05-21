/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 */

/*
 *	Contributors:
 *		Brian Schnepp
 */

#ifndef _PANIC_H_
#define _PANIC_H_

void stop_error(int errorcode);

void stop_error_extended(int errorcode);	//More specific details.

void kernel_dump();	//Dumps to a log file. Switches to an emergency kernel before system shutdown.

#endif
