CXXFLAGS = -Wall #-g
CXX = g++


main: main.o log.o
	${CXX} $^ ${CXXFLAGS} -o $@
	./main

clean:
	del -f *.o *.exe