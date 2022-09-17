#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "make_input.h"
#include <time.h>



int main(int ac, char** av) {
    t_game_state game_state;
    game_state = prep_init_state(ac, av);
    printf("156 tries: %d\n", game_state.tries);
    printf("157 secr: %s\n", game_state.secret);

    // play_game(game_state);

return 0;
}