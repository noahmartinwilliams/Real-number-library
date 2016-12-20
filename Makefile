libreal.so: real.cpp
	g++ -fPIC -shared -I . -c $^ -o $@


main: real.o main.cpp
	g++ $^ -o $@
	./main

real.o: real.cpp
	g++ -I . -c real.cpp -o real.o

.PHONY:
clean:
	rm real.o || true
	rm main || true
	rm libreal.so || true

install: libreal.so
	install libreal.so /usr/lib/
	install real.h /usr/include/
