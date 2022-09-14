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
    // printf("50: %c\n", *game_state_ptr);

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
                printf("count: %d\n", count);
                if (count == 2) { // found -c
                    isFlagC = 1; 
                    printf("87 \n");
                    printf("93 av ind+1: %s\n", av[av_index + 1]);
                        if (is_code_valid(av[av_index + 1], 4) == 1) {
                            char* secret = av[av_index + 1];
                            printf("88 sec: %c\n", *secret);
                            printf("89 sec: %s\n", secret);  
                            printf("100 \n");
                        }
                }
//             printf("102 \n");
            }     // closes search on av element
//         printf("104 \n");
        }; // closes for av
//     printf("106 \n");
    }
        printf("isflagc: %d\n", isFlagC);
        if (isFlagC == 0) {
            printf("101isflagc: %d\n", isFlagC);

            // char rand_secret_arr[4]="";
            // char ranNum;
            // int i_of_ran_secr;
            // srand(time(NULL));
            // for (i_of_ran_secr = 0; i_of_ran_secr < 4; i_of_ran_secr++) {
            //     ranNum =  (48 + (rand() % 8));
            //     rand_secret_arr[i_of_ran_secr] = ranNum;
            //     printf("%c\n", ranNum);
            //     printf("118 rand_sec[i]: %d, %c\n", i_of_ran_secr, rand_secret_arr[i_of_ran_secr]);
            // } // Closes for int i
            // rand_secret_arr[i_of_ran_secr] = '\0';
            rand_secret(game_state_ptr);
            // printf("109rand_secr: %s\n", secret); 

        };
    printf("110 \n");
    // printf("121*sec: %c\n", *secret);
    // printf("122sec: %s\n", secret);

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
        .secret = {0},
        .tries = make_tries(av, ac),
    };
    t_game_state *game_state_ptr = &game_state;
    make_secret(av, ac, game_state_ptr);
    printf("162 tries: %d\n", game_state.tries);
    printf("163 secr: %s\n", game_state.secret);
    printf("163 secr: %c\n", game_state.secret[2]);
    return game_state;
};


