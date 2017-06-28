/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

/* 
	Definitions for EFI. This replaces libre-efi, since we don't need ALL of EFI to work correctly.
	Referencing the UEFI 2.7 spec for the relevant definitions.
*/

#ifndef _EFISTUB_EFI_H_
#define _EFISTUB_EFI_H_

#include "efibind.h"
#include "efiguid.h"

//Stub FERAL kernels should be accordingly named "FERLKRNL.EFI", since we're a PE executable. We need to be 8.3 compliant.
//Normal kernels should be "feraloskrnl.pro", since they are ELF executables.

/* Defines we'll need. */

//Needed for capsules later on... Defined on page 312 of UEFI 2.7 spec.
#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET		 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 		 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 			 0x00040000

#define EFI_MEMORY_DESCRIPTOR_VERSION				  1

/* 	 Page 190 2.7 spec. These can be ORed as needed. 	 */
#define EFI_MEMORY_UC				 0x0000000000000001
#define EFI_MEMORY_WC				 0x0000000000000002
#define EFI_MEMORY_WT				 0x0000000000000004
#define EFI_MEMORY_WB				 0x0000000000000008
#define EFI_MEMORY_UCE				 0x0000000000000010
#define EFI_MEMORY_WP				 0x0000000000001000
#define EFI_MEMORY_RP				 0x0000000000002000
#define EFI_MEMORY_XP				 0x0000000000004000
#define EFI_MEMORY_NV				 0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE		 0x0000000000010000
#define EFI_MEMORY_RO				 0x0000000000020000
#define EFI_MEMORY_RUNTIME			 0x8000000000000000

#define EVT_TIMER 					 0x80000000
#define EVT_RUNTIME 					 0x40000000
#define EVT_NOTIFY_WAIT 				 0x00000100
#define EVT_NOTIFY_SIGNAL 				 0x00000200
#define EVT_SIGNAL_EXIT_BOOT_SERVICES 			 0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE 		 0x60000202


#define EFI_PAGE_SHIFT   				        	    12
#define EFI_PAGE_SIZE			       (((UINT64)1) << EFI_PAGE_SHIFT)
#define EFI_PAGES_MAX				(0xFFFFFFFF >> EFI_PAGE_SHIFT)

#define EFI_PCI_IO_PASS_THROUGH_BAR 					  0xFF

#define EFI_PCI_IO_ATTRIBUTE_ISA_MOTHERBOARD_IO 				0x0001
#define EFI_PCI_IO_ATTRIBUTE_ISA_IO 						0x0002
#define EFI_PCI_IO_ATTRIBUTE_VGA_PALETTE_IO 					0x0004
#define EFI_PCI_IO_ATTRIBUTE_VGA_MEMORY 					0x0008
#define EFI_PCI_IO_ATTRIBUTE_VGA_IO 						0x0010
#define EFI_PCI_IO_ATTRIBUTE_IDE_PRIMARY_IO 					0x0020
#define EFI_PCI_IO_ATTRIBUTE_IDE_SECONDARY_IO 					0x0040
#define EFI_PCI_IO_ATTRIBUTE_MEMORY_WRITE_COMBINE 				0x0080
#define EFI_PCI_IO_ATTRIBUTE_IO 						0x0100
#define EFI_PCI_IO_ATTRIBUTE_MEMORY 						0x0200
#define EFI_PCI_IO_ATTRIBUTE_BUS_MASTER 					0x0400
#define EFI_PCI_IO_ATTRIBUTE_MEMORY_CACHED 					0x0800
#define EFI_PCI_IO_ATTRIBUTE_MEMORY_DISABLE 					0x1000
#define EFI_PCI_IO_ATTRIBUTE_EMBEDDED_DEVICE 					0x2000
#define EFI_PCI_IO_ATTRIBUTE_EMBEDDED_ROM 					0x4000
#define EFI_PCI_IO_ATTRIBUTE_DUAL_ADDRESS_CYCLE 				0x8000
#define EFI_PCI_IO_ATTRIBUTE_ISA_IO_16 						0x10000
#define EFI_PCI_IO_ATTRIBUTE_VGA_PALETTE_IO_16 					0x20000
#define EFI_PCI_IO_ATTRIBUTE_VGA_IO_16 						0x40000

#define EFI_RUNTIME_SERVICES_SIGNATURE 			 ((UINT64)0x5652453544E5552)
#define EFI_BOOT_SERVICES_SIGNATURE    			((UINT64)0x56524553544F4F42)

#define EFI_RUNTIME_SERVICES_REVISION ((2<<16) | (50))
#define EFI_BOOT_SERVICES_REVISION    ((2<<16) | (50))

#define EFI_OPTIONAL_PTR 						 0x00000001
#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 				 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 				 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET					 0x00040000

#define EFI_OS_INDICATIONS_BOOT_TO_FW_UI	 		  0x0000000000000001
#define EFI_OS_INDICATIONS_TIMESTAMP_REVOCATION 	 	  0x0000000000000002
#define EFI_OS_INDICATIONS_FILE_CAPSULE_DELIVERY_SUPPORTED	  0x0000000000000004
#define EFI_OS_INDICATIONS_FMP_CAPSULE_SUPPORTED 		  0x0000000000000008
#define EFI_OS_INDICATIONS_CAPSULE_RESULT_VAR_SUPPORTED		  0x0000000000000010
#define EFI_OS_INDICATIONS_START_OS_RECOVERY 			  0x0000000000000020
#define EFI_OS_INDICATIONS_START_PLATFORM_RECOVERY 		  0x0000000000000040

#define EFI_BTT_ALIGNMENT 							4096
#define EFI_BTT_INFO_UNUSED_LEN 						3968
#define EFI_BTT_INFO_BLOCK_SIG_LEN 						  16

#define EFI_BIT_INFO_BLOCK_FLAGS_ERROT 					  0x00000001
#define EFI_BTT_INFO_BLOCK_MAJOR_VERSION 					   2
#define EFI_BTT_INFO_BLOCK_MINOR_VERSION 					   0

#define EFI_BTT_FLOG_ENTRY_ALIGNMENT 64

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL 		0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL 			0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL 		0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER 		0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER 			0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE 			0x00000020





typedef UINTN EFI_PHYSICAL_ADDRESS;
typedef UINTN EFI_VIRTUAL_ADDRESS;
typedef VOID* EFI_HANDLE;


/* Numbers we're given tend to be in the format XXXXXX-XXXX-XXXX-XXXX-XX-XX-XX-XX-XX-XX. */

//Needed for memory allocation, page 184.
typedef enum
{
	AllocateAnyPages   = 		0,
	AllocateMaxAddress = 		1,
	AllocateAddress    = 		2,
	AllocateMax        = 		3
}EFI_ALLOCATE_TYPE;

typedef enum
{
	EfiResetCold,	//Essentially a power re-cycle.
	EfiResetWarm,	//System wide re-initialization. Pending cycles aren't corrupted.
	EfiResetShutdown,
	EfiResetPlatformSpecific
}EFI_RESET_TYPE;

typedef enum
{
	EfiReservedMemoryType = 	 0,
	EfiLoaderCode =			 1,
	EfiLoaderData =			 2,
	EfiBootServicesCode =		 3,
	EfiBootServicesData =		 4,
	EfiRuntimeServicesCode =	 5,
	EfiRuntimeServicesData =	 6,
	EfiConventionalMemory =		 7,
	EfiUnusableMemory =		 8,
	EfiACPIReclaimMemory =		 9,
	EfiACPIMemoryNVS = 		10,
	EfiMemoryMappedIO = 		11,
	EfiMemoryMappedIOPortSpace = 	12,
	EfiPalCode =			13,
	EfiPersistentMemory =		14,
	EfiMaxMemoryType =		15
}EFI_MEMORY_TYPE;

typedef enum 
{
	EfiPciIoWidthUint8,
	EfiPciIoWidthUint16,
	EfiPciIoWidthUint32,
	EfiPciIoWidthUint64,
	EfiPciIoWidthFifoUint8,
	EfiPciIoWidthFifoUint16,
	EfiPciIoWidthFifoUint32,
	EfiPciIoWidthFifoUint64,
	EfiPciIoWidthFillUint8,
	EfiPciIoWidthFillUint16,
	EfiPciIoWidthFillUint32,
	EfiPciIoWidthFillUint64,
	EfiPciIoWidthMaximum
}EFI_PCI_IO_PROTOCOL_WIDTH;

typedef enum
{
	EfiPciIoAttributeOperationGet,
	EfiPciIoAttributeOperationSet,
	EfiPciIoAttributeOperationEnable,
	EfiPciIoAttributeOperationDisable,
	EfiPciIoAttributeOperationSupported,
	EfiPciIoAttributeOperationMaximum
}EFI_PCI_IO_PROTOCOL_ATTRIBUTE_OPERATION;

/* Various EFI statuses and all. Reference the spec for the full list and all. */
typedef enum EFI_STATUS
{
	EFI_SUCCESS = 0,

	/* High bit set. The shifting number is defined in efibind.h */

	EFI_LOAD_ERROR = 		(1  | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_INVALID_PARAMETER = 	(2  | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_UNSUPPORTED = 		(3  | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_BAD_BUFFER_SIZE = 		(4  | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_BUFFER_TOO_SMALL = 		(5  | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_NOT_READY = 		(6  | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_DEVICE_ERROR = 		(7  | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_WRITE_PROTECTED = 		(8  | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_OUT_OF_RESOURCES = 		(9  | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_VOLUME_CORRUPTED = 		(10 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_VOLUME_FULL = 		(11 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_NO_MEDIA = 			(12 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_MEDIA_CHANGED = 		(13 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_NOT_FOUND = 		(14 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_ACCESS_DENIED =		(15 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_NO_RESPONSE = 		(16 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_NO_MAPPING = 		(17 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_TIMEOUT = 			(18 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_NOT_STARTED = 		(19 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_ALREADY_STARTED = 		(20 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_ABORTED = 			(21 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_ICMP_ERROR = 		(22 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_TFTP_ERROR = 		(23 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_PROTOCOL_ERROR = 		(24 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_INCOMPATIBLE_VERSION = 	(25 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_SECURITY_VIOLATION = 	(26 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_CRC_ERROR = 		(27 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_END_OF_MEDIA = 		(28 | ((1L) << BITSHIFT_LEFT_NUM)),

	/* EFI Spec reserved between 28 and 31. */

	EFI_END_OF_FILE = 		(31 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_INVALID_LANGUAGE = 		(32 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_COMPROMISED_DATA =		(33 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_IP_ADDRESS_CONFLICT = 	(34 | ((1L) << BITSHIFT_LEFT_NUM)),
	EFI_HTTP_ERROR = 		(35 | ((1L) << BITSHIFT_LEFT_NUM))
}EFI_STATUS;

typedef struct
{
	EFI_STATUS* Read;
	EFI_STATUS* Write;	//These are both ultimately functions.
}EFI_PCI_IO_PROTOCOL_CONFIG_ACCESS;

typedef struct
{
	EFI_STATUS* Read;
	EFI_STATUS* Write;	//This and the above are the same, essentially. Only difference is what functions they point to.
}EFI_PCI_IO_PROTOCOL_ACCESS;

typedef struct 
{
	UINT32 Type;				//Type of memory region.
	EFI_PHYSICAL_ADDRESS PhysicalStart;	//Location where the memory starts. Aligned to 4KB pages.	(Cannot be > 0xfffffffffffff000.)
	EFI_VIRTUAL_ADDRESS VirtualStart;	//Location where the memory starts (in virtual address space). Aligned to 4KB pages. (Cannot be > 0xfffffffffffff000.)
	UINT64 NumberOfPages;			//Number of 4KB pages in the region.
	UINT64 Attribute;			//Attributes of the memory block.
}EFI_MEMORY_DESCRIPTOR;

typedef struct
{
	EFI_GUID Guid;
	UINT32 HeaderSize;
	UINT32 Flags;
	UINT32 ImageSize;
}EFI_CAPSULE_HEADER;

typedef struct
{
	UINT16 Year; 		//1990 - 20XX.
	UINT8 Month; 		//1 - 12
	UINT8 Day; 		//1 - 31
	UINT8 Hour;		//0 - 23
	UINT8 Minute;		//0 - 59
	UINT8 Second;		//0 - 59
	UINT8 Pad1;
	UINT32 Nanosecond;	// 0 - 999999999
	INT16 TimeZone;		//-1440 to 1440 or 2047 Subtract UTC time with this.
	UINT8 Daylight;
	UINT8 Pad2;
}EFI_TIME;

typedef struct
{
	UINT32 Resolution;
	UINT32 Accuracy;
	BOOLEAN SetsToZero;
}EFI_TIME_CAPABILITIES;

typedef struct
{
	UINT64 Signature;	//Identify this type of table.
	UINT32 Revision;	//Version of UEFI this platform supports.
	UINT32 HeaderSize;	//Size, in bytes of the ENTIRE table.
	UINT32 CRC32;		//CRC32 of the entire table.
	UINT32 Reserved;	//Field that MUST be set to 0. Reserved by UEFI spec.
}EFI_TABLE_HEADER;

typedef struct
{
	EFI_GUID VendorGuid;	//Unique identifier for system config.
	VOID* VendorTable;	//Pointer to relevant table. Can be virtual or physical. See the spec for info, 2.7's page 185 (in the PDF, 115 on the actual page number).
}EFI_CONFIGURATION_TABLE;

typedef struct
{
	EFI_TABLE_HEADER Hdr;
	EFI_STATUS RaiseTpl;
	EFI_STATUS RestoreTpl;
	EFI_STATUS AllocatePages;
	EFI_STATUS FreePages;
	EFI_STATUS GetMemoryMap;
	EFI_STATUS AllocatePool;
	EFI_STATUS FreePool;
	EFI_STATUS CreateEvent;
	EFI_STATUS SetTimer;
	EFI_STATUS WaitForEvent;
	EFI_STATUS SignalEvent;
	EFI_STATUS CloseEvent;
	EFI_STATUS CheckEvent;
	EFI_STATUS InstallProtocolInterface;
	EFI_STATUS ReinstallProtocolInterface;
	EFI_STATUS UninstallProtocolInterface;
	EFI_STATUS HandleProtocol;
	EFI_STATUS __Reserved__;
	EFI_STATUS RegisterProtocolNotify;
	EFI_STATUS LocateHandle;
	EFI_STATUS LocateDevicePath;
	EFI_STATUS InstallConfigurationTable;
	EFI_STATUS LoadImage;
	EFI_STATUS StartImage;
	EFI_STATUS Exit;
	EFI_STATUS UnloadImage;
	EFI_STATUS ExitBootServices;
	EFI_STATUS GetNextMonotonicCount;
	EFI_STATUS Stall;
	EFI_STATUS SetWatchdogTimer;
	EFI_STATUS ConnectController;
	EFI_STATUS DisconnectController;
	EFI_STATUS OpenProtocol;
	EFI_STATUS CloseProtocol;
	EFI_STATUS OpenProtocolInformation;
	EFI_STATUS ProtocolsPerHandle;
	EFI_STATUS LocateHandleBuffer;
	EFI_STATUS LocateProtocol;
	EFI_STATUS InstallMultipleProtocolInterfaces;
	EFI_STATUS UninstallMultipleProtocolInterfaces;
	EFI_STATUS CalculateCrc32;
	EFI_STATUS CopyMem;
	EFI_STATUS SetMem;
	EFI_STATUS CreateEventEx;
}EFI_BOOT_SERVICES;


typedef struct
{
	EFI_STATUS PollMem;
	EFI_STATUS PollIo;

	EFI_PCI_IO_PROTOCOL_ACCESS Mem;
	EFI_PCI_IO_PROTOCOL_ACCESS Io;

	EFI_PCI_IO_PROTOCOL_CONFIG_ACCESS Pci;
	
	EFI_STATUS CopyMem;
	EFI_STATUS Map;
	EFI_STATUS Unmap;
	
	EFI_STATUS AllocateBuffer;
	EFI_STATUS FreeBuffer;
	
	EFI_STATUS Flush;
	EFI_STATUS GetLocation;
	EFI_STATUS Attributes;
	EFI_STATUS GetBarAttributes;
	EFI_STATUS SetBarAttributes;
	
	UINT64 RomSize;
	VOID* RomImage;
	
}EFI_PCI_IO_PROTOCOL;

typedef struct
{
	EFI_TABLE_HEADER Hdr;
	EFI_STATUS GetTime;
	EFI_STATUS SetTime;
	EFI_STATUS GetWakeupTime;
	EFI_STATUS SetWakeupTime;
	EFI_STATUS SetVirtualAddressMap;
	EFI_STATUS ConvertPointer;
	EFI_STATUS GetVariable;
	EFI_STATUS GetNextVariable;
	EFI_STATUS SetVariable;	
	EFI_STATUS GetNextHighMonoCount;
	EFI_STATUS ResetSystem;
	EFI_STATUS UpdateCapsule;
	EFI_STATUS QueryCapsuleCaps;
	EFI_STATUS QueryVariableInfo;
}EFI_RUNTIME_SERVICES;


typedef struct
{
	INT32 MaxMode;
	
	//Current settings...
	INT32 Mode;
	INT32 Attribute;
	INT32 CursorColumn;
	INT32 CursorVisible;
}SIMPLE_TEXT_OUTPUT_MODE;


typedef struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
	EFI_STATUS Reset;
	EFI_STATUS OutputString;
	EFI_STATUS TestString;
	EFI_STATUS QueryMode;
	EFI_STATUS SetMode;
	EFI_STATUS SetAttribute;
	EFI_STATUS ClearScreen;
	EFI_STATUS SetCursorPosition;
	EFI_STATUS EnableCursor;
	SIMPLE_TEXT_OUTPUT_MODE* Mode;
	
}EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

typedef struct
{
	EFI_STATUS Reset;
	EFI_STATUS ReadKeyStroke;
	VOID* WaitForKey;
}EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef struct
{
	EFI_TABLE_HEADER Hdr;	 //The header for the system table, see the above struct.
	CHAR16* FirmwareVendor;	 //Firmware vendor: who makes the ROM EFI firmware?
	UINT32 FirmwareRevision; //What version of UEFI does this firmware support?
	
	VOID* ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL* ConIn;

	VOID* ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* ConOut;

	VOID* StandardErrorHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* StdErr;

	EFI_RUNTIME_SERVICES* RuntimeServices;
	EFI_BOOT_SERVICES* BootServices;

	UINTN NumberOfTableEntries;

	EFI_CONFIGURATION_TABLE* ConfigurationTable;
}EFI_SYSTEM_TABLE;

/* Runtime definitions... */
typedef EFI_STATUS GetTime(EFI_TIME* Time, EFI_TIME_CAPABILITIES* Capabilities);
typedef EFI_STATUS SetTime(EFI_TIME* Time);

typedef EFI_STATUS GetWakeupTime(BOOLEAN* Enabled, BOOLEAN* Pending, EFI_TIME* Time);
typedef EFI_STATUS SetWakeupTime(BOOLEAN* Enabled, EFI_TIME* Time);

typedef EFI_STATUS SetVirtualAddressMap(UINTN MemoryMapSize, UINTN DescriptorSize, UINT32 DescriptorVersion, EFI_MEMORY_DESCRIPTOR* VirtualMap);

typedef EFI_STATUS GetVariable(CHAR16* Name, EFI_GUID* Vendor, UINT32* Attributes, UINTN* DataSize, VOID* Data);
typedef EFI_STATUS GetNextVariable(UINTN* NameSize, CHAR16* Name, EFI_GUID* Vendor);
typedef EFI_STATUS SetVariable(CHAR16* Name, EFI_GUID* Vendor, UINT32 Attributes, UINTN DataSize, VOID* data);

typedef EFI_STATUS GetNextHighMonoCount(UINT32* Count);

typedef EFI_STATUS ResetSystem(EFI_RESET_TYPE ResetType, EFI_STATUS Status, UINTN DataSize, VOID* Data);

typedef EFI_STATUS UpdateCapsule(EFI_CAPSULE_HEADER** Capsules, UINTN Count, EFI_PHYSICAL_ADDRESS ScatterGatherList);

typedef EFI_STATUS QueryCapsuleCapabilities(EFI_CAPSULE_HEADER** Capsules, UINTN Count, UINT64* MaximumCapsuleSize, EFI_RESET_TYPE* ResetType);
typedef EFI_STATUS QueryVariableInfo(UINT32 Attributes, UINT64* StorageSpace, UINT64* RemainingSpace, UINT64* MaxVariableSpace);


/* Boot services definitions... */






/** Defines some things we'll need for UEFI through the kernel setup and all... **/

/* Global stuff we'll want. */
EFI_SYSTEM_TABLE* gST;
EFI_RUNTIME_SERVICES* gRS;
EFI_BOOT_SERVICES* gBS;

VOID* gHandle;

void Print(CHAR16* str);
void PrintLine(CHAR16* str);
void LoadDrivers(VOID* Folder);


/* Might as well. */
static inline void InitializeUefi(VOID* ImageHandle, EFI_SYSTEM_TABLE* SystemTable)
{
	gST = SystemTable;
	gBS = SystemTable->BootServices;
	gRS = SystemTable->RuntimeServices;
}

/* 
	We expect efistub.c to link up with kernel_main.c and just call the kernel's main function once it's done setting up the EFI environment.
	We should call ExitBootServices() before calling kernel_main, but not until we load up drivers in /EFI/Waypoint/Drivers/. 
 */

#endif
