libreal.so: real.cpp
	g++ -fPIC -shared -I . -c $^ -o $@


test: real.o test.cpp
	g++ $^ -o $@
	./test

real.o: real.cpp
	g++ -I . -c real.cpp -o real.o

.PHONY:
clean:
	rm real.o || true
	rm test || true
	rm libreal.so || true

install: libreal.so
	install libreal.so /usr/lib/
	install real.h /usr/include/
