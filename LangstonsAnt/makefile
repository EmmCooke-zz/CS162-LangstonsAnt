CXX = g++
CXXFLAGS =  -std=c++0x
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors
CXXFLAGS +=   -g
#CXXFLAGS +=   -O3
LDFLAGS =  -lboost_date_time
OBJS = Ant.o Board.o Menu.o Square.o validateInput.o main.o
SRCS = Ant.cpp Board.cpp Menu.cpp Square.cpp validateInput.cpp main.cpp
HEADERS = Ant.hpp Board.hpp Menu.hpp Square.hpp validateInput.hpp

#target: dependencies
#rule to build
#

Ant: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Ant

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c   $(@:.o=.cpp)

.PHONY: clean
clean:
	rm ${OBJS} Ant
