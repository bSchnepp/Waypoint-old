#ifndef _FERAL_FERAL_KRNL_H_
#define _FERAL_FERAL_KRNL_H_

#include <feral/feralobjs.h>

typedef enum
{
	IRQ_PASSIVE_LEVEL  = 0x0,
	IRQ_APC_LEVEL	   = 0x1,
	IRQ_DISPATCH_LEVEL = 0x2,
	IRQ_ABSOLUTE_LEVEL = 0x3	//All interrupts off.	
}IRQLevel;


/* Often used prototypes... */
void KeVerifyArea(VOID* address, UINTN count);



//TODO...

#endif
