#include "make_input.h"

#ifndef STRUCT_t_game_arrays
#define STRUCT_t_game_arrays

typedef struct s_game_arrays
{
    int secr_elem_count_arr[8];
    int guess_elem_count_arr[8];
} t_game_arrays;
#endif

int my_strlen(char *);

void fill_array(t_game_arrays*, t_game_state*);
void fill_guess_array(t_game_arrays*, char*);
int compare_for_X(t_game_state*, char*);
int compare_for_Z(t_game_arrays*);
int play_round(t_game_state*, t_game_arrays*);
int play_game(t_game_state*);
