test: test.o ctgl.o
		gcc -o test test.o ctgl.o
		@echo now you can run the command
test.o: test.c
		gcc -c -g test.c
ctgl.o: ctgl.c
		gcc -c -g ctgl.c