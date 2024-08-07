#ifndef CTGL_H
#define CTGL_H

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

typedef struct _Pixel {
	char symbol;
	short backgroundRGB[3];
	short foregroundRGB[3];
} Pixel;

typedef struct _Canvas {
	int width;
	int height;
	Pixel *pixels;
} Canvas;

Pixel ctgl_create_pixel(char symbol, short bRed, short bGreen, short bBlue, short fRed, short fGreen, short fBlue);
Canvas ctgl_create_canvas(int width, int height);

void ctgl_init();
void ctgl_hide_cursor();
void ctgl_show_cursor();
void ctgl_clear_screen();
void ctgl_reset_cursor_pos();
void ctgl_reset_terminal_modes();


void ctgl_fill_canvas(Canvas canvas, Pixel pixel);
void ctgl_render_canvas(Canvas canvas);
void ctgl_free_canvas(Canvas canvas);

void ctgl_set_backgroundRGB(Pixel *pixel, int rgb[3]);
void ctgl_set_foregroundRGB(Pixel *pixel, int rgb[3]);
void ctgl_set_symbol(Pixel *pixel, char symbol);
void ctgl_set_pixel(Canvas canvas, Pixel pixel, int x, int y);
void ctgl_set_text(Canvas canvas, const char *str, int x, int y);

void ctgl_draw_line_bresenham_low(Canvas canvas, Pixel pixel, int x0, int y0, int x1, int y1);
void ctgl_draw_line_bresenham_high(Canvas canvas, Pixel pixel, int x0, int y0, int x1, int y1);
void ctgl_draw_line_bresenham(Canvas canvas, Pixel pixel, int x0, int y0, int x1, int y1);
void ctgl_draw_vertical_line(Canvas canvas, Pixel pixel, int x, int y0, int y1);
void ctgl_draw_horizontal_line(Canvas canvas, Pixel pixel, int y, int x0, int x1);


#ifdef __cplusplus
}
#endif
#endif // CTGL_H