all: main.cpp
	g++ -c main.cpp
	g++ main.o -o combination

clean:
	rm main.o combination

