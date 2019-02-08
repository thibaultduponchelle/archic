
#include "mystruct.h"
#include <malloc.h> 

typedef struct _mystruct mystruct;

mystruct* se_mystruct() {

	mystruct* ms = (mystruct*) malloc(sizeof(mystruct));
	if(!ms) {
		// error
		return NULL;
	}
	return ms;
}

