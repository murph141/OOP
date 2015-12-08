GCC = g++
CFLAGS = #-Werror -Wbad-function-cast -Wall -Wshadow -ggdb3
SOURCES = source/main.cpp
OBJS = $(SOURCES:.cpp=.o)
HDRS = rapidxml/*.hpp headers/Map.h
EXECUTABLE = main

.PHONY: clean test all

all: $(SOURCES) $(EXECUTABLE) $(HDRS)

$(EXECUTABLE): $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.cpp.o: $(HDRS)
	$(GCC) $(CFLAGS) -c $*.cpp -o $*.o

clean:
	rm -f $(OBJS) $(EXECUTABLE) 
