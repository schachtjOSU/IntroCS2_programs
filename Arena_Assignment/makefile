CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time
PROGS := assign3
HEADERS = Base.hpp Character.hpp
OBJS = Base.o Character.o Arena.o

all: ${PROGS}

assign3: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o arena

Base.o: Base.cpp Base.hpp
	${CXX} -c $(@:.o=.cpp)

Character.o: Character.cpp Character.hpp
	${CXX} -c $(@:.o=.cpp)

Arena.o: Arena.cpp Base.hpp Character.hpp Base.cpp Character.cpp
	${CXX} -c $(@:.o=.cpp) 

clean:
	rm -f ${PROGS} *.o *~ 

