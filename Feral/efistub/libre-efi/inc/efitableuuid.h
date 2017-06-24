/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */

/*
	Defines needed by UEFI for some GUIDs.
 */

#ifndef _LIBRE_EFI_ACPI_INCLUDE_
#define _LIBRE_EFI_ACPI_INCLUDE_


typedef struct
{
	UINT32 Data1;
	UINT16 Data2;
	UINT16 Data3;
	UINT8  Data4[8];
}EFI_GUID;



/*#define EFI_ACPI_20_TABLE_GUID						\
	{								\
		0x8868E871, 0xE4F1, 0x11D3, 				\
		{							\
		 	0xBC, 0x22, 0x00, 0x80, 0xC7, 0x3C, 0x88, 0x81	\
		}							\
	}*/
		 
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


#endif
