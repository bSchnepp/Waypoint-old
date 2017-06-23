/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */

/*
	Declarations of core parts of the UEFI spec.
	[Note we refer to UEFI as 'UEFI' and 'EFI' interchangably]
 */

#ifndef _LIBRE_EFI_DECL_INCLUDE_
#define _LIBRE_EFI_DECL_INCLUDE_




#define EFI_SYSTEM_TABLE_SIGNATURE     0x5453595320494249

#define EFI_2_70_SYSTEM_TABLE_REVISION ((2<<16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2<<16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2<<16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2<<16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2<<16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2<<16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2<<16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2<<16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2<<16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1<<16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1<<16) | (02))

#define EFI_SYSTEM_TABLE_REVISION      EFI_2_50_SYSTEM_TABLE_REVISION	//TEMPORARY, TO ENSURE THAT IT WORKS ON TEST HARDWARE. WHEN ZEN CPU + BOARD COMES, TEST ON THAT!!!! WE'RE REALLY 2.7!!!
									//Too busy writing code to bother updating my UEFI firmware to 2.7 on the N3700.

#define EFI_SPECIFICATION_VERSION      EFI_SYSTEM_TABLE_REVISION

#define EFI_BOOT_SERVICES_SIGNATURE    0x56524553544F4F42
#define EFI_BOOT_SERVICES_REVISION     EFI_SPECIFICATION_VERSION

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544E5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

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
	EFI_TABLE_HEADER Hdr;	 //The header for the system table, see the above struct.
	CHAR16* FirmwareVendor;	 //Firmware vendor: who makes the ROM EFI firmware?
	UINT32 FirmwareRevision; //What version of UEFI does this firmware support?
	
	EFI_HANDLE ConsoleInHandle;
	EFI_SIMPLE_TEXT_INPUT_PROTOCOL* ConIn;

	EFI_HANDLE ConsoleOutHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* ConOut;

	EFI_HANDLE StandardErrorHandle;
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* StdErr;

	EFI_RUNTIME_SERVICES* RuntimeServices;
	EFI_BOOT_SERVICES* BootServices;

	UINTN NumberOfTableEntries;

	EFI_CONFIGURATION_TABLE* ConfigurationTable;
}EFI_SYSTEM_TABLE;

typedef struct
{
	EFI_TABLE_HEADER Hdr;	//Header for boot services.
	EFI_RAISE_TPL RaiseTPL;	//Task priority level.
	EFI_RESTORE_TPL RestoreTPL;

	EFI_ALLOCATE_PAGES AllocatePages;	//Allocates pages of memory.
	EFI_FREE_PAGES FreePages;		//Deletes pages of memory.
	EFI_GET_MEMORY_MAP GetMemoryMap;	//Gets the memory map.
	EFI_ALLOCATE_POOL AllocatePool;		//Allocates a pool of memory... kinda like a malloc().
	EFI_FREE_POOL FreePool;			//Frees a pool of memory.
	
	EFI_CREATE_EVENT CreateEvent;		//Creates a general-purpose event structure.
	EFI_SET_TIMER SetTimer;			//Sets event to be scheduled at a particular time.
	EFI_WAIT_FOR_EVENT WaitForEvent;	//Stops execution until event is called. Essentially a flush().
	EFI_SIGNAL_EVENT SignalEvent;		//Signals an event.
	EFI_CLOSE_EVENT CloseEvent;		//Closes + frees event structure.
	EFI_CHECK_EVENT CheckEvent;		//Check if event is signaled.

	EFI_INSTALL_PROTOCOL_INTERFACE InstallProtocolInterface;
	EFI_REINSTALL_PROTOCOL_INTERFACE ReinstallProtocolInferface;
	EFI_UNINSTALL_PROTOCOL_INTERFACE UninstallProtocolInterface;

	EFI_HANDLE_PROTOCOL HandleProtocol;

	VOID* Reserved;	//Unused in UEFI right now.

	EFI_REGISTER_PROTOCOL_NOTIFY RegisterProtocolNotify;
	EFI_LOCATE_HANDLE LocateHandle;
	EFI_LOCATE_DEVICE_PATH LocateDevicePath;
	EFI_INSTALL_CONFIGURATION_TABLE InstallConfigurationTable;
	
	EFI_IMAGE_LOAD LoadImage;	//Loads an EFI image into memory. 
	EFI_IMAGE_START StartImage;	//Transfers control to a loaded image’s entry point. 

	EFI_EXIT Exit;			//Exit progam's entry point.
	EFI_IMAGE_UNLOAD UnloadImage;	//Unloads an image.
	EFI_EXIT_BOOT_SERVICES ExitBootServices;	//Shuts down the boot services.

	EFI_GET_NEXT_MONOTONIC_COUNT GetNextMonotonicCount;
	EFI_STALL Stall;	//Stalls the processor for some time.
	EFI_SET_WATCHDOG_TIMER SetWatchdogTimer;

	EFI_CONNECT_CONTROLLER ConnectController;
	EFI_DISCONNECT_CONTROLLER DisconnectController;
	
	EFI_OPEN_PROTOCOL OpenProtocol;
	EFI_CLOSE_PROTOCOL CloseProtocol;
	EFI_OPEN_PROTOCOL_INFORMATION OpenProtocolInformation;

	EFI_PROTOCOLS_PER_HANDLE ProtocolsPerHandle;
	EFI_LOCATE_HANDLE_BUFFER LocateHandleBuffer;
	EFI_LOCATE_PROTOCOL LocateProtocol;
	EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES InstallMultipleProtocolInterfaces;
	EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES UninstallMultipleProtocolInterfaces;

	EFI_CALCULATE_CRC32 CalculateCrc32;
	
	EFI_COPY_MEM CopyMem;	//Copies from one buffer to another.
	EFI_SET_MEM SetMem;	//Fills a buffer with a value.
	EFI_CREATE_EVENT_EX CreateEventEx;	//Creates event structure as part of an event group.
}EFI_BOOT_SERVICES;


typedef struct 
{
	EFI_TABLE_HEADER Hdr;	//Header for runtime services.
	
	/* Time services */
	EFI_GET_TIME GetTime;
	EFI_SET_TIME SetTime;

	EFI_GET_WAKEUP_TIME GetWakeupTime;
	EFI_SET_WAKEUP_TIME SetWakeupTime;

	/* Virtual memory services */
	EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
	EFI_CONVERT_POINTER ConvertPointer;

	/* Variable services... */
	EFI_GET_VARIABLE GetVariable;
	EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
	EFI_SET_VARIABLE SetVariable;
	
	/* Miscellaneous Services */
	EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
	EFI_RESET_SYSTEM ResetSystem;
	
	/* Capsule Services */
	EFI_UPDATE_CAPSULE UpdateCapsule;
	EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;

	/* Misc UEFI 2.0+ services */
	EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
}EFI_RUNTIME_SERVICES;

typedef struct
{
	EFI_GUID VendorGuid;	//Unique identifier for system config.
	VOID* VendorTable;	//Pointer to relevant table. Can be virtual or physical. See the spec for info, 2.7's page 185 (in the PDF, 115 on the actual page number).
}EFI_CONFIGURATION_TABLE;




#endif
