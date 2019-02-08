#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))

int main(int argc, char* argv[]) {

	int x = CUBE(3);
	printf("CUBE 3 : %d\n",  x);
	int j = 5;
	int y = CUBE(++j);
	printf("CUBE ++5 : %d\n", y);
	

	return 0;
}
