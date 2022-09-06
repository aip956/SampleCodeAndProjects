#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "make_input.h"

#ifndef STRUCT_CHAR_STRUCT
#define STRUCT_CHAR_STRUCT

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
        // .secret = {0},
    };
    make_secret_and_tries(*av, &secret_and_tries);
return 0;
}