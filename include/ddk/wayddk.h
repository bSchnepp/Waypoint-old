/*
	Feral device driver kit header.

	Author:
		Brian Schnepp	June 22, 2017.
 */

#ifndef _FERAL_DRIVER_H_
#define _FERAL_DRIVER_H_

#include "../feralstatus.h"
#include "../feral/feralobjs.h"
//TODO: when makefiles are ready, fix these to be done with angle braces. (relative to root)

#ifdef __cplusplus
extern "C" 
{
#endif

//TODO: Hardware devices and whatnot... EVERYTHING IS AN OBJECT.
//Priority is >>STABLE DRIVER API<<. Cleanliness can be fixed when needed.
//We're going to assume most drivers for Waypoint are (unfortunately) proprietary, as such, radical changes in the kernel should be avoided unless REALLY needed.
//Don't want to GPL because I'd rather have proprietary drivers than no drivers, and proprietary software isn't bad, it's just I wouldn't use it on a production system.

//Tempoary stubs for now, implement properly later.
typedef int DRIVER_UNLOAD;
typedef int DRIVER_STARTIO;
typedef int DRIVER_DISPATCH;

//These need to be structs for sure.
typedef int DEVICE_OBJECT;



typedef struct _DriverObject
{
	DEVICE_OBJECT* DeviceObject;

	DRIVER_STARTIO* DriverStartIo;
	DRIVER_UNLOAD* DriverUnload;
	
	DRIVER_DISPATCH* MajorFunction;
}DriverObject;


typedef struct _IRP
{
	UINT64 Flags;	
	BOOLEAN PendingReturn;
	BOOLEAN Cancel;
	FERALSTATUS* DriverTarget;	//Pointer to function we bother. (Dispatcher)
	//TODO...
	
	//TODO, message packets sent between drivers, kernely stuff, etc.
}IRP;

typedef struct _SessMgr
{
	FERALSTATUS* SessionMgrEntry;
	FERALSTATUS* SessionMgrUnload;
	FERALSTATUS* SessionMgrDispatcher;
	SubsystemID ssid;
	//TODO
}SessMgr;	

typedef struct _WayLogon
{
	FERALSTATUS* LogonMgrEntry;
	FERALSTATUS* LogonMgrUnload;
	FERALSTATUS* LogonMgrDispatcher;
	SubsystemID ssid;
	//TODO
}WayLogon;

typedef struct _WayIoMgr
{
	FERALSTATUS* IoMgrEntry;
	FERALSTATUS* IoMgrUnload;
	FERALSTATUS* IoMgrDispatcher;
	SubsystemID ssid;
	//TODO
}WayIoMgr;


typedef struct _FeralRuntimeCore
{
	SessMgr  session_manager;
	WayLogon logon_manager;
	WayIoMgr io_mgr;
	//TODO...
}FeralRuntimeCore;


/* 
	EVERYTHING can be replaced with a driver. Conflicting drivers are first come first serve based on the loading mechanism of the kernel, which is probably alphabetically.
	This is to allow proprietary software to modify the kernel however it wishes: the kernel itself is the only part guaranteed to be software libre.

	Feral itself takes modularity to the extreme, having almost no functionality without drivers.
	Need to figure out how to separate userspace Native API from kernel space device drivers though.

	If we get a conflicting driver, we do something to the user like...

		//code...
		FERALSTATUS status = 0;
		int success = MessageBox(NULL, L"Conflicting driver attempted to be installed. \nOverwrite?", "Kernel Error", MB_YESNO | MB_SETFOREGROUND);
		if ((success == IDYES) && ((GetPermissions(currentUser) & AdministratorPriv) == AdministratorPriv))
		{
			status = KeLoadDriver(driver);
		}
		if (FL_SUCCESS(status))
		{
			//Driver loaded... code...
		}
		//code...
);

 */





#ifdef __cplusplus
}
#endif

#endif
