#include <stdio.h>
#include <stdlib.h>
#include "randoSecret.h"
#define MAX_SECRET_SIZE 128


int randoSecret() {
    int secret[MAX_SECRET_SIZE];
    for (int i = 0; i < 4; i++) {
        // int ranNum = (rand() % 8);
        secret[i] = (rand() % 8);
        // printf("%s\n", &secret[0]);
        // printf("%d\n", secret[i]);
    } // Closes for int i
    printf("15 %d\n", *secret);
     printf("%d\n", secret[1]);
      printf("%d\n", secret[2]);
    return *secret;
} // Closes function