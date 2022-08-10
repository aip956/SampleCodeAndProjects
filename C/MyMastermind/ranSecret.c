#include <stdio.h>
#include <stdlib.h>
#include "ranSecret.h"
#define MAX_SECRET_SIZE 128
#include <time.h>

char ranNum;
int i;

char* ranSecret(int secret_len, char* secrArr1) {

// int main(int secret_len, char** secrArr) {
    secret_len = 4;
    printf("I'm generating a random secret \n");
    printf("13strlen: %d\n", secret_len);
    srand(time(NULL));
    for (i = 0; i < secret_len; i++) {
        ranNum =  (48 + (rand() % 8));
        printf("%d %c\n", i, ranNum);
        secrArr1[i] = ranNum;
    } // Closes for int i
    secrArr1[i] = '\0';
    printf("19: %s\n", secrArr1);
    return secrArr1;
} // Closes function

// define a pointer
// dereference a pointer; access the h in hello world