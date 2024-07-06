#include "ctgl.h"

int main () {
	Canvas canvas = ctgl_create_canvas(40,10);
	Pixel underscorePixel = {'_',{0,0,0}, {255,255,255}};
	int x = 0;
	int y = 0;
	int dx = 1;
	int dy = 1;


	ctgl_init();

	while(1) {
		ctgl_fill_canvas(canvas, underscorePixel);
		ctgl_set_text(canvas, "DVD", x, y);
		ctgl_render_canvas(canvas);
		if(x == 0) {
			dx = 1;
		} else if (x == canvas.width - 3) {
			dx = -1;
		}
		if(y == 0) {
			dy = 1;
		} else if (y == canvas.height - 1) {
			dy = -1;
		}
		x += dx;
		y += dy;

	}

	
}