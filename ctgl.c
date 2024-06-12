#include "ctgl.h"
#include <stdlib.h>
#include <stdio.h>

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

void ctgl_fill_canvas(Canvas canvas, Pixel pixel)
{
	for (int i = 0; i < canvas.height; i++)
	{
		for (int j = 0; j < canvas.width; j++)
		{
			canvas.pixels[i * canvas.width + j] = pixel;
		}
	}
}
void ctgl_reset_terminal_color()
{
	printf(
		"\033[38;2;255;255;255m"
		"\033[48;2;0;0;0m"
		"\033[?25h");
}

inline void ctgl_hide_cursor()
{
	printf("\033[?25l");
}

void ctgl_render_sync(Canvas canvas)
{
	system("cls");
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
		printf("\n");
	}
}