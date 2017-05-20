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

// We're ELF, not PE. Remember that.

#ifndef _KERNEL_H_
#define _KERNEL_H_

struct WayUser
{
	const char* user_name;
	long int num_parents;
	WayUser* parents;
	int signature;	//UID, basically. User also always inherits permissions from it's parents. (We'll figure out a way to make it more intuitive like being able to limit inherited permissions.)
	// Need Administrator to create a new User, no user can have SYSTEM as a parent. Users with Administrator is probably OK because System Control should prompt before making a SYSTEM process and all.
	// SYSTEM has no parents, children, or "groups". PERIOD. It can do anything to anyone without any restrictions and no control on it at all. It can even terminate system processes.
	// We simply have a "UAC-like" interface requiring a system password. Every "sudo" needs that action re-done, or it can be auto-done for 3 minutes at a time, which is configurable.
	// We're trying to really enforce security as best we can.
}WayUser;

struct CnProcess
{
	//No libc, so 'unsigned short int' is in fact char16_t.
	unsigned short int* proc_name;
	register rip;
	register stack_start;
	register stack_end;
	//TODO
}CnProcess;

// int 2E + rax = 0x00, recover in case of things? I don't know, implement later. Internal use only.
void KeRecover();

// int 2E + rax = 0x01, rbx = address to process, yeah. This is probably all wrong and whatnot, just laying out syscalls and fix prototypes later.
CnProcess* CnCreateProcess(struct CnProcess* proc, int argc, unsigned short int* argv[]);	//TODO, expect this to change, new stuff and all.

// int 2E + rax = 0x02, rbx = [EXIT CODE]
void CnStopProcess(struct CnProcess* proc);

//80 - 100 is for *NIX convenience stuff... Expect the specific numbers to change, the wonderful pre-selected syscall layout to change, and all that fun stuff.
// int 2E + rax = 0x80 or something.
CnProcess* CnSpawnProcess();	//basically "fork()"

int CnExec(CnProcess* process);	//TODO

//rax = 100 - 110 is reserved for window creation and stuff. Probably. Still thinking about pros/cons about cramming display server into kernel.
//rax = 111 - ??? would thus also be reserved for sound stuff. 111 would probably make a user-space program the official sound server for the OS, and stuff.
//We're trying to be monolithic, but maybe "hybrid" in the sense XNU is hybrid--pretty much monolithic save for some bits and pieces here and there.

// Just in case, ??? - ??? + 20 is reserved for graphics stuff, like below.
// These can ONLY be accessed by SYSTEM process, running the actual window server.
long int CnCreateFrame();	//TODO
void CnDestroyFrame();	//TODO

#endif






































/*
 
We're going to have some rhyme and reason for syscall names:
	<PREFIX> <ACTION> <OBJECT>
Just like Uncle NT.

However, prefixes are STRICTLY two characters [one upper, one lower] only, for consistency/readability purposes. If the obvious one doesn't work, make one up. If you __REALLY__ need that combo, use lower first then upper.

'Rtl' or 'Alpc' are BIG no-nos. Do 'Dl' or cram into 'Pc' instead.

In full honesty, Waypoint will probably never be "production grade", and is really more just for fun. Don't worry **too** hard about it being messy, as long as it's fixable. [Just try not to make a mess in the first place.]

Prefixes:
	- Cn [Canine, refers to external kernel stuff.]
	- Ke [Internal kernel stuff, 'privlaged' processes like a sound server or other internal kernel services are the only ones allowed to call. Needs SYSTEM to run it.]
	- Ss [Subsystem stuff, we'll probably be confused as a microkernel for having this as a main feature ): ]
	- Pc [Process stuff, usually process services.]

Note that for each session [only a single person-user at a time, we're not making a server-oriented OS], only 3 users will probably be present with programs that _must_ run while the session is active.
This limitation can be removed later, but meh. Those 3 users, of course, are the running user, Administrator, and SYSTEM.


PROBABLY MOVE THE SYSCALL DEFINITIONS TO <CANINE/SYSCALLS.H>
*/
