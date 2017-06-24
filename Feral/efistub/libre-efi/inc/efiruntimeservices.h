/*
	Copyright (c) 2017 Brian Schnepp
	See 'LICENSE' in parent directory for license terms where applicable.
 */



#ifndef _LIBRE_EFI_RUNTIME_SERVICES_INCLUDE_
#define _LIBRE_EFI_RUNTIME_SERVICES_INCLUDE_

#define EFI_VARIABLE_NON_VOLATILE 				0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS 			0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS 				0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD	 		0x00000008 
#define EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS 		0x00000010	//DEPRECATED
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS 	0x00000020
#define EFI_VARIABLE_APPEND_WRITE 				0x00000040
#define EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS 		0x00000080

#define EFI_VARIABLE_AUTHENTICATION_3_TIMESTAMP_TYPE 1
#define EFI_VARIABLE_AUTHENTICATION_3_CERT_ID_SHA256 1
#define EFI_VARIABLE_AUTHENTICATION_3_NONCE_TYPE 2

#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02
#define EFI_UNSPECIFIED_TIMEZONE 0x07FF

typedef struct
{
	UINT8 Type;
	UINT32 IdSize;
}EFI_VARIABLE_AUTHENTICATION_3_CERT_ID;

/* DEPRECATED! DO NOT USE IF YOU CAN HELP IT! */
typedef struct 
{
	UINT64 MonotonicCount;
	WIN_CERTIFICATE_UEFI_GUID AuthInfo;
}EFI_VARIABLE_AUTHENTICATION;

typedef struct 
{
	EFI_TIME TimeStamp;
	WIN_CERTIFICATE_UEFI_GUID AuthInfo;
}EFI_VARIABLE_AUTHENTICATION_2;

typedef struct 
{
	UINT32 NonceSize;
	//UINT8 Nonce[NonceSize];	//Huh..? Not sure how this is supposed to work without this member.
}EFI_VARIABLE_AUTHENTICATION_3_NONCE; 

typedef struct 
{
	UINT8 Version;
	UINT8 Type;
	UINT32 MetadataSize;
	UINT32 Flags;
}EFI_VARIABLE_AUTHENTICATION_3;

/* Defined in PDF page 365 */
typedef struct
{
	UINT16 Year; //1990 - 20XX.
	UINT8 Month; //1 - 12
	UINT8 Day; //1 - 31
	UINT8 Hour;	//0 - 23
	UINT8 Minute;	//0 - 59
	UINT8 Second;	//0 - 59
	UINT8 Pad1;
	UINT32 Nanosecond;	// 0 - 999999999
	INT16 TimeZone;	//-1440 to 1440 or 2047 Subtract UTC time with this.
	UINT8 Daylight;
	UINT8 Pad2;
}EFI_TIME;

typedef struct 
{
	UINT32 Resolution;
	UINT32 Accuracy;
	BOOLEAN SetsToZero;
}EFI_TIME_CAPABILITIES;




/**  Section 8 of the UEFI spec. See PDF page 341 in the 2.7 spec. **/

/* Gets a variable from the motherboard's NVRAM. */
typedef EFI_STATUS GetVariable(IN CHAR16* VariableName, IN EFI_GUID* VendorGuid, OUT UINT32* Attributes OPTIONAL, IN OUT UINTN* DataSize, OUT VOID* Data OPTIONAL); 

typedef EFI_STATUS GetNextVariableName(IN OUT UINTN* VariableNameSize, IN OUT CHAR16* VariableName, IN OUT EFI_GUID* VendorGuid);

typedef EFI_STATUS SetVariable(IN CHAR16* VariableName, IN EFI_GUID* VendorGuid, IN UINT32 Attributes, IN UINTN DataSize, IN VOID* Data);

/* PDF page 362, hard page 292. */
typedef EFI_STATUS QueryVariableInfo(IN UINT32 Attributes, OUT UINT64* MaximumVariableStorageSize, OUT UINT64* MaximumVariableSize);

/* Returns the current time. */
typedef EFI_STATUS GetTime(OUT EFI_TIME* Time, OUT EFI_TIME_CAPABILITIES* Capabilities OPTIONAL);

typedef EFI_STATUS SetTime(IN EFI_TIME* Time);

typedef EFI_STATUS GetWakeupTime(OUT BOOLEAN* Enabled, OUT BOOLEAN* Pending, OUT EFI_TIME* Time);

/* Set system wakeup alarm time. PDF page 371*/
typedef EFI_STATUS SetWakeupTime(IN BOOLEAN Enable, IN EFI_TIME* Time OPTIONAL);






/** Virtual memory services... **/
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

#define EFI_CAPSULE_REPORT_GUID						\
	{								\
		0x39B68C46, 0xF7FB, 0x441B, 				\
		{							\
		 	0xB6, 0xEC, 0x16, 0xB0, 0xF6, 0x98, 0x21, 0xF3	\
		}							\
	}



typedef enum
{
	EfiResetCold,
	EfiResetWarm,
	EfiResetShutdown,
	EfiResetPlatformSpecific
}EFI_RESET_TYPE;

typedef struct 
{
	UINT64 Length;
	union 
	{
		EFI_PHYSICAL_ADDRESS DataBlock;
		EFI_PHYSICAL_ADDRESS ContinuationPointer;
	}Union;
}EFI_CAPSULE_BLOCK_DESCRIPTOR;

typedef struct 
{
	EFI_GUID CapsuleGuid;
	UINT32 HeaderSize;
	UINT32 Flags;
	UINT32 CapsuleImageSize;
}EFI_CAPSULE_HEADER;

typedef struct 
{
	UINT32 VariableTotalSize;
	UINT32 Reserved;	//Needed for alignment.
	EFI_GUID CapsuleGuid;
	EFI_TIME CapsuleProcessed;
	EFI_STATUS CapsuleStatus;
}EFI_CAPSULE_RESULT_VARIABLE_HEADER;

typedef EFI_STATUS SetVirtualAddressMap(IN UINTN MemoryMapSize, IN UINTN DescriptorSize, IN UINT32 DescriptorVersion, IN EFI_MEMORY_DESCRIPTOR* VirtualMap);

/* From what I'm understanding, this is for physical --> virtual only. */
typedef EFI_STATUS ConvertPointer(IN UINTN DebugDisposition, IN VOID** Address);



/** Misc. runtime services.  Section 8.5 **/
typedef VOID (EFIAPI *EFI_RESET_SYSTEM)(
        IN EFI_RESET_TYPE ResetType,
        IN EFI_STATUS ResetStatus,
        IN UINTN DataSize,
        IN VOID* ResetData OPTIONAL
);

typedef EFI_STATUS GetNextHighMonotonicCount(OUT UINT32* HighCount);

/* PDF page 381 */

typedef EFI_STATUS UpdateCapsule(IN EFI_CAPSULE_HEADER** CapsuleHeaderArray, IN UINTN CapsuleCount, IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL);

typedef EFI_STATUS QueryCapsuleCapabilities(IN EFI_CAPSULE_HEADER** CapsuleHeaderArray, IN UINTN CapsuleCount, OUT UINT64* MaximumCapsuleSize, OUT EFI_RESET_TYPE* ResetType);



#endif
