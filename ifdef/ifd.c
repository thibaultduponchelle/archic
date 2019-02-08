#include <stdio.h>

void do_something() {
	printf("Hello\n");
	return;
}

#ifdef TEST
/* Could be compiled standalone with -DTEST */
/* Use this trick for unit tests ! */
int main(int argc, char* argv[]) {

	do_something();
	return 0;
}
#endif
