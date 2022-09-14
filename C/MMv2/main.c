#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "make_input.h"
#include <time.h>
// #ifndef STRUCT_CHAR_STRUCT
// #define STRUCT_CHAR_STRUCT

// typedef struct s_game_state
// {
//     int tries;
//     char secret[5];
// } t_game_state;
// #endif


int main(int ac, char** av) {
    // printf("142_av: %s\n", av[1]);
    // printf("143_av: %s\n", av[2]);
    t_game_state game_state;
    game_state = prep_init_state(ac, av);
    printf("156 tries: %d\n", game_state.tries);
    printf("157 secr: %s\n", game_state.secret);

    // play_game(game_state);

return 0;
}