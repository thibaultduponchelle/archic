#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>


int main(int argc, char* argv[]) {

	int i = 0;

	printf("argc : %d\n", argc);

	if(argc <= 1) {
		printf("Not enough argument\n");
		return 0;
	}


	int* tab = (int*) malloc(argc * sizeof(int));
	if(!tab) return 1;
	
	int index = 0;
	for(i = 1; i < argc ; i++) {
		printf("[%d]", atoi(argv[i])); 
		tab[index] = atoi(argv[i]);
		index ++;
	}
	
	printf("\n");


	int is_sorted = -1;
	while(is_sorted != 0) {
		is_sorted = 0;
		for(i = 0; i < argc - 1; i++) {
			int tmp;
			if(tab[i]> tab[i+1]) {
				tmp = tab[i+1];
				tab[i+1] = tab[i];
				tab[i] = tmp;
				is_sorted = -1;
			}
				
		}
	}


	for(i = 0; i < argc; i++) {
		printf("%d ", tab[i]); 
	}

	printf("\n");

	return 0;
} 	
