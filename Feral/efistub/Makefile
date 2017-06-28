MAKE = bmake	##Enforce the use of bmake over GNU Make.

CC      = clang
TRIPLE  = x86_64-unknown-msvc-elf
INCLUDE = include
KRNL_INCLUDE = ../include
CFLAGS  = -std=c11 -fno-stack-protector -fPIC -fshort-wchar -mno-red-zone -Wall -I$(INCLUDE) -shared -target $(TRIPLE) -fms-extensions -O3
LD 	= ld.lld
LDFLAGS =  -nostdlib --entry=efi_main
##We use the MSABI, but still am ELF executable. This is interesting stuff actually on how all that works.

FINAL_OBJ = FERLKRNL.so-msvc

OBJECTS = efistub.so-msvc 

all:	$(FINAL_OBJ)

%.so-msvc: %.c
	$(CC) $(CFLAGS) efistub.c -o efistub.o
	$(LD) $(LDFLAGS) efistub.o -o efistub.so

$(FINAL_OBJ): OBJECTS
	$(CC) $(CFLAGS) $(OBJECTS) -o $(FINAL_OBJ)


