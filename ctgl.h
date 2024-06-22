#ifndef CTGL_H
#define CTGL_H

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

typedef struct _Pixel {
	char symbol;
	int backgroundRGB[3];
	int foregroundRGB[3];
} Pixel;

typedef struct _Canvas {
	int width;
	int height;
	Pixel *pixels;
} Canvas;

Canvas ctgl_create_canvas(int width, int height);
void ctgl_hide_cursor();
void ctgl_show_cursor();
void ctgl_clear_screen();
void ctgl_reset_cursor_pos();
void ctgl_fill_canvas(Canvas canvas, Pixel pixel);
void ctgl_render_sync(Canvas canvas);
void ctgl_set_backgroundRGB(Pixel *pixel, int rgb[3]);
void ctgl_set_foregroundRGB(Pixel *pixel, int rgb[3]);
void ctgl_set_symbol(Pixel *pixel, char symbol);
void ctgl_set_pixel(Canvas canvas, Pixel pixel, int x, int y);
void ctgl_set_text(Canvas canvas, char *str, int x, int y);
void ctgl_draw_line_naive(Canvas canvas, Pixel pixel, int x1, int y1, int x2, int y2);
void ctgl_reset_terminal_color();


#ifdef __cplusplus
}
#endif
#endif // CTGL_H