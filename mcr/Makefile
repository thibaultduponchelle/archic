all: mcr

mcr: mcr.o
	gcc -o $@ $^

%.o:%.c
	gcc -c $<

.PHONY: all clean
