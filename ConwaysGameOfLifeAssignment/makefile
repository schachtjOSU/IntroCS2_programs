CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time
PROGS := gamelife 
HEADERS = ConwayGameLife.hpp
OBJS = MainGame.o ConwayGameLife.o

all: ${PROGS}

gamelife: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o gamelife

MainGame.o: MainGame.cpp ConwayGameLife.cpp ConwayGameLife.hpp
	${CXX} -c MainGame.cpp ConwayGameLife.cpp ConwayGameLife.hpp 

clean:
	rm -f ${PROGS} *.o *~ 

