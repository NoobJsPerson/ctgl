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

This struct represents a pixel that is going to be printed on the terminal.
It holds the following data:
- `symbol`: the character the pixel is going to contain.
- `backgroundRGB`: the rgb values for the color of the background of the pixel
- `foregroundRGB`: the rgb values for the color of the foreground of the pixel



### `void ctgl_init();`

A function that runs necessary code for the rest of the library's functions to function correctly. Make sure to call this function before any other CTGL functions in your program!
