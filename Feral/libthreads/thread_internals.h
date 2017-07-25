/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */

#include <feral/feralstatus.h>


//TODO...
#define SPIN_RESCHEDULE	/* Do something new if thread is just spinlocking... */

#define THREAD_RUNNING   (0 << 0)
#define THREAD_SWITCHING (1 << 0)
#define THREAD_BLOCKED   (1 << 1)
#define THREAD_WAITING   (1 << 2)

#if 0
enum
{
	THREAD_NONE,
	THREAD_MUTEX,
	THREAD_CONDITION,
	THREAT_PORT_ENTRY
}FeralWaitEnum;
#endif	//Redo this later...

typedef struct _FeralThread
{
	struct _FeralThread*  next;	/* Threads are linked list. Trust me on this being a better idea. */
	struct _FeralThread** head;	/* Master thread list and all. */
	struct _FeralThread*  blocker;	/* If not NULL, that thread must execute before this one can. Skip over this. */
	
}FeralThread;

