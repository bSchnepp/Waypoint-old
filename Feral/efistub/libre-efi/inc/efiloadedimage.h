/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */



#ifndef _LIBRE_EFI_LOADED_IMAGES_SERVICES_INCLUDE_
#define _LIBRE_EFI_LOADED_IMAGES_SERVICES_INCLUDE_

#define EFI_LOADED_IMAGE_PROTOCOL_REVISION 0x1000

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




typedef struct
{
	UINT32 Revision;
	EFI_HANDLE ParentHandle;
	EFI_SYSTEM_TABLE* SystemTable;
	
	EFI_HANDLE DeviceHandle;
	EFI_DEVICE_PATH_PROTOCOL* FilePath;
	VOID* Reserved;
	
	UINT32 LoadOptionsSize;
	VOID* LoadOptions;

	VOID* ImageBase;
	UINT64 ImageSize;
	
	EFI_MEMORY_TYPE ImageCodeType;
	EFI_MEMORY_TYPE ImageDataType;

	EFI_IMAGE_UNLOAD Unload;
}EFI_LOADED_IMAGE_PROTOCOL;


/* Function definitions... */

typedef EFI_STATUS (EFIAPI *EFI_IMAGE_UNLOAD)(IN EFI_HANDLE ImageHandle);	//Spec might be wrong, comma after ImageHandle..? PDF pg. 399




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Section 10 of 2.7 UEFI spec implementation. */

#define EFI_PNP_ID(id)	( (UINT32)( ((id) << 16) | 0x41D0) )
#define EISA_PNP_ID(id) EFI_PNP_ID(id)


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



/* 
	Just in advance, I'm not going to implement things like networking and complicated features and probably omit whole sections.
	I've spent 4 days writing these headers, haven't got to the actual implementation yet, and have only implemented 15% of the whole spec.
	I'm not wasting the entire summer doing the whole thing from scratch. 
 */


typedef struct _EFI_DEVICE_PATH_PROTOCOL
{
	UINT8 Type;
	UINT8 SubType;
	UINT8 Length[2];
}EFI_DEVICE_PATH_PROTOCOL;

typedef struct _EFI_DEVICE_PATH_UTILITIES_PROTOCOL
{
	EFI_DEVICE_PATH_UTILS_GET_DEVICE_PATH_SIZE GetDevicePathSize;
	EFI_DEVICE_PATH_UTILS_DUP_DEVICE_PATH DuplicateDevicePath;
	EFI_DEVICE_PATH_UTILS_APPEND_PATH AppendDevicePath;
	EFI_DEVICE_PATH_UTILS_APPEND_NODE AppendDeviceNode;
	EFI_DEVICE_PATH_UTILS_APPEND_INSTANCE AppendDevicePathInstance;
	EFI_DEVICE_PATH_UTILS_GET_NEXT_INSTANCE GetNextDevicePathInstance;
	EFI_DEVICE_PATH_UTILS_IS_MULTI_INSTANCE IsDevicePathMultiInstance;
	EFI_DEVICE_PATH_UTILS_CREATE_NODE CreateDeviceNode;
}EFI_DEVICE_PATH_UTILITIES_PROTOCOL;



/* page 456 [PDF] */






#endif
