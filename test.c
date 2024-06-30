#include "ctgl.h"
#include "time.h"
#include "stdio.h"
#include <string.h>

int main() {
	float startTime = (float)clock()/CLOCKS_PER_SEC;
	Pixel underscorePixel = {'_', {255,0,0}, {255,0,0}};
	Pixel hashtagPixel = {'#', {0,255,0}, {0,255,0}};
	Canvas canvas = ctgl_create_canvas(50,20);
	ctgl_init();
	ctgl_fill_canvas(canvas, underscorePixel);
	ctgl_draw_line_bresenham(canvas, hashtagPixel, 0, (canvas.height-1)/3, canvas.width-1, canvas.height-1);
	ctgl_draw_line_bresenham(canvas, hashtagPixel, 0, canvas.height-1, canvas.width-1, (canvas.height-1)/3);
	ctgl_draw_line_bresenham(canvas, hashtagPixel, 0, canvas.height-1, (canvas.width-1)/2, 0);
	ctgl_draw_line_bresenham(canvas, hashtagPixel, (canvas.width-1)/2, 0, canvas.width-1, canvas.height-1);
	ctgl_draw_line_bresenham(canvas, hashtagPixel, 0, (canvas.height-1)/3, canvas.width-1, (canvas.height-1)/3);

	const char morocco[] = "Morocco";
	ctgl_set_text(canvas, morocco, (canvas.width-1)/2 - (strlen(morocco)-1)/2, canvas.height-1 );
	

	ctgl_render_canvas(canvas);
	ctgl_render_canvas(canvas);
	ctgl_render_canvas(canvas);
	ctgl_render_canvas(canvas);
	ctgl_reset_terminal_color();
	float endTime = (float)clock()/CLOCKS_PER_SEC;
	printf("Test finished in: %f seconds\n", endTime - startTime);
}