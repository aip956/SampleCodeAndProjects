#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

#ifndef STRUCT_CHAR_ARRAY
#define STRUCT_CHAR_ARRAY

typedef struct s_char_array
{
    int length;
    int tries;
    char* secret;
} char_struct;
#endif




int main(int ac, char** av) {

    char_struct secret_and_tries = 
    {
        .length = 4,
        .tries = 10,
        .secret = make_random_secret(4),
    };

make_secret_and_tries(char** av);

}