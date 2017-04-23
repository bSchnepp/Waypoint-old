/* 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. 
 */

/*
 *	Contributors:
 *		Brian Schnepp
 */



#ifndef __VGA__DRIVER__H_
#define __VGA__DRIVER__H_

#include <stdbool.h>
#include <stdint.h>


enum vga_colors
{
	VGA_BLACK         = 0,
	VGA_BLUE          = 1,
	VGA_GREEN         = 2,
	VGA_CYAN          = 3,
	VGA_RED           = 4,
	VGA_MAGENTA       = 5,
	VGA_BROWN         = 6,
	VGA_LIGHT_GREY    = 7,
	VGA_DARK_GREY     = 8,
	VGA_LIGHT_BLUE    = 9,
	VGA_LIGHT_GREEN   = 10,
	VGA_LIGHT_CYAN    = 11,
	VGA_LIGHT_RED     = 12,
	VGA_LIGHT_MAGENTA = 13,
	VGA_LIGHT_BROWN   = 14,
	VGA_WHITE         = 15
};

uint8_t fg = VGA_WHITE;
uint8_t bg = VGA_BLACK;

void vga_write_colored_string(const char* str, size_t length, uint8_t fg, uint8_t bg);
void vga_write_string(const char* str, size_t length);

void vga_write_terminated_string(const char* str);
void vga_write_terminated_colored_string(const char* str, uint8_t fg, uint8_t bg);

void vga_init();
void vga_redraw();


#endif
