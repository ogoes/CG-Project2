flags = `pkg-config --cflags --libs freeglut gl glu`


main: comp
	./main

comp:
	gcc main.c ${flags} -o main

clean:
	rm main

