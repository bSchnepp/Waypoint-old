#ifndef _FERAL_KERNEL_MANAGEMENT_TASK_H_
#define _FERAL_KERNEL_MANAGEMENT_TASK_H_

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
