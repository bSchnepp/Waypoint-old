/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

#include <feral/kernel.h>

BOOLEAN UsInitAlreadyDone;	/* csrss is currently running. */
BOOLEAN UsCsrSharedObjectDone;	/* csrss loaded it's shared object fine. */

VOID* RuntimeHeap;

/* TODO!!! */
BOOLEAN UsSharedObjectInit(VOID* SoHandle);



/* This header defines the stuff we need to make the kernel load the basic CSRSS stuff so we can actually DO SOMETHING. */


