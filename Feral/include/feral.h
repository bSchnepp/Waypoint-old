/*
	TODO: include all the relevant headers which may be needed by a USERSPACE application.
 */

#ifndef _FERAL_H_
#define _FERAL_H_

#include <feral/feralobjs.h>

#ifndef WAYPOINT_LEAN_AND_MEAN
//These won't always be be used by applications which require feral.h...


#endif

#ifndef WAYPOINT_INCLUDE_NIXOID_
//Include NIXOID headers... for those of you also too lazy to look up the right headers.
#include <sys/unistd.h>


#endif

#ifdef UNICODE
typedef TCHAR UINT32;
#else
typedef TCHAR UINT8;
#endif

//Here's everything that will be included (for sure) in anything including feral.h...


/* Standard library includes. */
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#endif
