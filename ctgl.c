/*
#############################################
#                  CTGL                     #
#    A graphics library for the terminal    #
#         Made by Amine ElBaghdadi          #
#         @noobjsperson on GitHub           #
#############################################
*/

#include "ctgl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>

inline void ctgl_reset_cursor_pos()
{
	HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	SetConsoleCursorPosition( hStdOut, (COORD) {0,0} );
}
inline void ctgl_clear_screen()
{
	system("cls");
}
#else
inline void ctgl_reset_cursor_pos()
{
	printf("\033[1;1H");
}
inline void ctgl_clear_screen()
{
	printf("\033[1;1H\033[2J");
}
#endif

Canvas ctgl_create_canvas(int width, int height)
{
	Pixel *pixels = malloc(height * width * sizeof(Pixel));
	Canvas canvas = {width, height, pixels};
	return canvas;
}

void ctgl_set_backgroundRGB(Pixel *pixel, int rgb[3])
{
	for (int i = 0; i < 3; i++)
		pixel->backgroundRGB[i] = rgb[i];
}

void ctgl_set_foregroundRGB(Pixel *pixel, int rgb[3])
{
	for (int i = 0; i < 3; i++)
		pixel->foregroundRGB[i] = rgb[i];
}

inline void ctgl_set_symbol(Pixel *pixel, char symbol) {
	pixel->symbol = symbol;
}

inline void ctgl_set_pixel(Canvas canvas, Pixel pixel, int x, int y) {
	canvas.pixels[x + y * canvas.width] = pixel;
}

void ctgl_set_text(Canvas canvas, char *str, int x, int y) {
	for (int i = 0; i < strlen(str); i++) {
		canvas.pixels[i + x + y * canvas.width].symbol = str[i];
	}
}

void ctgl_fill_canvas(Canvas canvas, Pixel pixel)
{
	for (int i = 0; i < canvas.height * canvas.width; i++)
	{
			canvas.pixels[i] = pixel;
	}
}
inline void ctgl_reset_terminal_color()
{
	printf(
		"\033[38;2;255;255;255m"
		"\033[48;2;0;0;0m");
}

inline void ctgl_hide_cursor()
{
	printf("\033[?25l");
}

// Shows the cursor
inline void ctgl_show_cursor()
{
	printf("\033[?25h");
}

// Implements the Naive Line Drawing Algorithm
void ctgl_draw_line_naive(Canvas canvas, Pixel pixel, int x1, int y1, int x2, int y2) {
	if(x2 < x1) {
		int temp = x2;
		x2 = x1;
		x1 = temp;
	}
	int dx = x2 - x1;
	if(dx == 0) {
		for(int y = y1; y <= y2; y++) {
			// in this case x1 == x2 because their difference is 0
			ctgl_set_pixel(canvas, pixel, x1, y);
		}
		return;
	}
	int dy = y2 - y1;
	int y;

	for(int x = x1; x <= x2; x++) {
		y = y1 + dy * (x - x1) / dx;
		ctgl_set_pixel(canvas, pixel, x, y);
	}
}

// Boilerplate for Bresenham Line Plotting Algorithm
// void plotBresenhamLineLow(Canvas canvas, Pixel pixel, int x0, int y0, int x1, int y1) {
// 	int dx = x1 - x0;
//     int dy = y1 - y0;
//     int yi = 1;
//     if (dy < 0) {
//         yi = -1;
//         dy = -dy;
// 	}
//     int D = (2 * dy) - dx;
//     int y = y0;

// 	for (int x = x0; x <= x1; x++) {
// 		canvas.pixels[x + y * canvas.width] = pixel; // plot(x, y);
//         if (D > 0) {
//             y = y + yi;
//             D = D + (2 * (dy - dx));
//         } else {
//             D = D + 2*dy;
//         }
// 	}
// }

void ctgl_render_sync(Canvas canvas)
{
	ctgl_reset_cursor_pos();
	ctgl_hide_cursor();
	for (int i = 0; i < canvas.height; i++)
	{
		for (int j = 0; j < canvas.width; j++)
		{
			printf(
				"\033[38;2;%d;%d;%dm" // set foreground color
				"\033[48;2;%d;%d;%dm" // set background color
				"%c",				  // print character
				canvas.pixels[i * canvas.width + j].foregroundRGB[0], canvas.pixels[i * canvas.width + j].foregroundRGB[1], canvas.pixels[i * canvas.width + j].foregroundRGB[2],
				canvas.pixels[i * canvas.width + j].backgroundRGB[0], canvas.pixels[i * canvas.width + j].backgroundRGB[1], canvas.pixels[i * canvas.width + j].backgroundRGB[2],
				canvas.pixels[i * canvas.width + j].symbol);
		}
		ctgl_reset_terminal_color();
		printf("\n");
	}
}
