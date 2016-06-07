
main: real.o main.cpp
	g++ $^ -o $@
	./main

real.o: real.cpp
	g++ -I . -c real.cpp -o real.o

clean:
	rm real.o
	rm main
