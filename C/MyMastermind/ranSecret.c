#include <stdio.h>
#include <stdlib.h>
#include "ranSecret.h"
#define MAX_SECRET_SIZE 128
#include <time.h>


char ranSecret(int secret_len, char** secrArr) {
// int main(int secret_len, char** secrArr) {
    secret_len = 4;
    printf("I'm generating a random secret \n");
    printf("88strlen: %d\n", secret_len);
    srand(time(NULL));
    for (int i = 0; i < secret_len; i++) {
        char ranNum =  (48 + (rand() % 8));
        printf("%c\n", ranNum);
         *secrArr[i] = ranNum;
    } // Closes for int i
    return **secrArr;
} // Closes function