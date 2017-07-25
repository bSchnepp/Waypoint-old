; Initializes the multiboot magic we need for the kernel.
; (See 'LICENSE' in root directory for licensing terms of this file.
; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;

MB_ALIGN    equ 1<<0
MB_MEM_INFO equ 1<<1
MB_FLAGS    equ MB_ALIGN | MB_MEM_INFO
MB_MAGIC    equ 0x1BADB002

MB_CHECKSUM    equ -(MB_MAGIC + MB_FLAGS)

[SECTION .multiboot]
ALIGN 4
dd MB_MAGIC
dd MB_FLAGS
dd MB_CHECKSUM

[SECTION .bss]
ALIGN 4

stack_bottom:
	resb 12288	;12KiB for kernel stack...

stack_top:
			; on x86/x86-64, stack grows downward.

[SECTION .text]
global _kinit:function (_kinit.end - _kinit)
_kinit:
	mov esp, stack_top		; Setup stack. C cannot work without stack.
	mov ebp, stack_bottom		; Are we actually doing this right? I'm not great at assembly, but I'm trying.

	;push eax			;Do we need eax for anything?? 
	push ebx			;Multiboot struct pointer.

	

	extern KElfLoader		; Kernel_Main defined in main.c...	;Switch to instead target an ELF loader which then loads the kernel.
	call   KElfLoader		; Jump to kernel's main code...		;The loader is defined in hardabs.c. We shouldn't return.
	cli									;Kernel shutdown routine TODO. (dirty easy hack would be to intentionally corrupt GDT, and thus triple fault)
	hlt

.hang:
	jmp $

.end:


;TODO: Switch to 64-bit mode, and THEN load the kernel. This is so we can keep the kernel as "an ordinary ELF64 executable" and be easy to swap out the bootloader.
;This is also so, with a little tinkering, we can patch the Feral kernel to be able to run in userspace on Linux and all, (or even better, as a Mach server).
;This way, you can run Feral programs and use Feral without really having a full install of the OS. I won't be the one doing those patches though.
