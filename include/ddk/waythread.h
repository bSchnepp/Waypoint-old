/*
	Feral device driver kit header.

	Author:
		Brian Schnepp	June 22, 2017.
 */

#ifndef _FERAL_THREAD_H_
#define _FERAL_THREAD_H_

#include "../feralstatus.h"
#include "../feral/feralobjs.h"
//TODO: when makefiles are ready, fix these to be done with angle braces. (relative to root)

#ifdef __cplusplus
extern "C" 
{
#endif

//Stub for now, fix later.
typedef INT64 KTHREAD:	


static inline KTHREAD* KeGetCurrentThread(void)
{
	return ((void*)0);	//TODO...
}

static inline KTHREAD* KeCreateThread(void)
{
	return ((void*)0);	//TODO...
}

static inline void KeDesroyThread(KTHREAD* thread)
{
	//TODO...
	return;
}



#ifdef __cplusplus
}
#endif

#endif
