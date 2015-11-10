GCC = g++
SOURCES = HW13.cpp
OBJS = $(SOURCES:.cpp=.o)
HDRS = 
EXECUTABLE = $(SOURCES:.cpp=)

.PHONY: all clean

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS) $(HDRS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
	$(GCC) $(CFLAGS) -c $*.cpp


clean:
	rm -rf *.o $(EXECUTABLE)

run: all
	./$(EXECUTABLE)
