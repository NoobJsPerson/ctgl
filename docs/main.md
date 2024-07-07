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
This struct holds the following data:
- `char symbol`: the character the pixel is going to contain.
- `short backgroundRGB[3]`: the rgb values for the color of the background of the pixel
- `short foregroundRGB[3]`: the rgb values for the color of the foreground of the pixel

### `Canvas`

```c
typedef struct _Canvas {
	int width;
	int height;
	Pixel *pixels;
} Canvas;
```

This struct represents a canvas that contains pixels and can be easily printed on the terminal screen using [ctgl_render_canvas](#ctgl_render_canvas). You can manipulate a canvas' pixels (either through CTGL functions or manually) to change how it will look when it gets rendered using [ctgl_render_canvas](#ctgl_render_canvas)<br>
This struct holds the following data:
- `int width`: the width of the canvas
- `int height`: the height of the canvas
- `Pixel *pixels`: A pointer to a pixel array that holds the canvas' pixels

### `void ctgl_init();`

A function that runs necessary code for the rest of the library's functions to function correctly. Make sure to call this function before any other CTGL functions in your program!

### `Pixel ctgl_create_pixel(char symbol, short bRed, short bGreen, short bBlue, short fRed, short fGreen, short fBlue);`

A function that creates a pixel using the given data and returns it.<br>
This function takes the following arguments:
- `char symbol`: the character the pixel is going to contain.
- `int bRed`: the red value of the background color the pixel
- `int bGreen`: the green value of the background color the pixel
- `int bBlue`: the blue value of the background color the pixel
- `int fRed`: the red value of the foreground color the pixel
- `int fGreen`: the green value of the foreground color the pixel
- `int fBlue`: the blue value of the foreground color the pixel

### `Canvas ctgl_create_canvas(int width, int height);`

A function that creates a canvas with the given width and height.<br>
**WARNING**: this function allocates memory! make sure to call [`ctgl_free_canvas`](#ctgl_free_canvas) when you don't need the canvas anymore or you might have a memory leak in your program!<br>
This function takes the following arguments:
- `int width`: the width of the canvas
- `int height`: the height of the canvas

### `void ctgl_hide_cursor();`

A function that hides the cursor.

### `void ctgl_show_cursor();`

A function that shows the cursor.

### `void ctgl_clear_screen();`

A function that clears the screen.

### `void ctgl_reset_cursor_pos();`

A function that resets the cursor position to (0,0) (which usually the top right of the terminal screen)

### `void ctgl_fill_canvas(Canvas canvas, Pixel pixel);`

A function that fills the given canvas with the given pixel<br>
This function takes the following arguments:
- `[Canvas](#canvas) canvas`: the canvas to be filled with given pixel
- `[Pixel](#pixel) pixel`: the pixel that the canvas will be filled with
