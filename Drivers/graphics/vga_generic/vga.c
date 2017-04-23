/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 */

/*
 *	Contributors:
 *		Brian Schnepp
 */

#include "vga.h"
#define VGA_COLOR(fb, bg) ((fg << 4) | (bg & 0x0F))

//TODO EVERYWHERE!!

void vga_write_colored_string(const char* str, size_t length, uint8_t fg, uint8_t bg)
{
	return;
}

void vga_write_string(const char* str, size_t length)
{
	return;
}

void vga_write_terminated_string(const char* str)
{
	return;
}

void vga_write_terminated_colored_string(const char* str, uint8_t fg, uint8_t bg)
{
	return;
}

void vga_init()
{
	return;
}

void vga_redraw()
{
	return;
}
