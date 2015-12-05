GCC = g++
CFLAGS = #-Werror -Wbad-function-cast -Wall -Wshadow -ggdb3
SOURCES = source/main.cpp
OBJS = $(SOURCES:.cpp=.o)
HDRS = rapidxml/*.hpp headers/*.h
EXECUTABLE = main

.PHONY: clean test all run

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(GCC) $(CFLAGS) -c $*.cpp -o $*.o

clean:
	rm -f $(OBJS) $(EXECUTABLE) 
