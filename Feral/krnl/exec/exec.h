/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

#ifndef _LIB_NYX_EXEC_H_
#define _LIB_NYX_EXEC_H_

#include <feral/feralobjs.h>

/* 
	Initially was going to call Feral "Waypoint Is Not New Technology!".
	Stupid name. "Feral" is much better because it reflects that fact that it's not terribly innovative better.
*/

typedef enum
{
	EXEC_NONE  = 0,	//Userspace Service can figure out what format it is by itself. Not helping.
	EXEC_ELF   = 1,
	EXEC_MACHO = 2,	//Why not?
	EXEC_COFF  = 3,
	EXEC_PE    = 4	//If someone wants to create a kernel personality for loading/running PE stuff.

	//Only supported formats done "natively" are ELF and possibly MACHO. Everything else is piped
	//to a userspace server with relevant information (section header, start, etc) to make life 
	//easy. This way, something like WINE can just skip over a lot of initialization steps.
	//Said userspace server just declares itself as so by the registry.
}ExecFormat;

typedef enum
{
	SUBSYS_SYSV    = 0x00,
	SUBSYS_LINUX   = 0x03,
	SUBSYS_MACH    = 0x04,
	SUBSYS_BSD     = 0x09,
}SubssytemID;

typedef enum
{
	//In an effort to eventually create some sort of "Waypoint on Waypoint" (WoW), we JIT compile (or AOT) for different ISAs... eventually?
	ISA_NUL   = 0x00,	
	ISA_X86   = 0x03,
	ISA_PPC   = 0x14,	//Need to implement UEFI for it first.
	ISA_ARM32 = 0x28,
	ISA_JCORE = 0x2A,	//Just in case I get a FPGA sometime + create UEFI firmware for it.
	ISA_x8664 = 0x3E,
	ISA_ARM64 = 0xB7,
	ISA_RISCV = 0xF3	//Again, need to create UEFI support for it.
}ArchitectureID;

typedef struct
{
	ExecFormat format;
	SubsystemID subsys;

	UINTN StartAddress;
	UINTN TextSize;

	UINTN BssAddress;
	UINTN BssSize;

	UINTN CodeAddress;
	UINTN CodeSize;
	/* TODO: locations in memory and all... */
}ExecInfo;

#endif
