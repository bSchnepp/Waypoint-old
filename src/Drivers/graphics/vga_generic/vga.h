/*
Copyright (c) 2017 Brian Schnepp

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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