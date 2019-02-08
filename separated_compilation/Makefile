
all: main

main: main.o mystruct.o
	gcc -o $@ $^

.o : .c
	gcc -c $@ $<


.phony: all clean

clean: 
	rm -rf *.o main
