# CTGL Documentation



```c
#include "ctgl.h"

int main() {
	Canvas canvas = ctgl_create_canvas(50,20);
	Pixel pixel = ctgl_create_pixel('_', 0, 0, 0, 255, 255 ,255);
	ctgl_init();
	ctgl_fill_canvas(canvas, pixel);
	ctgl_render_canvas(canvas);
}
```

## API Reference


### `Pixel`

```c
typedef struct _Pixel {
	char symbol;
	short backgroundRGB[3];
	short foregroundRGB[3];
} Pixel;
```

This struct represents a pixel that is going to be printed on the terminal.<br>
It holds the following data:
- `char symbol`: the character the pixel is going to contain.
- `short backgroundRGB[3]`: the rgb values for the color of the background of the pixel
- `short foregroundRGB[3]`: the rgb values for the color of the foreground of the pixel



### `void ctgl_init();`

A function that runs necessary code for the rest of the library's functions to function correctly. Make sure to call this function before any other CTGL functions in your program!

### `Pixel ctgl_create_pixel(char symbol, short bRed, short bGreen, short bBlue, short fRed, short fGreen, short fBlue);`

A function that creates a pixel using the given data and returns it.<br>
It takes the following arguments:
- `char symbol`: the character the pixel is going to contain.
- `int bRed`: the red value of the background color the pixel
- `int bGreen`: the green value of the background color the pixel
- `int bBlue`: the blue value of the background color the pixel
- `int fRed`: the red value of the foreground color the pixel
- `int fGreen`: the green value of the foreground color the pixel
- `int fBlue`: the blue value of the foreground color the pixel

### `Canvas ctgl_create_canvas(int width, int height);`

A function that creates a canvas with the given width and height.
**WARNING**: this function allocates memory! make sure to call [`ctgl_free_canvas`](#ctgl_free_canvas) when you don't need the canvas anymore or you might have a memory leak in your program!
