#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
// #include "make_input.h"
#include <time.h>
#ifndef STRUCT_CHAR_STRUCT
#define STRUCT_CHAR_STRUCT

typedef struct s_char_array
{
    int length;
    int tries;
    char* secret;
    char** av_arr;
    int av_len;
} char_struct;
#endif

int my_strlen(char* param_1) {
// a = param_1 // param_1 is my pointer; = a = Program
    int index = 0;
    int length = 0;
    for (index = 0; param_1[index] != '\0'; index++) {
        // printf("20 ind: %d\n", index);
        if (param_1[index] > 32) {
            // printf("ascii: %d\n", param_1[index]);
            // printf("ascii#: %d\n", param_1[index]);
            // printf("ascii char: %c\n", param_1[index]);
            length++;
            // printf("23 Ind/Len: %d\n", length);
        } // Closes if
    } // Closes for
    return length;
 }; // Closes function

 char* ranSecret(int secret_len, char* secret) {
    // printf("I'm generating a random secret \n");
    // printf("13strlen: %d\n", secret_len);
    char ranNum;
    int i;
    srand(time(NULL));
    for (i = 0; i < secret_len; i++) {
        ranNum =  (48 + (rand() % 8));
        // printf("%d %c\n", i, ranNum);
        secret[i] = ranNum;
    } // Closes for int i
    secret[i] = '\0';
    // printf("19: %s\n", secret);
    return secret;
} // Closes function

char is_code_valid(char* inp_secret, int secret_len) {
    int is_code_valid = 1;
    // Check input secret is valid, and paste into secret array
    // inp_secret is the input string after -c flag
    for (int i = 0; i < secret_len; i++) {
        if (inp_secret[i] < 48 || inp_secret[i] > 55) {
            printf("Wrong input! \n");
            return is_code_valid = 0;
        } // Closes if not ascii 0 - 9
    } // Closes for length of secret
    return is_code_valid;
}; // Closes function


char make_secret (char_struct* s_and_t){
    int i, av_index=1, secret_len;
    // int av_len = my_strlen(av);
    printf("69 ac: %d\n", s_and_t->av_len);
    char *flag_c = "-c";
    int isFlagC = 0;
    int count = 0;
    char *secret;
    while (av_index < s_and_t->av_len) {
        // for each flag in av
        char* flag = s_and_t->av_arr[i];
        // printf("76 flag: %s\n", flag);
        // int flag_len = my_strlen(s_and_t->av_arr[i]); // length of element
        for (i = 0; i < 2; i++) {
            if (flag_c[i] == flag[i]) {
                // printf("-c, flag: %c %c\n", flag_c[i],flag[i]);
                count ++;
                // printf("count: %d\n", count);
                if (count == 2) { // found -c
                    secret = s_and_t->av_arr[av_index + 1];
                    isFlagC = 1;
                    secret_len = my_strlen(secret);
                    printf("89 sec: %s\n", secret);
                    printf("secret_len: %d\n", secret_len);
                    if (is_code_valid(secret, secret_len) == 0) {
                        secret = NULL;
                        printf("92 sec: %s\n", secret);
                        };
                    return *secret;
                } // Closes if -c
            }
        }     // closes search on av element
            if (isFlagC == 0) {
                ranSecret(secret_len, secret);
            };
        av_index++;
    }; // closes for av
    return *secret;
}; // Closes make_secret





void make_secret_and_tries(char_struct* s_and_t) {
    // s_and_t->length = secret_length;
    *s_and_t->secret = make_secret(s_and_t);
    // printf("av: %c\n", **av);
    //    printf("101av: %c\n", av_arr);
    // printf("102: %c\n", make_secret(av));

    // s_and_t->secret = "0033";
    // printf("secret: %s\n", s_and_t->secret);
    // printf("tries: %d\n", s_and_t->tries);
    printf("108_av_arr: %s\n", s_and_t->av_arr[2]);
    // s_and_t->tries = make_max_tries(*av);    
};



int main(int ac, char** av) {
    // char** av_arr = &av[0];
    // printf("ac: %d\n", ac);
    // char array_for_av[6] = "";



    // printf("116_av: %s\n", av[1]);
    // printf("116_av: %s\n", av[2]);
    char_struct secret_and_tries = 
    {
        .length = 4,
        .tries = 10,
        .av_arr = av,
        .av_len = ac,
        // .secret = {0},
    };
    // for (int i = 1; i < ac; i++) {
    //     secret_and_tries.av_arr[i] = av[i];
    //     printf("129_av_arr: %s\n", secret_and_tries.av_arr);
    // }
    printf("131_av_arr: %s\n", secret_and_tries.av_arr[2]);
    printf("132_av_len: %d\n", secret_and_tries.av_len);
    make_secret_and_tries(&secret_and_tries);
return 0;
}



// ./draft -c "0123" -t "4"
// gcc -o draft draft.c