/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */

//Macro to say "THIS IS LIBRE-EFI!"
#ifndef _LIBRE_EFI_LIB_
#define _LIBRE_EFI_LIB_
#endif

/* Things initialized by InitializeLib(imgHdl, gST) */
EFI_SYSTEM_TABLE* gST;
EFI_BOOT_SERVICES* gBT;
EFI_RUNTIME_SERVICES* gRT;

/* Stuff to make it nice. */
void InitializeLib(EFI_HANDLE* ImageHandle, EFI_SYSTEM_TABLE* SystemTable);



/* Ease functions managed by libre-efi... */
EFI_STATUS Print(wchar_t* String);
EFI_STATUS Stall(UINT64 time);
//TODO...

#endif



