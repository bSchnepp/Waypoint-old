/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */
#include <feral/feralobjs.h>

/* CPU stuff */
typedef INT32 CpuType;
typedef INT32 CpuSubtype;

/* Defines for the CPU.*/

#define CPU_STATE_USER   0
#define CPU_STATE_SYSTEM 1
#define CPU_STATE_IDLE   2
#define CPU_STATE_NICE   3

#define CPU_STATE_MAX    4

#define CPU_64_BIT       0x01000000 

#define CPU_TYPE_ANY     ((CpuType) -1             ) 

#define CPU_TYPE_X86_32  ((CpuType) 7              )
#define CPU_TYPE_ARM_32  ((CpuType) 12             )

#define CPU_TYPE_X86_64  ((CpuType) CPU_64_BIT + 7 )
#define CPU_TYPE_AArch64 ((CpuType) CPU_64_BIT + 12)

#define CPU_TYPE_PPC     ((CpuType) 18             )
#define CPU_TYPE_PPC_64  ((CpuType) CPU_64_BIT + 18)

/* Subtypes: some CPUs can be in either little-endian or big-endian mode.*/
#define CPU_SUBTYPE_MULTIPLE      ((CpuSubtype) -1)
#define CPU_SUBTYPE_LITTLE_ENDIAN ((CpuSubtype)  0)
#define CPU_SUBTYPE_BIG_ENDIAN    ((CpuSubtype)  1)
/* These are multiplied against the value for big or little endian. */

/* TODO: Differentiate between CPU subtypes, if we should really even care. */



/* Memory stuff: For the sake of simplicity, we'll assume they're the same as a 'natural int'. */
/* That assumption (probably) doesn't work true on _all_ CPU architectures, but it does for ARM64 + x64 */
typedef UINTN VmOffset;
typedef UINTN VmSize;



/* Information about the machine. Imitating mach/machine.h */
typedef struct MachineInfo
{
	INT32 MajorVersion;	/* Major version of the kernel (>0<.1, >1<.0, >10<.12, etc)    */
	INT32 MinorVersion;	/* Minor version of the kernel. (0.>1<, 1.>0<, 10.>12<, etc.) */

	INT32 MaxCpus;		/* Max number of CPUs we can utilize  */
	INT32 AvailCpus;	/* Number of CPUs actually available. */
	UINTN MemorySize;	/* Size of memory (in bytes)	      */
}MachineInfo;

typedef struct MachineSlot
{
	BOOLEAN IsCpu;			/* Is there a CPU here? */
	CpuType TypeOfCpu;		/* Type of the CPU (probably x86-64) */
	CpuSubtype SubtypeOfCpu;	/* Subtype of the CPU */
	BOOLEAN IsRunning;		/* Is the CPU running? */
	UINT32 CpuTicks[CPU_STATE_MAX];	/*  */
	UINT32 IntClockFreq;		/* Clock interrupt frequency */
}MachineSlot;
