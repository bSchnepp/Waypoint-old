/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */


#ifndef _FERAL_IPC_MSG_H_
#define _FERAL_IPC_MSG_H_

#include <feral/feralobjs.h>	

typedef struct _FeralTask
{
	/* Stuff we'll need. */
	UINTN references;
	UINTN threads;
		
	UINT64 task_flags;	//Running, not running, blocked, etc...
	BOOLEAN terminated;	//This task should be removed when the kernel sees it...
		
	/* Statistics... */
	UINT64 total_user_time;
	UINT64 total_system_time;
		
	struct _FeralTask* children;	//Child tasks...
		
	//TODO: Virtual memory map declarations and all.
	
	UINTN priority;				//Priority of this task. 0 - 255.
						//Max of whatever is "natural int" of tasks.
									
	//TODO: IPC ports and all.
	/* TODO: pretty much everything. */
		
}FeralTask;

typedef struct
{
		UINTN msg_hdr_bits;
		UINTN msg_hdr_size;
}FeralMsgHdr;

typedef struct _FeralIpcMapping
{
	UINTN NumOfPages;	//Number of pages shared between two processes.
	UINTN* Pages;		//Pointer to the actual (contiguous) physical pages.
}FeralIpcMapping;

#endif

//We **really** need fast IPC (around as fast as SeL4!!!) because framing manager is in userspace.
//To have any reasonable chance at out-competing other platforms for getting ports of video games to, we need to have **signifigant** performance improvements.
//We have to obsess over the little things. If it isn't 256% better, not worth the effort. 100% doesn't cut it.



FeralIpcMapping* KeAllocateIpcSpace(FeralTask processA, FeralTask processB, UINTN numOfPages)
{
	//TODO...
	//Things we need to consider: If process B (passer) terminates before process A (reciever), how does memory deallocation work?
} 




