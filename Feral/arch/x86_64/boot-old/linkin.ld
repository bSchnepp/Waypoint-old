ENTRY(_kinit)	/* We look here to start the bootloader image. Linking on the 'in' part of the bootloader (32-bit), hence, 'link' + 'in'. */

/* Sections that belong to the final executable. */
SECTIONS
{
	/* Put it at 1 MB. */
	. = 1M;
	
	/* We slap the Multiboot section into the kernel as soon as possible, before the .text (compiled code) section */
	.text BLOCK(4K) : ALIGN(4K)
	{
		*(.multiboot)	/* We only have one multiboot section, so put it first. */
		*(.text)	/* Grab the inputs from the rest of the object files, slap them together here. */
	}

	/* Read only data. */
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	/* Initialized data (.data) */
	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	/* Read/write uninitalized data, and the stack. */
	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}

	/* TODO!!!! */
}
