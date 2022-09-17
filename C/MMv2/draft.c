#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
// #include "make_input.h"
#include <time.h>
#ifndef STRUCT_CHAR_STRUCT
#define STRUCT_CHAR_STRUCT

typedef struct s_game_state
{
    int tries;
    char secret[5];
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

 void rand_secret(t_game_state* game_state_ptr) {
    printf("rand_secret\n");
    char ranNum;
    int i;
    srand(time(NULL));
    for (i = 0; i < 4; i++) {
        printf("39: %d\n", i);
        ranNum =  (48 + (rand() % 8));
        printf("rannum: %c\n", ranNum);
        game_state_ptr->secret[i] = ranNum;
        printf("%c\n", game_state_ptr->secret[i]);
    } // Closes for int i
    game_state_ptr->secret[i] = '\0';
    printf("48: %c\n", game_state_ptr->secret[2]);
    printf("49: %s\n", game_state_ptr->secret);


}; // Closes function

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



void make_secret (char** av, int ac, t_game_state* game_state_ptr) {
    int i, av_index;
    printf("make_secret");
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
                if (count == 2) { 
                    isFlagC = 1; 
                    if (is_code_valid(av[av_index + 1], 4) == 1) {
                        for (int secr_ind = 0; secr_ind < 4; secr_ind++) {
                            game_state_ptr->secret[secr_ind] = av[av_index + 1][secr_ind];
                        };
                    };
                }; 
            };     
        }; 
    };
        if (isFlagC == 0) {
            printf("101isflagc: %d\n", isFlagC);
            rand_secret(game_state_ptr);
        };
}; 

int make_tries (char** av, int ac){
    int i, av_index;
    int tries = 10;
    char *flag_t = "-t";
    int count = 0;
    for (av_index = 1; av_index < ac; av_index++) {
        char* flag = av[av_index];
        for (i = 0; i < 2; i++) {
            if (flag_t[i] == flag[i]) {
                count ++;
                if (count == 2) { // found -t
                    tries = atoi(av[av_index + 1]);
                }; 
            };
        }; 
    };
    return tries;
};


t_game_state prep_init_state(int ac, char** av) {
   t_game_state game_state = {
        .secret = {0},
        .tries = make_tries(av, ac),
    };
    t_game_state *game_state_ptr = &game_state;
    make_secret(av, ac, game_state_ptr);
    return game_state;
};





int main(int ac, char** av) {
    t_game_state game_state;
    game_state = prep_init_state(ac, av);
    printf("156 tries: %d\n", game_state.tries);
    printf("157 secr: %s\n", game_state.secret);
return 0;
}



// ./draft -c "0123" -t "4"
// gcc -o draft draft.c
