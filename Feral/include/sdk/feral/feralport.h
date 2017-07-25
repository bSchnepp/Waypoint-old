/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:	
 *	Brian Schnepp	[author]
 */

#ifndef _FERAL_FERAL_PORT_H_
#define _FERAL_FERAL_PORT_H_

#include <feral/feralobjs.h>

typedef UINTN FeralPort;
typedef FeralPort *FeralPortArray;

//TODO...



// We try to cram a lot of information about where/how things should go into as small of a reasonable unit as we can.
// Thus, we can assume at least 32 bits of space (4 billion or so as the max number we got), but often the full 64-bits.

// Design choices on the spot are FUN!

// (if we feel particularly creative, figure out a way to emulate a 64-bit register on a 32-bit CPU with some clever hack of 'fake registers' in RAM...)
// (on a 32-bit system, this really hurts performance (as slow as RAM now, which is often MUCH slower than register), but lets us assume we get 64 bits to work with.)

#endif
