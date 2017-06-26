/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

/*
	Definitions for a bunch of GUIDs that EFI wants.
 */

#ifndef _EFI_STUB_GUID_INCLUDE_
#define _EFI_STUB_GUID_INCLUDE_

#pragma pack(1)
typedef struct
{
	UINT64 p1;
	UINT32 p2;
	UINT32 p3;
	UINT8  p4[8];
}EFI_GUID;
#pragma pack(0)	//Try to treat as a 16-byte integer.	

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

#define EFI_BTT_ABSTRACTION_GUID					\
	{								\
		0x18633BFC, 0x1735, 0x4217, 				\
		{							\
		 	0x8A, 0xC9, 0x17, 0x23, 0x92, 0x82, 0xD3, 0xF8	\
		}							\
	}


#define EFI_UNUSED_ENTRY						\
	{								\
		0x00000000, 0x0000, 0x0000, 				\
		{							\
		 	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	\
		}							\
	}

//C12A7328-F81F-11D2-BA4B-00A0C93EC93B
#define EFI_SYSTEM_PARTITION_ENTRY					\
	{								\
		0xC12A7328, 0xF81F, 0x11D2, 				\
		{							\
		 	0xBA, 0x4B, 0x00, 0xA0, 0xC9, 0x3E, 0xC9, 0x3B	\
		}							\
	}


//Contains legacy MBR:	0x024DEE41 0x33E7 0x11D3 0x9D 0x69 0x00 0x08 0xC7 0x81 0xF3 0x9F
#define EFI_SYSTEM_LEGACY_MBR_PARTITION_ENTRY				\
	{								\
		0x024DEE41, 0x33E7, 0x11D3, 				\
		{							\
		 	0x9D, 0x69, 0x00, 0x08, 0xC7, 0x81, 0xF3, 0x9F	\
		}							\
	}

#define EFI_LOADED_IMAGE_PROTOCOL_GUID					\
	{								\
		0x5B1B31A1, 0x9562, 0x11D2, 				\
		{							\
		 	0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B	\
		}							\
	}

#define EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL_GUID			\
	{								\
		0xBC62157E, 0x3E33, 0x4FEC, 				\
		{							\
		 	0x99, 0x20, 0x2D, 0x3B, 0x36, 0xD7, 0x50, 0xDF	\
		}							\
	}

#define EFI_DEVICE_PATH_PROTOCOL_GUID					\
	{								\
		0x09576E91, 0x6D3F, 0x11D2, 				\
		{							\
		 	0x8E, 0x39, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B	\
		}							\
	}

#define EFI_PC_ANSI_GUID 						\
	{								\
		0xE0C14753, 0xF9BE, 0x11D2, 				\
		{							\
			0x9A, 0x0C, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D 	\
		}							\
	}

#define EFI_VT_100_GUID							\
	{								\
		0xDFA66065, 0xB419, 0x11D3, 				\
		{							\
			0x9A, 0x2D, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D 	\
		}							\
	}

#define EFI_VT_100_PLUS_GUID 						\
	{								\
		0x7BAEC70B, 0x57E0, 0x4C76, 				\
		{							\
			0x8E, 0x87, 0x2F, 0x9E, 0x28, 0x08, 0x83, 0x43 	\
		}							\
	}

#define EFI_VT_UTF8_GUID     						\
	{								\
		0xAD15A0D6, 0x8BEC, 0x4ACF, 				\
		{							\
			0xA0, 0x73, 0xD0, 0x1D, 0xE7, 0x7E, 0x2D, 0x88 	\
		}							\
	}

#define DEVICE_PATH_MESSAGING_UART_FLOW_CONTROL     			\
	{								\
		0x37499A9D, 0x542F, 0x4C89, 				\
		{							\
			0xA0, 0x26, 0x35, 0xDA, 0x14, 0x20, 0x94, 0xE4 	\
		}							\
	}




#define EFI_VIRTUAL_DISK_GUID     					\
	{								\
		0x77AB535A, 0x45FC, 0x624B, 				\
		{							\
			0x55, 0x60, 0xF7, 0xB2, 0x81, 0xD1, 0xF9, 0x6E 	\
		}							\
	}

#define EFI_VIRTUAL_CD_GUID     					\
	{								\
		0x3D5ABD30, 0x4175, 0x87CE, 				\
		{							\
			0x6D,0x64,0xD2,0xAD,0xE5,0x23,0xC4,0xBB 	\
		}							\
	}

#define EFI_PERSISTENT_VIRTUAL_DISK_GUID     				\
	{								\
		0x5CEA02C9, 0x4D07, 0x69D3, 				\
		{							\
			0x26,0x9F,0x44,0x96,0xFB,0xE0,0x96,0xF9 	\
		}							\
	}

#define EFI_PERSISTENT_VIRTUAL_CD_GUID     				\
	{								\
		0x08018188, 0x42CD, 0xBB48, 				\
		{							\
			0x10, 0x0F, 0x53, 0x87, 0xD5, 0x3D, 0xED, 0x3D 	\
		}							\
	}
/* PDF page 455 */


#define EFI_DEVICE_PATH_UTILITIES_PROTOCOL_GUID     			\
	{								\
		0x0379BE4E, 0xD706, 0x437d, 				\
		{							\
			0xB0, 0x37, 0xED, 0xB8, 0x2F, 0xB7, 0x72, 0xA4 	\
		}							\
	}

#define EFI_MEMORY_ATTRIBUTES_TABLE_GUID				\
	{								\
		0xdcfa911d, 0x26eb, 0x469f, 				\
		{							\
		 	0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20	\
		}							\
	}

#define EFI_CAPSULE_REPORT_GUID						\
	{								\
		0x39B68C46, 0xF7FB, 0x441B, 				\
		{							\
		 	0xB6, 0xEC, 0x16, 0xB0, 0xF6, 0x98, 0x21, 0xF3	\
		}							\
	}

#define ACPI_TABLE_GUID							\
	{								\
		0xEB9D2D30, 0x2D88, 0x11D3, 				\
		{							\
		 	0x9A, 0x16, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D	\
		}							\
	}

#define SAL_SYSTEM_TABLE_GUID						\
	{								\
		0xEB9D2D32, 0x2D88, 0x11D3, 				\
		{							\
		 	0x9A, 0x16, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D	\
		}							\
	}

#define SMBIOS_TABLE_GUID						\
	{								\
		0xEB9D2D31, 0x2D88, 0x11D3, 				\
		{							\
		 	0x9A, 0x16, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D	\
		}							\
	}

#define SMBIOS3_TABLE_GUID						\
	{								\
		0xF2FD1544, 0x9794, 0x4A2C, 				\
		{							\
		 	0x99, 0x2E, 0xE5, 0xBB, 0xCF, 0x20, 0xE3, 0x94	\
		}							\
	}

#define MPS_TABLE_GUID							\
	{								\
		0xEB9D2D2F, 0x2D88, 0x11D3, 				\
		{							\
		 	0x9A, 0x16, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D	\
		}							\
	}

#define EFI_ACPI_TABLE_GUID						\
	{								\
		0x8868E871, 0xE4f1, 0x11D3, 				\
		{							\
		 	0xbc, 0x22, 0x00, 0x80, 0xC7, 0x3C, 0x88, 0x81	\
		}							\
	}

#define ACPI_TABLE_GUID						\
	{								\
		0xEB9D2D30, 0x2D88, 0x11D3, 				\
		{							\
		 	0x9A, 0x16, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D	\
		}							\
	}

#define EFI_ACPI_20_TABLE_GUID EFI_ACPI_TABLE_GUID



static inline EFI_GUID CreateGUID(UINT64 p1, UINT32 p2, UINT32 p3, UINT8* p4)
{
	//p4 should be 8 bytes long.
	EFI_GUID guid;
	guid.p1 = p1;
	guid.p2 = p2;
	guid.p3 = p3;

	for (int i = 0; i < 8; i++)
	{
		guid.p4[i] = p4[i];
	}
	return guid;
}	


#endif
