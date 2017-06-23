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


typedef EFI_STATUS (EFIAPI *EFI_CREATE_EVENT)(
	IN UINT32 Type,
	IN EFI_TPL NotifyTpl,
	IN EFI_EVENT_NOTIFY NotifyFunction, OPTIONAL 
	IN VOID *NotifyContext, OPTIONAL 
	OUT EFI_EVENT *Event
);	
//Probably right...?
//TODO: Refactor to get events out of boot services.

typedef VOID (EFIAPI *EFI_EVENT_NOTIFY)(
	IN EFI_EVENT Event,
	IN VOID* Context
);

typedef EFI_STATUS (EFIAPI *EFI_CREATE_EVENT_EX)(
	IN UINT32 Type,
	IN EFI_TPL NotifyTpl,
	IN EFI_EVENT_NOTIFY NotifyFunction OPTIONAL,
	IN CONST VOID* NotifyContext OPTIONAL,
	IN CONST EFI_GUID *EventGroup OPTIONAL,
	OUT EFI_EVENT *Event
);

typedef EFI_STATUS (EFIAPI *EFI_CLOSE_EVENT)(
	IN EFI_EVENT Event
);

typedef EFI_STATUS (EFIAPI *EFI_SIGNAL_EVENT)(
	IN EFI_EVENT Event
);

/* (PDF) Page 242 of EFI spec 2.7 */

typedef EFI_STATUS (EFIAPI *EFI_WAIT_FOR_EVENT)(
	INT UINTN NumberOfEvents,
	IN EFI_EVENT *Event,
	OUT UINTN *Index
);

/* Check event if it's in signaled state or not. */
typedef EFI_STATUS (EFIAPI *EFI_CHECK_EVENT)(
	IN EFI_EVENT Event
)

;



#endif
