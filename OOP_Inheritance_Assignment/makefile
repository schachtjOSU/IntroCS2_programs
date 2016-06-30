CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time
PROGS := assign2
HEADERS = Item.hpp List.hpp
OBJS = item.o list.o shoplist.o

all: ${PROGS}

assign2: ${OBJS}
	${CXX} ${LDFLAGS} ${OBJS} -o shoplist

item.o: item.cpp Item.hpp
	${CXX} -c $(@:.o=.cpp)

list.o: list.cpp List.hpp
	${CXX} -c $(@:.o=.cpp)

shoplist.o: shoplist.cpp Item.hpp List.hpp item.cpp list.cpp
	${CXX} -c $(@:.o=.cpp) 

clean:
	rm -f ${PROGS} *.o *~ 

