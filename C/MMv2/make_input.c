#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <time.h>
#include "make_input.h"



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
    char ran_char;
    int ran_num;
    int possible[8] = {'0','0','0','0','0','0','0','\0'};
    int i = 0;
    srand(time(NULL));
    while (i < 4) {
        ran_num = (rand() % 8);
        if (possible[ran_num] != 1) {
            ran_char = 48 + ran_num;
            game_state_ptr->secret[i] = ran_char;
            possible[ran_num] = 1;
            i++;
        }; 
    };
    game_state_ptr->secret[i] = '\0';
}; 

int is_code_valid(char* code, int code_len) {
    int is_code_valid = 1;
    for (int i = 0; i < code_len; i++) {
        if (code[i] < 48 || code[i] > 55) {
            printf("Wrong input! \n");
            return is_code_valid = 0;
        };
    };
    return is_code_valid;
}; 



void make_secret (char** av, int ac, t_game_state* game_state_ptr) {
    int i, av_index;
    char *flag_c = "-c";
    int isFlagC = 0;
    int count = 0;
    for (av_index = 1; av_index < ac; av_index++) {
        char* flag = av[av_index];
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


// ./my_mastermind -c "2345" -t "4"