# ctgl
### A graphical library for terminals written in C (WIP)
This is a simple graphical library for terminals written in C that aims to facilitate drawing lines and shapes on terminal window. It could be used to make simple animations and terminal games.<br>
It is still a work in progress but in its current state it has the following features:
- Implements a Canvas with a set width, height and number of pixels that you can manipulate directly or use library functions to do so
- Can render the canvas on top of a previous render by setting the cursor to the beginning
- Adds functions to hide and show the cursor and reset the cursor's position to the beginning
- Adds portable function to clear the screen
- Adds functions to manipulate a pixel's foreground color, background color and symbol
- Has support for True color (24-bit) so you can make colorful masterpieces
- Implements a basic algorithm to draw lines (more advanced algorithms like Bresenham's will be added soon)
## How to use
You can use the library by cloning the repo and including it in the top of your source C file like in this (this will allow to use ctgl functions and structs in your code)
```
#include "path/to/cloned/repo/ctgl.h"
```
and then you can run the following commands in a terminal in the folder where your source C file is located (assuming gcc)
```
gcc -c nameofyoursourcefile.c
gcc -c path/to/cloned/repo/ctgl.c
gcc -o main nameofyoursourcefile.o ctgl.o
```
and you can use the following command to run your resulting program<br>
On Linux
```
./main
```
On Windows
```
.\main.exe
```
## Running Tests
As of now the tests are used to test stuff during developement. A more organised way to test the library is planned soon.
To run the tests, execute the following command (requires make and gcc)
```
make
```
then you can run the resulting program using:
```
./test
```
On Linux

```
.\test.exe
```
On Windows
