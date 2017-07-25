/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 *
 * Contributors:
 *	Brian Schnepp [author]
 */

/* Define the common stuff we need for VGA/VESA/Whatever support. */

#include <feral/feralobjs.h>

//Pretty sure this is right. Need to refer back to the article on it or whatever.
#define CreateColorPair(UINT8 fg, UINT8 bg)	((UINT16)(fg) + (bg << 16))

//TODO!!!!


/* For text mode VGA... */
const UINTN width  = 80;
const UINTN height = 25;

volatile UINT16* VgaMemLoc = ((UINT16*)0xB8000);

UINTN CursorX = 0;
UINTN CursorY = 0;

/*
typedef enum
{
	BLACK = 0,
	
}Color;
*/
