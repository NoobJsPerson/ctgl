test: test.o ctgl.o
		gcc -o -g test test.o ctgl.o
		@echo now you can run the command
test.o: test.c
		gcc -c -g test.c
ctgl.o: ctgl.c
		gcc -Werror -c -g ctgl.c

dvd: ctgl.o dvd.o
		gcc -o dvd -g dvd.o ctgl.o
		@echo now you can run the command

dvd.o: examples/dvd/dvd.c
		gcc -c -g examples/dvd/dvd.c -I.

clear:
		$(RM) test.exe dvd.exe test.o dvd.o ctgl.o