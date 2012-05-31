all: main.c
	gcc -c main.c
	gcc main.o -o combo

clean:
	rm main.o combo

