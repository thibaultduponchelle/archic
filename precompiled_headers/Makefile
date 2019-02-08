all: main

pc.h.gch: pc.h
	gcc -c pc.h

main: main.c pc.h.gch
	gcc -o main main.c -H
