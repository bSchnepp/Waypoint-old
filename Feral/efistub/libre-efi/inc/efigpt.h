/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */



#ifndef _LIBRE_EFI_GPT_INCLUDE_
#define _LIBRE_EFI_GPT_INCLUDE_

/* MBR partition entry */
#pragma pack(1)
typedef struct
{
	UINT8 StartHead;
	UINT8 StartSector;
	UINT8 StartTrack;
	UINT8 OSIndicator;
	UINT8 EndHead;
	UINT8 EndSector;
	UINT8 EndTrack;
	UINT8 StartingLBA[4];
	UINT8 SizeInLBA[4];
}MBR_PARTITION_RECORD;


typedef struct
{
	EFI_GUID PartitionTypeGUID;
	EFI_GUID UniquePartitionGUID;
	EFI_LBA StartingLBA;
	EFI_LBA EndingLBA;
	UINT64 Attributes;
	CHAR16 PartitionName[36]; 
}EFI_PARTITION_ENTRY;


#define EFI_BTT_ALIGNMENT 4096
#define EFI_BTT_INFO_UNUSED_LEN 3968
#define EFI_BTT_INFO_BLOCK_SIG_LEN 16

#define EFI_BIT_INFO_BLOCK_FLAGS_ERROT 0x00000001
#define EFI_BTT_INFO_BLOCK_MAJOR_VERSION 2
#define EFI_BTT_INFO_BLOCK_MINOR_VERSION 0

#define EFI_BTT_FLOG_ENTRY_ALIGNMENT 64


typedef struct
{
	CHAR8 Sig[EFI_BTT_INFO_BLOCK_SIG_LEN]; 	
	EFI_GUID Uuid;
	EFI_GUID ParentUuid;
	UINT32 Major;
	UINT32 Minor;
	UINT32 ExternalLbaSize;
	UINT32 ExternalNLba;
	UINT32 InternalLbaSize;
	UINT32 InternalNLba;
	UINT32 NFree;
	UINT32 InfoSize;
	UINT64 NextOff;
	UINT64 DataOff;
	UINT64 MapOff;
	UINT64 FlogOff;
	UINT64 InfoOff;
	CHAR8 Unused[EFI_BTT_INFO_UNUSED_LEN];
	UINT64 Checksum;
}EFI_BTT_INFO_BLOCK;


/* MBR partition table */
typedef struct
{
	UINT8 BootStrapCode[440];
	UINT8 UniqueMbrSignature[4];		//If protective, set to 0.
	UINT8 Unknown[2];			//If protective, set to 0.
	MBR_PARTITION_RECORD Partition[4];
	UINT16 Signature;			//On x86-based systems, this has to be 0xAA55.
}MASTER_BOOT_RECORD;

typedef struct _EFI_BIT_MAP_ENTRY
{
	UINT32 PostMapLba : 30;
	UINT32 Error : 1;
	UINT32 Zero : 1;
}EFI_BTT_MAP_ENTRY;

 
#pragma pack()

/*
	Values we care about:
		0xEF defines UEFI system partition (UEFIFAT)
		0xEE defines protective MBR. 

	Everything else is defined by an operating system, we ignore it. 
 */


//This is for validating EFI partitions.
typedef struct
{
	UINT64 Signature;	//0x5452415020494645 on EFIFAT partitions.
	UINT32 Revision; 	//0x00010000.
	UINT32 HeaderSize;
	UINT32 HeaderCRC32;	//CRC32 checksum of the header.
	UINT32 Reserved;	//Not used.	
	UINT64 MyLBA;
	UINT64 AlternateLBA;
	UINT64 FirstUsableLBA;
	UINT64 LastUsableLBA;
	UINT64 DiskGUID[2];
	UINT64 PartitionEntryLBA;
	UINT32 NumberOfPartitionEntries;
	UINT32 SizeOfPartitionEntry;
	UINT32 PartitionEntryArrayCRC32;
}EFI_GPT_HEADER;


typedef struct _EFI_BIT_FLOG
{
	UINT32 Lba0;
	UINT32 OldMap0;
	UINT32 NewMap0;
	UINT32 Seq0;
	UINT32 Lba1;
	UINT32 OldMap1;
	UINT32 NewMap1;
	UINT32 Seq1;
}EFI_BIT_FLOG;


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

#endif
