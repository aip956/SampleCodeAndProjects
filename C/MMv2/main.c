#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "make_input.h"




int main(int ac, char** av) {
    printf("%d\n", ac);

    char_struct secret_and_tries = 
    {
        .length = 4,
        .tries = 10,
        // .secret = {0},
    };
    make_secret_and_tries(*av, &secret_and_tries);
return 0;
}