#include "make_input.h"

#ifndef STRUCT_t_game_arrays
#define STRUCT_t_game_arrays

typedef struct s_game_arrays
{
    int secr_elem_count_arr[8];
    int guess_elem_count_arr[8];
} t_game_arrays;
#endif

void fill_array(t_game_arrays*, t_game_state*);
int play_game(t_game_state*);
