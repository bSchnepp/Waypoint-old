/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

#ifndef _KRNL_INCLUDE_ERROR_
#define _KRNL_INCLUDE_ERROR_

#include <nyx/size_abstract.h>

struct StopErrorMgr
{
	VOID*   StopErrorFunc;
	UINTN** ArrayOfErrorCodes;
	UINT8** ArrayOfStringsToDisplayOnError;
}StopErrorMgr;

/* Kernel panic default function. */
extern VOID DefaultStopErrorFunction(UINTN error_code, UINT8* string_to_display);
extern static struct StopErrorMgr* CreateSystemMgr(VOID* Func, UINTN** ErrorCodes, UINT8** Strings);

#endif
