#Imported from old Feral. Fix up later!


MAKE = bmake	##Enforce the use of bmake over GNU Make.

CC           = clang
TRIPLE       = x86_64-unknown-msvc-elf
INCLUDE      = include
KRNL_INCLUDE = ../include
CFLAGS       = -std=c11 -fno-stack-protector -fPIC -fshort-wchar -mno-red-zone -Wall -I$(INCLUDE) -I$(KRNL_INCLUDE) -shared -target $(TRIPLE) -fms-extensions -O3
LD 	     = ld.lld
LDFLAGS      =  -nostdlib --entry=efi_main
ASM          = nasm
ASMFLAGS     = -f bin

FINAL_OBJ = FERLKRNL.so-msvc

OBJECTS = efistub.so-msvc efistub.pestub

all:	$(FINAL_OBJ)

%.so-msvc: %.c
	$(CC) $(CFLAGS) efistub.c -o efistub.so
	$(LD) $(LDFLAGS) efistub.so -o efistub.so-msvc

efistub.pestub: asm/pestub.asm
	$(ASM) $(ASMFLAGS) asm/pestub.asm -o efistub.pestub

$(FINAL_OBJ): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(FINAL_OBJ)


