#ifndef STRUCT_t_game_state
#define STRUCT_t_game_state

typedef struct s_game_state
{
    int tries;
    char secret[5];
} t_game_state;
#endif


int my_strlen(char*);
void rand_secret(t_game_state*);
int is_code_valid(char*);
void make_secret(char**, int, t_game_state*);
int make_tries(char**, int);
t_game_state prep_init_state(int, char**);