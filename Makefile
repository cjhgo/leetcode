CFLAGS = -Wall -g
LIBS  = -lm
CXX=/usr/bin/g++-6
SRCS = $(wildcard *.cpp)

PROGS = $(patsubst %.cpp,bin/%,$(SRCS))

all: $(PROGS)

bin/%: %.cpp
	$(CXX) $(CFLAGS) -o $@ $<  $(LIBS)