/*
 *	Copyright (c) 2017 Brian Schnepp
 *	LICENSE: Apache 2.0. Refer to 'LICENSE' in the root of this project.
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
