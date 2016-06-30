CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time
PROGS := assign4
HEADERS = Arena.hpp Character.hpp
OBJS = Main.o Character.o Arena.o

all: ${PROGS}

assign4: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o assign4

Arena.o: Arena.cpp Arena.hpp
	${CXX} -c $(@:.o=.cpp)

Character.o: Character.cpp Character.hpp
	${CXX} -c $(@:.o=.cpp)

Main.o: Main.cpp Arena.hpp Character.hpp Arena.cpp Character.cpp
	${CXX} -c $(@:.o=.cpp) 

clean:
	rm -f ${PROGS} *.o *~ 

