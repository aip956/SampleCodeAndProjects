#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "make_input.h"
#include "play_functions.h"
#include <time.h>



int main(int ac, char** av) {
    t_game_state game_state;
    game_state = prep_init_state(ac, av);
    play_game(&game_state);

return 0;
};