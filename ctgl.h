#ifndef CTGL_H
#define CTGL_H

#ifdef __cplusplus
extern "C" {
#else
#include <stdbool.h>
#endif

typedef struct {
	char symbol;
	int backgroundColorRGB[3];
	int foregroundColorRGB[3];
} Pixel;

typedef struct {
	int width;
	int height;
	Pixel **pixels;
} Canvas;

#ifdef __cplusplus
}
#endif
#endif // CTGL_H