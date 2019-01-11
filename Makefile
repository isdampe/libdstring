CXX = gcc
src = $(wildcard src/*.c examples/example.c)
obj = $(src:.c=.o)

LDFLAGS = -std=c11 -O3 -Wall

example: $(obj)
	@mkdir -p bin
	$(CXX) -g -o bin/$@ $^ $(LDFLAGS) $(OSFLAGS)

clean:
	rm $(obj)
