CFLAGS = -O3 -I$(INCLUDE) -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2

LOCAL_GOALS = flbooter bootstrap.o

##Rewrite the makefile.
##We have two goals: flbooter (ELF32 complete executable which is Multiboot 1 compliant), and bootstrap.o, the bootstrapping part of the kernel which is linked later on.

all:	$(LOCAL_GOALS)
	



bootstrap.o: boot/multiboot.asm
	$(ASM) $(ASMFLAGS) boot/multiboot.asm -f elf64 -o bootstrapx64.o
	objcopy -O elf32-i386 bootstrapx64.o bootstrapx86.o
	mv bootstrapx86.o $(BUILD_DIR)/bootstrap.o

flbooter:
	
