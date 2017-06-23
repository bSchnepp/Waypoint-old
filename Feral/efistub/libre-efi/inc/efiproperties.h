/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */

#ifndef _LIBRE_EFI_PROPERIES_INCLUDE_
#define _LIBRE_EFI_PROPERIES_INCLUDE_

/*
	Definitions for the properties table, associated stuff, etc. etc.
	[Page numbers in reference to the PDF document on tianocore.org by the way]
	
	Page 187. 
 */



#define EFI_MEMORY_ATTRIBUTES_TABLE_GUID				\
	{								\
		0xdcfa911d, 0x26eb, 0x469f, 				\
		{							\
		 	0xa2, 0x20, 0x38, 0xb7, 0xdc, 0x46, 0x12, 0x20	\
		}							\
	}



typedef struct 
{
	UINT32 Version;	
	UINT32 Length;	//Size of the structure
	UINT64 MemoryProtectionAttribute;
}EFI_PROPERTIES_TABLE;


typedef struct 
{
	UINT32 Version;
	UINT32 NumberOfEntries;
	UINT32 DescriptorSize;
	UINT32 Reserved;
	//EFI_MEMORY_DESCRIPTOR Entry[1];	//Spec shows this as commented out. Is this intended?
}EFI_MEMORY_ATTRIBUTES_TABLE;

//TODO: Defines as put in on page 189. EFI_MEMORY_RO, EFI_MEMORY_XP, EFI_MEMORY_RUNTIME. 



#endif
