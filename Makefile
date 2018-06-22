CFLAGS = -Wall -g
LIBS  = -lm
CXX=g++
SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,bin/%,$(SRCS))

all: $(PROGS)

bin/%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<  $(LIBS)