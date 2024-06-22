#include "ctgl.h"
#include "time.h"
#include "stdio.h"

int main() {
	float startTime = (float)clock()/CLOCKS_PER_SEC;
	Pixel underscorePixel = {'_', {255,0,0}, {255,0,0}};
	Pixel hashtagPixel = {'#', {0,255,0}, {0,255,0}};
	Canvas canvas = ctgl_create_canvas(50,20);
	ctgl_fill_canvas(canvas, underscorePixel);
	ctgl_clear_screen();
	ctgl_render_sync(canvas);
	// for(int i = 0; i < canvas.height * canvas.width; i++){
	// 	ctgl_set_backgroundRGB(canvas.pixels + i, (int[3]) {255,255,255});
	// 	ctgl_render_sync(canvas);
	// 	ctgl_set_backgroundRGB(canvas.pixels + i, (int[3]) {0,0,0});
	// }
	ctgl_draw_line_naive(canvas, hashtagPixel, 0, (canvas.height-1)/3, canvas.width-1, canvas.height-1);
	ctgl_draw_line_naive(canvas, hashtagPixel, 0, canvas.height-1, canvas.width-1, (canvas.height-1)/3);
	ctgl_draw_line_naive(canvas, hashtagPixel, 0, canvas.height-1, (canvas.width-1)/2, 0);
	ctgl_draw_line_naive(canvas, hashtagPixel, (canvas.width-1)/2, 0, canvas.width-1, canvas.height-1);
	ctgl_draw_line_naive(canvas, hashtagPixel, 0, (canvas.height-1)/3, canvas.width-1, (canvas.height-1)/3);


	


	// ctgl_set_text(canvas, "Hello, World!", 0, 0);
	ctgl_render_sync(canvas);
	ctgl_reset_terminal_color();
	float endTime = (float)clock()/CLOCKS_PER_SEC;
	printf("Test finished in: %f seconds\n", endTime - startTime);
}