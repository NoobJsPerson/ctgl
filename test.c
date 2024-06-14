#include "ctgl.h"

int main() {
	Pixel underscorePixel = {'_', {0,0,0}, {255,255,255}};
	Canvas canvas = ctgl_create_canvas(10,10);
	ctgl_fill_canvas(canvas, underscorePixel);
	ctgl_clear_screen();
	ctgl_render_sync(canvas);
	for(int i = 0; i < 100; i++){
		ctgl_set_backgroundRGB(canvas.pixels + i, (int[3]) {255,255,255});
		ctgl_render_sync(canvas);
		ctgl_set_backgroundRGB(canvas.pixels + i, (int[3]) {0,0,0});
	}
	ctgl_reset_terminal_color();



	
}