MAKE = bmake	##We **really** want to force BSDmake usage, since it's free software and under a permissive license.
CC = clang
LD = ld.lld
ASM = nasm
ARCH = x86_64	##TODO: Dynamically define through a kernelconfig.ini file, which updates a generic rules makefile which we import to hold this kind of information.

TRIPLE = $(ARCH)-unknown-msvc-elf	##MSABI support. We go ahead and objcopy sections over for PE kernel. We masquerade the kernel as being PE, when it really only has a PE stub on it.
CFLAGS = -O3 -ffreestanding -nostdlibs -nostdinc -std=c11 -target $(TRIPLE)	##For sure I'm missing something.

##TODO: Put the userspace stuff, other related services, etc. in their own relevant areas and add into OBJS_WANTED. For now, kernel is all we care about.
OBJS_WANTED = FERLKRNL.EFI



##EFISTUB creates a .so-msvc file, so we know it speaks the MSABI "language". It's still ELF though. Clang won't let us target COFF+MSABI for non ReactOS-like platforms.
##The expected filename is FERLKRNL.so-msvc
%.EFI: %.so-msvc
	objcopy -j .text -j .sdata -j .data -j .dynamic -j .dynsym  -j .rel -j .rela -j .reloc --target=efi-app-$(ARCH) $^ $@



