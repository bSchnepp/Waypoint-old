#ifndef _FERAL_STATUS_H_
#define _FERAL_STATUS_H_

#include "feral/feralobjs.h"

#ifdef __cplusplus
extern "C" 
{
#endif

/*
	Values between 0 and 0x3FFFFFFF are success, 0x40000000 and 0x7FFFFFFF are informational (which is also success), anything above is a warning or error.
	This splits it into nice, even fourths.
 */
typedef enum FERALSTATUS
{
	Success   = 0x0,	//Everything OK! Last call was fine, kernel is doing good, don't worry.

	//Put stuff here...

	UserApc   = 0xC0,	//Usermode async
	KernelApc = 0x100	//kernel async

	//TODO...



	//Informational...
};

inline BOOLEAN FL_INFORMATION(FERALSTATUS status)
{
	if ((status > 0x40000000) && (status < 0x7FFFFFFF))
	{
		return true;
	}
	return false;
}

inline BOOLEAN FL_SUCCESS(FERALSTATUS status)
{
	BOOLEAN infotype = FL_INFORMATION(status);
	if (infotype)
	{
		return true;
	}
	else
	{
		if (status < 0x3FFFFFFF)
		{
			return true;
		}
	}
	return false;
}

inline BOOLEAN FL_WARNING(FERALSTATUS status)
{
	if ((status > 0x80000000) && (status < 0xBFFFFFFF))
	{
		return true;
	}
	return false;
}

inline BOOLEAN FL_WARNING(FERALSTATUS status)
{
	if ((status > 0xC0000000) && (status < 0xFFFFFFFF))
	{
		return true;
	}
	return false;
}


#ifdef __cplusplus
}
#endif

#endif
