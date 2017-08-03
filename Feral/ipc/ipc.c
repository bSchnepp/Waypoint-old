/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */

#include <feral/feralobjs.h>	
#include <krnl/management/task.h>


FeralIpcMapping* KeAllocateIpcSpace(FeralTask processA, FeralTask processB, UINTN numOfPages)
{
	//TODO...
	//Things we need to consider: If process B (passer) terminates before process A (reciever), how does memory deallocation work?
} 



//We **really** need fast IPC (around as fast as SeL4!!!) because framing manager is in userspace.
//To have any reasonable chance at out-competing other platforms for getting ports of video games to, we need to have **signifigant** performance improvements.
//We have to obsess over the little things. If it isn't 256% better, not worth the effort. 100% doesn't cut it.







