;Trying to get a PE stub in assembly here so we don't have to make the kernel PE.
;Simply slap this on the kernel and pretend like nothing ever happened.

[BITS 64]

section .bstext
global _bootstub

_bootstub:
	db "MZ"

	mov ax, cs
	mov ds, ax
	mov es, ax
	mov ss, ax

	xor sp, sp	; Clear stack pointer.

	sti
	cld
	
	times 0x3B - ($-$$) db 0	;;Might be 0x3C...
	dd _pe_header

section .bsdata

_pe_header:
	db "PE",0,0	;PE header. This is needed by EFI.

_coff_header:
	dw 0x8664	;Signify this is x86-64.
	dw 4		;Number of sections.
	dd 0
	dd 0
	dd 1
	dw section_table - optional_header	; Size of the stub
	dw 0x206		;When asking for help, I'm just told to set this to 0x206. OK.

optional_header:
	dw 0x20B		;We're PE32+
	dw 0x1402		;Linker version. Minor is first, then major. A single word does it.
	
	;efistub.c will fill these in...
	dd 0		;SizeOfCode
	dd 0		;SizeofInitializedData
	dd 0		;SizeOfUninitializedData
	dd 0x0000	;AddressOfEntryPoint
	dd 512		;BaseOfCode
	
	dq 0		;ImageBase. a 'long' in x86 assembly is actually an int, and a quad is a long.

	dd 32		;SectionAlignment
	dd 32		;FileAlignment
	dw 0		;Major OS version
	dw 0		;Minor OS version
	dw 0		;Major Image version
	dw 0		;Minor Image version
	dw 0		;Major subsystem version
	dw 0		;Minor subsystem version
	dd 0		;W32 Version Value

	; Defined efistub.c...
	dd 0		;Size of image
	dd 512		;Size of headers
	dd 0		;Checksum.
	dw 10		;Subsystem we use (10)
	dw 0		;DLL characteristics.

	dq 0		;Size of Stack Reserved
	dq 0		;Size of Stack Commit
	dq 0		;Size of Heap Reserve
	dq 0		;Size of Heap Commit

	dd 0		;Loader flags..?
	dd 6		;Num of RVAs and Sizes..?

	dq 0		;Export table
	dq 0		;Import table
	dq 0		;Resource table
	dq 0		;Exception table
	dq 0		;Cert table
	dq 0		;Base Relocation table

section_table:
	db ".setup",0,0 ;Name of the section PE wants. Has to be 8 bytes long.

	dd 0
	dd 0x0		;Startup...
	dd 0x0		;Size of initialized data.
	dd 0x0
	dd 0x0		;Pointer to relocations
	dd 0x0		;Pointer to line numbers
	dw 0x0		;Num of relocations
	dw 0x0		;Num of line numbers
	dd 0x60500020	;Characteristics (these are essentially section flags)

	db ".text",0,0	;Actual code section (text). This is a stub to load the ELF section elsewhere in the binary.
	db 0x0
	dd 0x0
	dd 0x0		;Startup
	dd 0x0		;Size of init. data
	dd 0x0
	dd 0x0		;Pointer to relocations
	dd 0x0		;Pointer to line numbers

	dw 0		;Number of reloations
	dw 0		;Numver of line numbers
	dd 0x60500020	;Characteristics.

	db ".bss",0,0,0,0	;Uninitalized data.
	dd 0x0
	dd 0x0
	dd 0x0

	dd 0x0
	dd 0x0
	dd 0x0
	dw 0
	dw 0
	dd 0xC8000080


;This is the end of the needed PE stub to load the kernel.
;Many things will be needed to be filled in from kernel code and other stuff.
;For now, this is essentially all we really need for a working kernel (once assembled then
;slapped onto the kernel)


