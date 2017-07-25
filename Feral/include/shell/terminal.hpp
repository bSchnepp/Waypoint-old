#ifndef _TERMINAL_KERNEL_INTERFACE_HPP_
#define _TERMINAL_KERNEL_INTERFACE_HPP_

//TODO: Define Feral users!!!

#include <feral/feralobjs.h>

/* 
	This is a kernel interface for the 'native shell' of the Feral kernel.
	This is in C++ so that it can be subclassed and inherited and all that fun stuff.
*/


class KNativeShell
{
public:
	KNativeShell(CHAR8* username, CHAR8* password);
	virtual ~KNativeShell();

	VOID   PushToHistory(CHAR8* string);
	CHAR8* GrabFromHistory(UINTN num);

protected:
	CHAR8* CurrentLine;
	
private:
	CHAR8** History;
	CHAR8*  Username;
	CHAR8*  Password;

	BOOLEAN AutomaticallyElevate;	// elevate is 'sudo' for Waypoint.
};


#endif
