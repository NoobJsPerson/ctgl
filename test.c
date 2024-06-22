#include "ctgl.h"
#include "time.h"
#include "stdio.h"

int main() {
	float startTime = (float)clock()/CLOCKS_PER_SEC;
	Pixel underscorePixel = {'_', {0,0,0}, {255,255,255}};
	Pixel hashtagPixel = {'#', {255,255,255}, {0,0,0}};
	Canvas canvas = ctgl_create_canvas(20,10);
	ctgl_fill_canvas(canvas, underscorePixel);
	ctgl_clear_screen();
	ctgl_render_sync(canvas);
	// for(int i = 0; i < canvas.height * canvas.width; i++){
	// 	ctgl_set_backgroundRGB(canvas.pixels + i, (int[3]) {255,255,255});
	// 	ctgl_render_sync(canvas);
	// 	ctgl_set_backgroundRGB(canvas.pixels + i, (int[3]) {0,0,0});
	// }
	ctgl_draw_line_naive(canvas, hashtagPixel, 0, 0, 19, 9);
	ctgl_draw_line_naive(canvas, hashtagPixel, 0, 9, 19, 0);

	// ctgl_set_text(canvas, "Hello, World!", 0, 0);
	ctgl_render_sync(canvas);
	ctgl_reset_terminal_color();
	float endTime = (float)clock()/CLOCKS_PER_SEC;
	printf("Test finished in: %f seconds\n", endTime - startTime);
}