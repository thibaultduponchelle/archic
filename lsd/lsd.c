#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]) {
  int n;
  
  srand(time(NULL)); //seed 
  for(n = 1; n < argc; n++) {
    int i = 0;
    for(i = 0; i < strlen(argv[n]); i++) {
      int r = rand() % 7; // color
      int s = rand() % 9; // style
      printf("\033[%d;%dm%c\033[0m", s, r + 31, argv[n][i]);
    }
    printf(" "); // between words
  }

  printf("\n\n\n");

  return 0;
}
    
