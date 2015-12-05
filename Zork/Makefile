GCC = g++
PARAMS = #Override in command line (or here) is parameters are present
DIRECTORY = #(Override in command line (or here) if you want to compile a different directory
CFLAGS = #-Werror -Wbad-function-cast -Wall -Wshadow -ggdb3
SOURCES = main.cpp
OBJS = $(SOURCES:.cpp=.o)
HDRS = *.hpp
EXECUTABLE = $(SOURCES:.cpp=)

.PHONY: clean test all run

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(GCC) $(CFLAGS) -c $*.cpp


clean:
	rm -f $(OBJS) $(EXECUTABLE) 
