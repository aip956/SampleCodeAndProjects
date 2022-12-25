#include <stdio.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int my_strlen(char* a){
  int length = strlen(a);
  int count = 0;
  int i;
  
   for( i = 0; i < length; i++)
        if(isalpha(a[i])) count++;

return count;
}



int main() {
    printf("25: %d\n", my_strlen(126));
    // printf("ac: %d\n", ac);
    return 0;
}


// gcc -o scratch scratch.c