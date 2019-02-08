all: cpa

cpa: cpa.o
	gcc -o $@ $^

%.o:%.c
	gcc -c $<

.PHONY: all clean
