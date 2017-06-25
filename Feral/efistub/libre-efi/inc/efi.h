/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */

//Macro to say "THIS IS LIBRE-EFI!"
#ifndef _LIBRE_EFI
#define _LIBRE_EFI
#endif

#ifndef _LIBRE_EFI_INCLUDE_
#define _LIBRE_EFI_INCLUDE_


/* Temporary stubs just to make sure everything adds up correctly... */
#define IN 
#define OPTIONAL
#define OUT
#define EFIAPI






#include "efibind.h"
#define CONST const

/* Unsorted bits and all, just to get the headers to work. */
typedef UINT64 EFI_LBA;
typedef UINTN EFI_TPL;
typedef UINTN EFI_STATUS;
typedef VOID* EFI_HANDLE;
typedef UINT8 BOOLEAN;

/* Defined in PDF page 365 */
typedef struct
{
	UINT16 Year; //1990 - 20XX.
	UINT8 Month; //1 - 12
	UINT8 Day; //1 - 31
	UINT8 Hour;	//0 - 23
	UINT8 Minute;	//0 - 59
	UINT8 Second;	//0 - 59
	UINT8 Pad1;
	UINT32 Nanosecond;	// 0 - 999999999
	INT16 TimeZone;	//-1440 to 1440 or 2047 Subtract UTC time with this.
	UINT8 Daylight;
	UINT8 Pad2;
}EFI_TIME;

#include "efitableuuid.h"
#include "efiproperties.h"
#include "efigpt.h"

#include "efibootservices.h"
#include "efiruntimeservices.h"
#include "efiloadedimage.h"


#include "efidecl.h"	//This should be close to last if not last.
//TODO...

#endif
