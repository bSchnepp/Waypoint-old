/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */

#include "wayddk.h"

/* This struct is for creating a generic NIC driver, long TODO!!! */

typedef struct kBasicNICDriver
{
	VOID (*CreateDriver)(VOID *DriverEntry, VOID DriverExit, VOID DriverDispatch, VOID DriverPing);	//TODO!!! 
}

/* This struct is for creating a generic GPU driver, long TODO!!! */
typedef struct kBasicGPUDriver
{
	CHAR8* VendorColor;	//"green", "blue", and "red". Unknown should be 'yellow'. This is to avoid trademarked names for a myriad of reasons.
	VOID  (*CreateDriver)(VOID *DriverEntry, VOID DriverExit, VOID DriverDispatch);	//TODO...
}

//Waypoint's (new) testing hardware consists of a ZEN 1700X, 16GB of DDR4 RAM, and two 290X GPUs. (GCN 4 I believe??)
//As such, our priority for GPU drivers is **specifically** that card.
