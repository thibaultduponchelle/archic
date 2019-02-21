#include <stdio.h>

#include "foo.h"

#include "mystruct.h"

int main(int argc, char* argv[]) {
	mystruct s;
	printf("main\n");
	foo();
	return 0;
}
