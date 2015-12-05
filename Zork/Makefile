GCC = g++
CFLAGS = #-Werror -Wbad-function-cast -Wall -Wshadow -ggdb3
SOURCES = main.cpp
OBJS = $(SOURCES:.cpp=.o)
HDRS = rapidxml/*.hpp headers/*.h
EXECUTABLE = $(SOURCES:.cpp=)

.PHONY: clean test all run

all: source/$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(GCC) $(CFLAGS) -c $*.cpp

clean:
	rm -f $(OBJS) $(EXECUTABLE) 
