GCC = g++
CFLAGS = -ggdb3#-Werror -Wbad-function-cast -Wall -Wshadow -ggdb3
SOURCES = source/main.cpp
OBJS = $(SOURCES:.cpp=.o)
HDRS = headers/Map.h
EXECUTABLE = main
INPUT = inputs/sample.xml

.PHONY: clean test all run

all: $(SOURCES) $(EXECUTABLE) $(HDRS)

$(EXECUTABLE): $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.cpp.o: ../$(HDRS)
	$(GCC) $(CFLAGS) -c $*.cpp -o $*.o

clean:
	rm -f $(OBJS) $(EXECUTABLE) 

run: clean all
	@clear
	./$(EXECUTABLE) $(INPUT)
