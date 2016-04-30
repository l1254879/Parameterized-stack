
COMPILER = g++

run: all
	./a.out

all: stack.h Driver2.cpp
	$(COMPILER) stack.h Driver2.cpp


clear:
	rm -rf *.o *.out
