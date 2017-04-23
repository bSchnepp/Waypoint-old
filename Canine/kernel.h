/*
 *	Copyright (c) 2017 Brian Schnepp
 *	LICENSE: Apache 2.0. Refer to 'LICENSE' in the root of this project.
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
