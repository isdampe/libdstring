CXX = gcc
src = $(wildcard src/*.c examples/example.c)
obj = $(src:.c=.o)

LDFLAGS = -std=c99 -O2

example: $(obj)
	@mkdir -p bin
	$(CXX) -g -o bin/$@ $^ $(LDFLAGS) $(OSFLAGS)

clean:
	rm $(obj)