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
// Resets cursor position to (1,1)
inline void ctgl_reset_cursor_pos()
{
	HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;
	SetConsoleCursorPosition( hStdOut, (COORD) {0,0} );
}

// Clears the screen
inline void ctgl_clear_screen()
{
	system("cls");
}
#else
// Resets cursor position to (1,1)
inline void ctgl_reset_cursor_pos()
{
	printf("\033[1;1H");
}

// Clears the screen
inline void ctgl_clear_screen()
{
	printf("\033[1;1H\033[2J");
}
#endif

// Creates a canvas with the given width and height
Canvas ctgl_create_canvas(int width, int height)
{
	Pixel *pixels = malloc(height * width * sizeof(Pixel));
	Canvas canvas = {width, height, pixels};
	return canvas;
}

// Creates a canvas with the given width and height
inline Pixel ctgl_create_pixel(char symbol, int bRed, int bGreen, int bBlue, int fRed, int fGreen, int fBlue)
{
	Pixel pixel = {symbol, {bRed, bGreen, bBlue}, {fRed, fGreen, fBlue}};
	return pixel;
}

// Sets up CTGL to work correctly (make sure to call this before ctgl_render_sync)
void ctgl_init() {
	ctgl_clear_screen();
	ctgl_hide_cursor();
};

// Sets the background rgb values for a given pixel
void ctgl_set_backgroundRGB(Pixel *pixel, int rgb[3])
{
	for (int i = 0; i < 3; i++)
		pixel->backgroundRGB[i] = rgb[i];
}
// Sets the foreground rgb values for a given pixel
void ctgl_set_foregroundRGB(Pixel *pixel, int rgb[3])
{
	for (int i = 0; i < 3; i++)
		pixel->foregroundRGB[i] = rgb[i];
}
// Sets the symbol for a given pixel
inline void ctgl_set_symbol(Pixel *pixel, char symbol) {
	pixel->symbol = symbol;
}
// Sets a given pixel on a given canvas
inline void ctgl_set_pixel(Canvas canvas, Pixel pixel, int x, int y) {
	canvas.pixels[x + y * canvas.width] = pixel;
}
// Sets a text in the given canvas starting from the given x and y coordinates
void ctgl_set_text(Canvas canvas, const char *str, int x, int y) {
	for (int i = 0; i < strlen(str); i++) {
		canvas.pixels[i + x + y * canvas.width].symbol = str[i];
	}
}
// Fills the given canvas with the given pixel
void ctgl_fill_canvas(Canvas canvas, Pixel pixel)
{
	for (int i = 0; i < canvas.height * canvas.width; i++)
	{
			canvas.pixels[i] = pixel;
	}
}
// Resets terminal color to white foreground and black background
inline void ctgl_reset_terminal_color()
{
	printf(
		"\033[38;2;255;255;255m"
		"\033[48;2;0;0;0m");
}
// Hides the cursor
inline void ctgl_hide_cursor()
{
	printf("\033[?25l");
}

// Shows the cursor
inline void ctgl_show_cursor()
{
	printf("\033[?25h");
}

void ctgl_draw_vertical_line(Canvas canvas, Pixel pixel, int x, int y0, int y1) {
	if (y1 < y0) {
		int temp = y1;
		y1 = y0;
		y0 = temp;
	}
	for(int y = y0; y <= y1; y++) ctgl_set_pixel(canvas, pixel, x, y);
};

void ctgl_draw_horizontal_line(Canvas canvas, Pixel pixel, int y, int x0, int x1) {
	if (x1 < x0) {
		int temp = x1;
		x1 = x0;
		x0 = temp;
	}
	for(int x = x0; x <= x1; x++) ctgl_set_pixel(canvas, pixel, x, y);
};

// Boilerplate for Bresenham Line Plotting Algorithm
void ctgl_draw_line_bresenham_low(Canvas canvas, Pixel pixel, int x0, int y0, int x1, int y1) {
	int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;
    if (dy < 0) {
        yi = -1;
        dy = -dy;
	}
    int D = (2 * dy) - dx;
    int y = y0;

	for (int x = x0; x <= x1; x++) {
		ctgl_set_pixel(canvas, pixel, x, y); // plot(x, y);
        if (D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        } else {
            D = D + 2*dy;
        }
	}
}

void ctgl_draw_line_bresenham_high(Canvas canvas, Pixel pixel, int x0, int y0, int x1, int y1) {
	int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;
    if (dx < 0) {
        xi = -1;
        dx = -dx;
	}
    int D = (2 * dx) - dy;
    int x = x0;

	for (int y = y0; x <= y1; y++) {
		ctgl_set_pixel(canvas, pixel, x, y); // plot(x, y);
        if (D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        } else {
            D = D + 2*dx;
        }
	}
}

void ctgl_draw_line_bresenham(Canvas canvas, Pixel pixel, int x0, int y0, int x1, int y1) {
	if (abs(y1 - y0) < abs(x1 - x0)) {
		if (x0 > x1) ctgl_draw_line_bresenham_low(canvas, pixel, x1, y1, x0, y0);
		else ctgl_draw_line_bresenham_low(canvas, pixel, x0, y0, x1, y1);
	} else {
		if (y0 > y1) ctgl_draw_line_bresenham_high(canvas, pixel, x1, y1, x0, y0);
        else ctgl_draw_line_bresenham_high(canvas, pixel, x0, y0, x1, y1);
	}
}

// plotLineHigh(x0, y0, x1, y1)
//     dx = x1 - x0
//     dy = y1 - y0
//     xi = 1
//     if dx < 0
//         xi = -1
//         dx = -dx
//     end if
//     D = (2 * dx) - dy
//     x = x0

//     for y from y0 to y1
//         plot(x, y)
//         if D > 0
//             x = x + xi
//             D = D + (2 * (dx - dy))
//         else
//             D = D + 2*dx
//         end if

// Renders a given canvas synchronously
void ctgl_render_canvas(Canvas canvas)
{
	ctgl_reset_cursor_pos();
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

void ctgl_render_canvas_vsync(Canvas canvas)
{
	// 31 is the length of the char array required to print one pixel
	// 33 it the length of the char array required to reset the terminal color and return to a new line
	// 1 is for the null terminator '\0'
	char result[31 * canvas.width * canvas.height + 33 * canvas.height + 1];
	result[0] = 0;
	ctgl_reset_cursor_pos();
	for (int i = 0; i < canvas.height; i++)
	{
		for (int j = 0; j < canvas.width; j++)
		{
			char temp[31] = {0};
			sprintf(
				temp,
				"\033[38;2;%d;%d;%dm" // set foreground color
				"\033[48;2;%d;%d;%dm" // set background color
				"%c",				  // print character
				canvas.pixels[i * canvas.width + j].foregroundRGB[0], canvas.pixels[i * canvas.width + j].foregroundRGB[1], canvas.pixels[i * canvas.width + j].foregroundRGB[2],
				canvas.pixels[i * canvas.width + j].backgroundRGB[0], canvas.pixels[i * canvas.width + j].backgroundRGB[1], canvas.pixels[i * canvas.width + j].backgroundRGB[2],
				canvas.pixels[i * canvas.width + j].symbol);
			strcat(result, temp);
		}
		strcat(result,"\033[38;2;255;255;255m" // reset the foreground color to white
			"\033[48;2;0;0;0m" // // reset the background color to black
			"\n"); // new line
	}
	printf(result);
}
