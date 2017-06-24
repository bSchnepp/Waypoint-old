/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */



#ifndef _LIBRE_EFI_BOOT_INCLUDE_
#define _LIBRE_EFI_BOOT_INCLUDE_

#define EVT_TIMER 0x80000000
#define EVT_RUNTIME 0x40000000
#define EVT_NOTIFY_WAIT 0x00000100
#define EVT_NOTIFY_SIGNAL 0x00000200
#define EVT_SIGNAL_EXIT_BOOT_SERVICES 0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE 0x60000202

#define EFI_EVENT_GROUP_EXIT_BOOT_SERVICES				\
	{								\
		0x27ABF055, 0xB1B8, 0x4C26, 				\
		{							\
		 	0x80, 0x48, 0x74, 0x8F, 0x37, 0xBA, 0xA2, 0xDF	\
		}							\
	}

#define EFI_EVENT_GROUP_VIRTUAL_ADDRESS_CHANGE				\
	{								\
		0x13FA7698, 0xC831, 0x49C7, 				\
		{							\
		 	0x87, 0xEA, 0x8F, 0x43, 0xFC, 0xC2, 0x51, 0x96	\
		}							\
	}

#define EFI_EVENT_GROUP_MEMORY_MAP_CHANGE 				\
	{								\
		0x78BEE926, 0x692F, 0x48FD,				\
		{ 							\
			0x9E, 0xDB, 0x01, 0x42, 0x2E, 0xF0, 0xD7, 0xAB	\
		}							\
	}				

#define EFI_EVENT_GROUP_READY_TO_BOOT 					\
	{								\
		0x7CE88FB3, 0x4BD7, 0x4679,				\
		{ 							\
			0x87, 0xA8, 0xA8, 0xD8, 0xDE, 0xE5, 0x0D, 0x2B	\
		}							\
	}

#define EFI_EVENT_GROUP_RESET_SYSTEM 					\
	{								\
		0x62DA6A56, 0x13FB, 0x485A,				\
		{ 							\
			0xA8, 0xDA, 0xA3, 0xDD, 0x79, 0x12, 0xCB, 0x6B	\
		}							\
	}



typedef VOID* EFI_EVENT;

typedef enum 
{
	EFI_NATIVE_INTERFACE
}EFI_INTERFACE_TYPE;

typedef enum
{
	TimerCancel,
	TimerPeriodic,
	TimerRelative
}EFI_TIMER_DELAY;

typedef UINT64 EFI_PHYSICAL_ADDRESS;
typedef UINT64 EFI_VIRTUAL_ADDRESS;

typedef enum
{
	AllocateAnyPages,
	AllocateMaxAddress,
	AllocateAddress,
	MaxAllocateType
}EFI_ALLOCATE_TYPE;

typedef enum
{
	EfiReservedMemoryType,
	EfiLoaderCode,
	EfiLoaderData,
	EfiBootServicesCode,
	EfiBootServicesData,
	EfiRuntimeServicesCode,
	EfiRuntimeServicesData,
	EfiConventionalMemory,
	EfiUnusableMemory,
	EfiACPIReclaimMemory,
	EfiACPIMemoryNVS,
	EfiMemoryMappedIO,
	EfiMemoryMappedIOPortSpace,
	EfiPalCode,
	EfiPersistentMemory,
	EfiMaxMemoryType
}EFI_MEMORY_TYPE;

typedef struct 
{
	UINT32 Type;	//Type of memory region.
	EFI_PHYSICAL_ADDRESS PhysicalStart;	//Location where the memory starts. Aligned to 4KB pages.	(Cannot be > 0xfffffffffffff000.)
	EFI_VIRTUAL_ADDRESS VirtualStart;	//Location where the memory starts (in virtual address space). Aligned to 4KB pages. (Cannot be > 0xfffffffffffff000.)
	UINT64 NumberOfPages;	//Number of 4KB pages in the region.
	UINT64 Attribute;	//Attributes of the memory block.
}EFI_MEMORY_DESCRIPTOR;




//Come back to this...
typedef EFI_STATUS (EFIAPI *EFI_CREATE_EVENT)(IN UINT32 Type, IN EFI_TPL NotifyTpl, IN EFI_EVENT_NOTIFY NotifyFunction, OPTIONAL IN VOID* NotifyContext, OPTIONAL OUT EFI_EVENT* Event);	

typedef VOID (EFIAPI *EFI_EVENT_NOTIFY)(IN EFI_EVENT Event, IN VOID* Context);

typedef EFI_STATUS (EFIAPI *EFI_CREATE_EVENT_EX)(IN UINT32 Type, IN EFI_TPL NotifyTpl, IN EFI_EVENT_NOTIFY NotifyFunction OPTIONAL, IN CONST VOID* NotifyContext OPTIONAL, IN CONST EFI_GUID* EventGroup OPTIONAL, OUT EFI_EVENT* Event);

typedef EFI_STATUS (EFIAPI *EFI_CLOSE_EVENT)(IN EFI_EVENT Event);

typedef EFI_STATUS (EFIAPI *EFI_SIGNAL_EVENT)(IN EFI_EVENT Event);

/* (PDF) Page 242 of EFI spec 2.7 */

typedef EFI_STATUS (EFIAPI *EFI_WAIT_FOR_EVENT)(INT UINTN NumberOfEvents, IN EFI_EVENT* Event, OUT UINTN* Index);

/* Check event if it's in signaled state or not. */
typedef EFI_STATUS (EFIAPI *EFI_CHECK_EVENT)(IN EFI_EVENT Event);


//From here, we just replace tabs with 8 spaces. FINE.
typedef EFI_STATUS (EFIAPI *EFI_SET_TIMER)(
        IN EFI_EVENT Event,	//Defined in CreateEvent()...
        IN EFI_TIMER_DELAY Type,
        IN UINT64 TriggerTime
);

/* Raises a task's TPL, returns previous TPL.  */
typedef EFI_TPL (EFIAPI *EFI_RAISE_TPL)(
        IN EFI_TPL NewTpl
);

/* Restores a task's TPL. */
typedef VOID (EFIAPI *EFI_RESTORE_TPL)(
        IN EFI_TPL OldTPl
);







/** MEMORY ALLOCATION SERVICES **/
/* PDF page 252 (Just under 10% done!) */




/* 
	See PDF page 260 for the stuff behind these #defines... 
	These defines can be ORed together in the memory descriptor.
 */
#define EFI_MEMORY_UC 				0x0000000000000001
#define EFI_MEMORY_WC 				0x0000000000000002
#define EFI_MEMORY_WT 				0x0000000000000004
#define EFI_MEMORY_WB 				0x0000000000000008
#define EFI_MEMORY_UCE 				0x0000000000000010
#define EFI_MEMORY_WP 				0x0000000000001000
#define EFI_MEMORY_RP 				0x0000000000002000
#define EFI_MEMORY_XP 				0x0000000000004000
#define EFI_MEMORY_NV 				0x0000000000008000
#define EFI_MEMORY_MORE_RELIABLE 		0x0000000000010000
#define EFI_MEMORY_RO 				0x0000000000020000
#define EFI_MEMORY_RUNTIME 			0x8000000000000000


#define EFI_MEMORY_DESCRIPTOR_VERSION 1




/* Function prototypes... */


typedef EFI_STATUS (EFIAPI *EFI_ALLOCATE_PAGES)(
        IN EFI_ALLOCATE_TYPE Type,
        IN EFI_MEMORY_TYPE MemoryType,
        IN UINTN Pages,
        IN OUT EFI_PHYSICAL_ADDRESS* Memory
);

typedef EFI_STATUS (EFIAPI *EFI_FREE_PAGES)(
        IN EFI_PHYSICAL_ADDRESS Memory,	//Base address to be freed.
        IN UINTN Pages			//Number of pages to free. (Contiguous, 4KB each)
);

/* PDF page 258 */
typedef EFI_STATUS (EFIAPI *EFI_GET_MEMORY_MAP)(
        IN OUT UINTN *MemoryMapSize,			//Pointer to size (in bytes) of MemoryMap buffer.
        IN OUT EFI_MEMORY_DESCRIPTOR *MemoryMap,	//Where firmware puts current memory map
        OUT UINTN *MapKey,				//Location of current key
        OUT UINTN *DescriptorSize,			//Pointer to Size (in bytes) of individual descriptor.
        OUT UINT32 *DescriptorVersion			//Version number associated with descriptor.
);

typedef EFI_STATUS (EFIAPI *EFI_ALLOCATE_POOL)(
        IN EFI_MEMORY_TYPE PoolType;
        IN UINTN Size;
        OUT VOUD** Buffer;
);

typedef EFI_STATUS (EFIAPI *EFI_FREE_POOL)(
        IN VOID* Buffer;
);



/**	Protocol interfaces and all.	 **/
/* TODO: Move this into it's own header. ~pg. 266 in the PDF. */

#define EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL 		0x00000001
#define EFI_OPEN_PROTOCOL_GET_PROTOCOL 			0x00000002
#define EFI_OPEN_PROTOCOL_TEST_PROTOCOL 		0x00000004
#define EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER 		0x00000008
#define EFI_OPEN_PROTOCOL_BY_DRIVER 			0x00000010
#define EFI_OPEN_PROTOCOL_EXCLUSIVE 			0x00000020

typedef enum
{
	AllHandles,	
	ByRegisterNotify,
	ByProtocol
}EFI_LOCATE_SEARCH_TYPE;

typedef struct
{
	EFI_HANDLE AgentHandle;
	EFI_HANDLE ControllerHandle
	UINT32 Attributes;
	UINT32 OpenCount;
}EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;

typedef EFI_STATUS (EFIAPI *EFI_INSTALL_PROTOCOL_INTERFACE)(
        IN OUT EFI_HANDLE* Handle,
        IN EFI_GUID8 Protocol,
        IN EFI_INTERFACE_TYPE InterfaceType,
        IN VOID* Interface
);

typedef EFI_STATUS (EFIAPI *EFI_UNINSTALL_PROTOCOL_INTERFACE)(
        IN EFI_HANDLE Handle,
	IN EFI_GUID* Protocol,
        IN VOID* Interface
);

typedef EFI_STATIS (EFIAPI *EFI_REINSTALL_PROTOCOL_INTERFACE)(
        IN EFI_HANDLE Handle,
        IN EFI_GUID *Protocol,
        IN VOID* OldInterface,
        IN VOID* NewInterface
);

typedef EFI_STATUS (EFIAPI *EFI_REGISTER_PROTOCOL_NOTIFY)(
        IN EFI_GUID* Protocol,
        IN EFI_EVENT Event,
        OUT VOID** Registration
);

typedef EFI_STATUS (EFIAPI *EFI_LOCATE_HANDLE)(
        IN EFI_LOCATE_SEARCH_TYPE SearchType,
        IN EFI_GUID *Protocol OPTIONAL,
        IN VOID *SearchKey OPTIONAL,
        IN OUT UINTN* BufferSize,
        OUT EFI_HANDLE* Buffer
);

typedef EFI_STATUS (EFIAPI *EFI_HANDLE_PROTOCOL)(
        IN EFI_HANDLE Handle;
        IN EFI_GUID* Protocol,
        OUT VOID** Interface
);

typedef EFI_STATUS (EFIAPI *EFI_LOCATE_DEVICE_PATH)(
        IN EFI_GUID* Protocol,
        IN OUT EFI_DEVICE_PATH_PROTOCOL** DevicePath,
        OUT EFI_HANDLE* Device
);

typedef EFI_STATUS (EFIAPI *EFI_OPEN_PROTOCOL)(
        IN EFI_HANDLE Handle,
        IN EFI_GUID* Protocol,
        OUT VOID** Interface OPTIONAL,
        IN EFI_HANDLE AgentHandle,
        IN EFI_HANDLE ControllrHandle,
        IN UINT32 Attributes
);


typedef EFI_STATUS (EFIAPI *EFI_CLOSE_PROTOCOL)(
        IN EFI_HANDLE Handle,
        IN EFI_GUID* Protocol,
        IN EFI_HANDLE AgentHandle,
        IN EFI_HANDLE ControllerHandle
);

typedef EFI_STATUS (EFIAPI *EFI_OPEN_PROTOCOL_INFORMATION)(
        IN EFI_HANDLE Handle,
        IN EFI_GUID* Protocol,
        OUT EFI_OPEN_PROTOCOL_INFORMATION_ENTRY** EntryBuffer,
        OUT UINTN* EntryCount
);

typedef EFI_STATUS (EFIAPI *EFI_CONNECT_CONTROLLER)(
        IN EFI_HANDLE ControllerHandle,

);

typedef EFI_STATUS (EFIAPI *EFI_CONNECT_CONTROLLER)(
        IN EFI_HANDLE ControllerHandle,
        IN EFI_HANDLE* DriverImageHandle OPTIONAL,
        IN EFI_DEVICE* RemainingDevicePath OPTIONAL
        IN BOOLEAN Recursive
);

typedef EFI_STATUS (EFIAPI *EFI_DISCONNECT_CONTROLLER)(
        IN EFI_HANDLE ControllerHandle,
        IN EFI_HANDLE DriverImageHandle OPTIONAL,
        IN EFI_HANDLE ChildHandle OPTIONAL
);

typedef EFI_STATUS (EFIAPI *EFI_DISCONNECT_CONTROLLER)(
        IN EFI_HANDLE ControllerHandle,
        IN EFI_HANDLE DriverImageHandle OPTIONAL,
        IN EFI_HANDLE ChildHandle OPTIONAL
);

typedef EFI_STATUS (EFIAPI *EFI_PROTOCOLS_PER_HANDLE)(
        IN  EFI_HANDLE Handle,
        OUT EFI_GUID*** ProtocolBuffer,
        OUT UINTN* ProtocolBufferCount
);

typedef EFI_STATUS (EFIAPI *EFI_LOCATE_HANDLE_BUFFER)(
        IN EFI_LOCATE_SEARCH_TYPE SearchType,
        IN EFI_GUID* Protocol OPTIONAL,
        IN VOID* OPTIONAL,
        IN OUT UINTN* NoHandles,
        OUT EFI_HANDLE** Buffer
);

typedef EFI_STATUS (EFIAPI *EFI_LOCATE_PROTOCOL)(
        IN  EFI_GUID* Protocol,
        IN  VOID* Registration OPTIONAL,
        OUT VOID** Interface
);

typedef EFI_STATUS (EFIAPI *EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES)(
        IN OUT EFI_HANDLE* Handle,
        ...
);

typedef EFI_STATUS (EFIAPI *EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES)(
        IN EFI_HANDLE Handle,
        ...
);


/** Section 7.4: Image services. **/
/* PDF page 312 */

typedef EFI_STATUS (EFIAPI *EFI_IMAGE_LOAD)(
        IN BOOLEAN BootPolicy,
        IN EFI_HANDLE ParentImageHandle,
        IN EFI_DEVICE_PATH_PROTOCOL* DevicePath,
        IN VOID* SourceBuffer OPTIONAL,
        IN UINTN SourceSize,
        OUT EFI_HANDLE* ImageHandle
);

/* Transfers control to relevant program loaded by ImageLoad() */
typedef EFI_STATUS (EFIAPI *EFI_IMAGE_START)(
        IN EFI_HANDLE ImageHandle,
        OUT UINTN* ExitDataSize,
        OUT CHAR16** ExitData OPTIONAL
);

/* Unloads a function if it's been loaded with ImageLoad(). If done on one with StartImage(), calls the Unload() function. */
typedef EFI_STATUS (EFIAPI *EFI_IMAGE_UNLOAD)(
        IN EFI_HANDLE ImageHandle
);

/* Entry point to UEFI applications. */
typedef EFI_STATUS (EFIAPI *EFI_IMAGE_ENTRY_POINT)(
        IN EFI_HANDLE ImageHandle
        IN EFI_SYSTEM_TABLE* SystemTable
);

/* Terminates control from UEFI program and returns to the firmware. */
typedef EFI_STATUS (EFIAPI *EFI_EXIT)(
        IN EFI_HANDLE ImageHandle,
        IN EFI_STATUS ExitStatus,
        IN UINTN ExitDataSize,
        IN CHAR16* ExitData OPTIONAL
);

/* Really really really shuts down boot services. Needed by OS loaders. */
typedef EFI_STATUS (EFIAPI *EFI_EXIT_BOOT-SERVICES)(
        IN EFI_HANDLE ImageHandle,
        IN UINTN MapKey
);



/** Misc. boot services, PDF page 327. **/

/* Watchdog timer. Usually set to 5 minutes since boot. Once it goes off, the system WILL reset (ie, reboot). ExitBootServices() terminates it. */
typedef EFI_STATUS (EFIAPI *EFI_SET_WATCHDOG_TIMER)(
        IN UINTN Timeout,
        IN UINT64 WatchdogCode,
        IN UINTN DataSize,
        IN CHAR16* WatchdogData OPTIONAL
);

/* Stalls the system. Input is in microseconds. Multiply by 1000000 to get seconds. */
typedef EFI_STATUS (EFIAPI *EFI_STALL)(
        IN UINTN Microseconds
);

/* Copies Length bytes from Source buffer into Destination buffer. Ensure there is enough memory there. */
typedef VOID (EFIAPI *EFI_COPY_MEM)(
        IN VOID* Destination,
        IN VOID* Source,
        IN UINTN Length
);

/* Fills a buffer of size Size with Value at every 8-bit entry. */
typedef VOID (EFIAPI *EFI_SET_MEM)(
        IN VOID* Buffer,
        IN UINTN Size,
        IN UINT8 Value
);

/* Number that increases on each call. Top 32 bits are non-volatile and only increase when system is reset or lower overflows. */
typedef EFI_STATUS (EFIAPI *EFI_GET_NEXT_MONOTONIC_COUNT)(
        OUT UINT64* Count
);


/* Adds, updates, or removes from EFI configuration table (in EFI System Table) */
typedef EFI_STATUS (EFIAPI *EFI_INSTALL_CONFIGURATION_TABLE)(
        IN EFI_GUID* Guid,
        IN VOID* Table
);

/* Computes the CRC32 hash of a particular buffer. */
typedef EFI_STATUS (EFIAPI *EFI_CALCULATE_CRC32)(
        IN VOID* Data,
        IN UINTN DataSize,
        OUT UINT32* Crc32
);
#endif
