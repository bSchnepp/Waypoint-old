/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

#include <efi.h>
#include <kernel/feral_kernel.h>	//Connect to the kernel...
#define EFIAPI __attribute__((ms_abi))
//Implementation of the core functions we want for EFI, just enough to support the kernel correctly.



EFI_STATUS EFIAPI efi_main(VOID* ImageHandle, EFI_SYSTEM_TABLE* SystemTable)
{
	InitializeUefi(ImageHandle, SystemTable);
	//Associate the relevant functions to the tables we care about...

	//Call the kernel from here, exit boot services.
	return EFI_SUCCESS;
}
