#ifndef __KERNEL_H__
#define __KERNEL_H__

struct WayUser
{
	const char* user_name;
	WayUser* parents;
	int signature;
}WayUser;

#endif