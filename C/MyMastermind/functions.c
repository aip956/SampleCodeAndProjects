#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#define MAX_SECRET_SIZE 128
#include <time.h>
#include <unistd.h>
#include <time.h>

char ranNum;
int i;

char* ranSecret(int secret_len, char* secrArr1) {
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


int my_strlen(char* param_1) {
// a = param_1 // param_1 is my pointer; = a = Program
    int index = 0;
    int length = 0;
    for (index = 0; param_1[index] != '\0'; index++) {
        // printf("20 ind: %d\n", index);
        if (param_1[index] > 30) {
            // printf("ascii: %d\n", param_1[index]);
            length++;
            // printf("23 Ind/Len: %d\n", length);
        } // Closes if
    } // Closes for
    return length;
 } // Closes function

int isFlagC (char* inp_flag){
    int i;
    int flag_len = my_strlen(inp_flag);
    char *flag_c = "-c";
    int isFlagC = 1;
        for (i = 0; i < flag_len; i++) {
            if (flag_c[i] != inp_flag[i]) {
                return isFlagC = 0;
            } // Closes if, not a "c"
        } // Closes for
    return isFlagC;
} // Closes isFlagC


int isFlagT (char* inp_flag){
    int i;
    int flag_len = my_strlen(inp_flag);
    char *flag_t = "-t";
    int isFlagT = 1;
        for (i = 0; i < flag_len; i++) {
            if (flag_t[i] != inp_flag[i]) {
                return isFlagT = 0;
            } // Closes if, not a "t"
        } // Closes for
    return isFlagT;
} // Closes isFlagT

char checkSecret(char* inp_secret, int secret_len) {
    int isInpSecrValid = 1;
    // Check input secret is valid, and paste into secret array
    // inp_secret is the input string after -c flag
    for (int i = 0; i < secret_len; i++) {
        if (inp_secret[i] < 48 || inp_secret[i] > 55) {
            printf("Wrong input! \n");
            return isInpSecrValid = 0;
        } // Closes if not ascii 0 - 9
    } // Closes for length of secret
    return isInpSecrValid;
} // Closes function


// pass in the pointer to secrArr to first char
char makeSecretArr(char* inp_secret, int secret_len, char* secrArr) {
    int i;
    // int secret_len = my_strlen(inp_secret);
    // printf("66strlen: %d\n", secret_len);
    // printf("64inpsec: %s\n", inp_secret);
    // printf("65: %d\n", checkSecret(inp_secret, secret_len) == 1);
    if (checkSecret(inp_secret, secret_len) == 1) {
        for (i = 0; i < secret_len; i++) {
            secrArr[i] = inp_secret[i];
            // printf("68: %c\n", secrArr[i]);
        } // Closes for
    }
    // printf("74: %s\n", secrArr);
    return *secrArr;
} // Closes function

char makeMaxTries(char* inp_tries) {
    return atoi(inp_tries);
} // Closes function


void fill_array(int* array, char* str) {
    int index;
    // printf("CURRENT STRING: %s\n", str);
    for (index = 0; str[index] != '\0'; index++) {
        // if (array[(int)str[index]] != '"') 
        // {
        array[(int)str[index]] += 1;
        // printf("%c <=> %d\n", str[index], array[(int)str[index]]);
        // printf("ascii: %d\n", str[index]);
        // } // Closes if
    } // Closes for
} // Closes function

void print_array(int* array, int size_array) {
    int index;
    for (index = 0; index < size_array; index++){
        // bypass garbage characters
        // printf("index: %d\n", index);
        if (array[index] > 0) {
            // printf("%c:%d\n", index, array[index]);
        } // Closes if
    } // Closes for
} // Closes function
// Exact matches
int compareForX(char* secrArr, char* guess, int secret_len) {
    X = 0;
    for (i = 0; i < secret_len; i++) {
        if (secrArr[i] == guess[i]) {
            X++;
            // printf("ind: %d, X: %d\n", i, X);
        } // Closes if
    } // Closes for
    return X;
} // Closes function

// Right number, wrong place matches
int compareForZ(int* secr_elem_count_arr, int* guess_elem_count_arr) {
    Z = 0;
    for (i = 48; i < 56; i++) {
        // printf("i: %d %c\n", i, i);
        // printf("142secElAr[i] %d\n", secr_elem_count_arr[i]);
        // printf("143guessElAr[i] %d\n", guess_elem_count_arr[i]);

        if (secr_elem_count_arr[i] > 0 && guess_elem_count_arr[i] > 0) {
            if (secr_elem_count_arr[i] <= guess_elem_count_arr[i]) {
                Z += secr_elem_count_arr[i];
                // printf("144 Z: %d\n", Z);
            } // Closes if secr count < guess count
            else {
                // printf("147 Z: %d\n", Z);
                Z += guess_elem_count_arr[i];
                // printf("149 Z: %d\n", Z);
            } // Closes else
        } // Closes if not = 0
    } // Closes for
    return Z;
} // Closes function



    // print_array(secr_elem_count_arr, MAX_SECRET_SIZE);
    // printf("sec_len: %d\n", secret_len);
    // printf("192 maxTries: %d\n", max_Tries);
    // printf("secrArr: %s\n", secrArr);