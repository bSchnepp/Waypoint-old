/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

//TODO: Go around the whole source tree and slap the appropriate license headers everywhere.

#ifndef _KERNEL_ELF_HDR_
#define _KERNEL_ELF_HDR_

#include "macho_types.h"


struct
{
	UINT64 Magic;
	UINT32 CpuType;
	UINT32 CpuSubtype;
	UINT64 Filetype;
	UINT64 NCmds;
	UINT64 SizeOfCmds;
	UINT64 Flags;
}MachHeader;



#endif
