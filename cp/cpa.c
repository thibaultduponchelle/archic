#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int a[3] = { 1, 2, 3};
int b[3] = { 4, 5, 6};

int *c;
int *d;

int main(int argc, char* argv[]) {
	
	c = (int*) malloc(3);
	d = (int*) malloc(4);

	c[0] = 0;
	c[1] = 1;
	c[2] = 2;
	d[0] = 4;
	d[1] = 5;
	d[2] = 6;
	d[3] = 7;
	
	/* Impossible */
	/* a = b; */ 
	printf("Sizeof b : %d\n", sizeof(b));
	memcpy(a,b,sizeof(b));
	printf("[%d][%d][%d]\n", a[0], a[1], a[2]); 

	printf("a : %p\n", a); 
	printf("b : %p\n", b); 
	printf("c : %p\n", c); 
	printf("d : %p\n", d); 
	c = d;

	printf("[%d][%d][%d][%d]\n", c[0], c[1], c[2], c[3]); 
	


	return 0;
}
	
