#include <stdio.h>



#define s 10

int tab[s] = { 3, 2, 1, 4, 5, 6, 9, 8, 7, 0 }; 

int main(int argc, char* argv[]) {
	
	int selector = 0;
	while(selector < s) {
		int small_one = tab[selector];
		int small_one_index = selector;
		int i;
		for(i = selector; i < s; i++) {
			if(tab[i] < tab[selector]) {
				small_one = tab[i];
				small_one_index = i;
			}
		}
		int tmp = tab[selector]; 
		tab[selector] = small_one;
		tab[small_one_index] = tmp;
		selector ++;
	}

	int i;	
	for(i=0; i < s; i++) {
		printf("[%d]", tab[i]);
	} 

	printf("\n");  

	return 0;
}
