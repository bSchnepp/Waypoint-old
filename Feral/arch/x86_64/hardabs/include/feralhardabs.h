/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */


#include <feral/feralobjs.h>

bool kernelHardwareClockLocalOrUtcTime = 0;	//Assume it's UTC time on hardware clock.

typedef struct _DAY_MONTH_PAIR __attribute__((__packed__))
{
	UINT8 NumDaysEven : 1 	//If number of days is 30 or 28/29. Just to waste a bit to get Day to 4 bits.
	UINT8 Month 	  : 3;	//0 - 14 (Smallest you can represent months with)
	UINT8 Day   	  : 4;	//0 - 31
}DAY_MONTH_PAIR

typedef struct _KERNEL_SYSTEM_TIME
{
	UINT16 Year;		//Are you really using Waypoint in 65535 AD?
	UINT8  DayMonth;	//Above should be treated as a UINT8...	
}KERNEL_SYSTEM_TIME;


/* Get the current thread that the kernel uses. The kernel is ALWAYS on 1 physical processor. */
//TODO on this defenition, etc. etc. How will this work out? (try to mirror the ReactOS kernel so that drivers can be ported super easy)
VOID* KeGetCurrentThread();
// The kernel is async in order to squeeze more performance out.
// While this 'wastes' a processor to do more awesome, it prevents the usermode --> kernel mode
// context switch, which does the most to impact performance. (over 100 CPU cycles!!!! Bad!!!)
// We'd rather leave the kernel thread in a spinlock while inactive (which shouldn't happen too much) than have it on ALL cores/threads 
// and into a giant mess. In a Zen 1700X CPU, we'd have 1 core (2 
// threads) available for the kernel, and 14 real threads for userspace processes. Plenty of room.
// We care more about performance than scalability. (And readability over performance, 
// hence why C instead of raw assembly. Also so we can do an Aarch64 port.)

//Especially since Team Red is making good 8-core processors, there's no shortage of cores to worry
//about. We also really don't care about power efficiency outside of hardabs for Aarch64.
//Essentially no one still uses a 2-core system for gaming anymore. Don't bother supporting it.
//Are 3-core Accelerated Processing Units still a thing? Highly suggest 4 cores for any system running Waypoint, ideally 6 or 8.
//More, right now, is kinda pointless and too much on wasting potential per-core performance.

//We're focused on high-end hardware, where 800W - 1200W PSUs (or better like 1600W) and dual top-of-the-line graphics cards and 32GB of non-ECC RAM are the norm.



//Following the hype train (and now thay my Zen 1700X arrived + motherboard), I'll start optimizing Feral for the brand new Zen architecture specifically.
//(not that I hate Team Blue, quite the contrary, I really have no real preference, it's that I'm following the hype train and just want whatever's faster.)

/* TODO: make NIXoid applications happy. */
UINT64 UsConvertKernelTimeToEpochTime(DAY_MONTH_PAIR pair);


//TODO: Provide the nice defines we want for the assembly stuff we have to have.
// (ie, setting up stack and all that...)

//Probably a 12MB stack.


/* HARDABS error messages */
#define HARDABS_MSG_HARDWARE_ERROR "\n\n !!! Hardware malfunction! !!! \n\n"
#define HARDABS_MSG_HALT	     "\n !!! The system has halted !!! \n"

#define HARDABS_MSG_PANIC	       " !!! HARDABS panic! System halting... !!! "



//The logic goes if you don't start making a production system NOW, it'll never be done by the time 
//it's able to be relevant. I should have started this (as in THIS this) when I was 12 - 13. Then we'd 
//be done by 2040, not like 2045.


/*
	When a process requests another thread, we should (in order):
		- Attempt to give it the thread on the same core, if SMT/HT is available.
		- Attempt to give it to a new core, if available.
		- Attempt to give it to a new thread on the least active core.
		- Allocate a 'virtual thread' and start switching out threads and stuff.
		- Uh oh. Getting to this spot on the list shouldn't ever happen. Stop Error! He's dead, Jim!
 */
