CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time
PROGS := raceGame
HEADERS = car.hpp region.hpp
OBJS = Main.o car.o region.o

all: ${PROGS}

raceGame: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o raceGame

car.o: car.cpp car.hpp
	${CXX} -c $(@:.o=.cpp)

region.o: region.cpp region.hpp
	${CXX} -c $(@:.o=.cpp)

Main.o: Main.cpp car.hpp car.cpp region.cpp region.hpp
	${CXX} -c $(@:.o=.cpp) 

clean:
	rm -f ${PROGS} *.o *~ 

