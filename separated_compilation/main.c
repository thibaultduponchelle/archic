#include <stdio.h>
#include <malloc.h>
#include "mystruct.h"


typedef struct _mystruct mystruct;

int main(int argc, char* argv[]) {

	mystruct ms ; //= (mystruct*) malloc (sizeof(mystruct));
	ms.field1 = 1;
	printf("field1 : %d\n", ms.field1);
//	printf("main\n");

	return 0;

}
