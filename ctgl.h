#ifndef CTGL_H
#define CTGL_H

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

typedef struct Pixel {
	char symbol;
	int backgroundRGB[3];
	int foregroundRGB[3];
} Pixel;

typedef struct Canvas {
	int width;
	int height;
	Pixel *pixels;
} Canvas;

Canvas ctgl_create_canvas(int height, int width);
void ctgl_hide_cursor();
void ctgl_fill_canvas(Canvas canvas, Pixel pixel);
void ctgl_render_sync(Canvas canvas);
void ctgl_set_backgroundRGB(Pixel *pixel, int rgb[3]);
void ctgl_set_foregroundRGB(Pixel *pixel, int rgb[3]);
void ctgl_reset_terminal_color();


#ifdef __cplusplus
}
#endif
#endif // CTGL_H