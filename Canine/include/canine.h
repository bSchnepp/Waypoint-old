/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 */

/*
 *	Contributors:
 *		Brian Schnepp
 */

// 0xE85250D6 for Multiboot 2!!
//TODO

#ifndef _KERNEL_H_
#define _KERNEL_H_
struct WayUser
{
	const char* user_name;
	WayUser* parents;
	int signature;
}WayUser;
#endif
