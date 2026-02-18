binary = bookindex-test
folder = book-index
objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

run: $(binary)
	./$(binary)

$(binary): $(objects)
	g++ -g3 -o $@ $^

%.o: %.cpp
	g++ -g3 -c -o $@ $<

clean:
	rm -f *.o

clear: clean
	rm -f *.zip $(binary) *.bmp

zip: clean
	zip $(folder) Makefile *.cpp *.h *.pxl
