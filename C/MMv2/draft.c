#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
// #include "make_input.h"
#include <time.h>
#ifndef STRUCT_CHAR_STRUCT
#define STRUCT_CHAR_STRUCT

typedef struct s_game_state
{
    // int length;
    int tries;
    char* secret;
    // char** av_arr;
    // int av_len;
    // char secret;
} t_game_state;
#endif

int my_strlen(char* param_1) {
// a = param_1 // param_1 is my pointer; = a = Program
    int index = 0;
    int length = 0;
    for (index = 0; param_1[index] != '\0'; index++) {
        // printf("20 ind: %d\n", index);
        // if (param_1[index] > 32) {
            // printf("ascii#: %d\n", param_1[index]);
            // printf("ascii char: %c\n", param_1[index]);
            printf("ascii char: %c\n", param_1[index]);
            length++;
            printf("23 Ind/Len: %d\n", length);
        // } // Closes if
    } // Closes for
    return length;
 }; // Closes function

 char* rand_secret(char* secret) {
    char ranNum;
    int i;
    srand(time(NULL));
    for (i = 0; i < 4; i++) {
        ranNum =  (48 + (rand() % 8));
        secret[i] = ranNum;
        printf("%c\n", secret[i]);
    } // Closes for int i
    // secret[i] = '\0';
    printf("19: %s\n", secret);
    return secret;
} // Closes function

int is_code_valid(char* code, int code_len) {
    int is_code_valid = 1;
    for (int i = 0; i < code_len; i++) {
        if (code[i] < 48 || code[i] > 55) {
            printf("Wrong input! \n");
            return is_code_valid = 0;
        };
    };
    printf("Code valid \n");
    return is_code_valid;
}; 



char* make_secret (char** av, int ac) {
    int i, av_index;
    printf("make_secret");
    char* secret;
    char *flag_c = "-c";
    int isFlagC = 0;
    int count = 0;
      printf("74 \n");
    for (av_index = 1; av_index < ac; av_index++) {
        printf("76, av_ind: %d\n", av_index);
        char* flag = av[av_index];
        printf("79 flag: %s\n", flag);
        for (i = 0; i < 2; i++) {
            if (flag_c[i] == flag[i]) {
                count ++;
                printf("count: %d\n", count);
                if (count == 2) { // found -c
                    isFlagC = 1; 
                    printf("87 \n");
                    printf("93 av ind+1: %s\n", av[av_index + 1]);
    //              check secret is valid
                        if (is_code_valid(av[av_index + 1], 4) == 1) {
                            char* secret = av[av_index + 1];
                            printf("88 sec: %c\n", *secret);
                            printf("89 sec: %s\n", secret);  
                            return secret;
                        } 
                    printf("100 \n");
                }
//             printf("102 \n");
            }     // closes search on av element
//         printf("104 \n");
        }; // closes for av
//     printf("106 \n");
    }
        if (isFlagC == 0) {
            rand_secret(secret);
            printf("120ransecr: %s\n", secret);
        };
//     printf("110 \n");
    printf("125*sec: %c\n", *secret);
    return secret;
}; // Closes make_secret

int make_tries (char** av, int ac){
    int i, av_index;
    printf("make tries");
    int tries = 10;
    char *flag_t = "-t";
    int count = 0;
    printf("129 \n");
    for (av_index = 1; av_index < ac; av_index++) {
        printf("130, av_ind: %d\n", av_index);
        char* flag = av[av_index];
        printf("132 flag: %s\n", flag);
        for (i = 0; i < 2; i++) {
            if (flag_t[i] == flag[i]) {
                count ++;
                printf("131count: %d\n", count);
                if (count == 2) { // found -t
                    printf("138 \n");
                    tries = atoi(av[av_index + 1]);
                    printf("140 av_ind+1: %d\n", av_index + 1);
                    printf("141 av ind+1: %s\n", av[av_index + 1]);
                    printf("142 tries: %d\n",tries);
                } // Closes isFlagT
            }
        }  
    }
    return tries;
}


t_game_state prep_init_state(int ac, char** av) {
   t_game_state game_state = {
        .secret = make_secret(av, ac),
        .tries = make_tries(av, ac),
    };
    printf("162 tries: %d\n", game_state.tries);
    printf("163 secr: %s\n", game_state.secret);
    printf("163 secr: %c\n", game_state.secret[2]);
    return game_state;
};



int main(int ac, char** av) {
    // printf("142_av: %s\n", av[1]);
    // printf("143_av: %s\n", av[2]);
    t_game_state game_state;
    game_state = prep_init_state(ac, av);
    printf("156 tries: %d\n", game_state.tries);
    printf("157 secr: %s\n", game_state.secret);

    

return 0;
}



// ./draft -c "0123" -t "4"
// gcc -o draft draft.c




      // for (i = 0; i < 4; i++) {
                        //     printf("88sec_in_av_ind : %d\n", i);
                        //     printf("89secret[i]: %s\n", av[av_index + 1]);
                        //     printf("90secret[i][secinav]: %c\n", av[av_index + 1][i]);
                        //     *secret[i] = av[av_index + 1][i];
                        //     printf("93secret[i]: %c\n", *secret[i]);
                        //     }