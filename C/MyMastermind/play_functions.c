#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "make_input.h"
#include "play_functions.h"
#include <time.h>

int my_strlen(char* param_1) {
    int index = 0;
    int length = 0;
    for (index = 0; param_1[index] != '\0'; index++) {
        if (param_1[index] > 32) {
            length++;
        };
    };
    return length;
 };


void fill_sec_array(t_game_arrays* game_arrays_ptr, t_game_state* game_state_ptr) {
    int index;
    for (index = 0; game_state_ptr->secret[index] != '\0'; index++) {
        int sec_ind = (game_state_ptr->secret[index]) - 48;
        game_arrays_ptr->secr_elem_count_arr[sec_ind] += 1;
    };
};


void fill_guess_array(t_game_arrays* game_arrays_ptr, char* buffer) {
    for (int i = 0; i < 8; i++){
        game_arrays_ptr->guess_elem_count_arr[i] = 0;
    };
    int index;
    for (index = 0; index < 4; index++) {
        int guess_ind = (buffer[index]) - 48;
        game_arrays_ptr->guess_elem_count_arr[guess_ind] += 1;
    };
};


int compare_for_X(t_game_state* game_state_ptr, char* buffer) {
    int X = 0; 
    for (int i = 0; i < 4; i++) {
        if (game_state_ptr->secret[i] == buffer[i]) {
            X++;
        };
    };
    return X;
};


int compare_for_Z(t_game_arrays* game_arrays_ptr) {
    int Z = 0;
    for (int i = 0; i < 8; i++) {
        if (game_arrays_ptr->secr_elem_count_arr[i] > 0 && game_arrays_ptr->guess_elem_count_arr[i] > 0) {
            if (game_arrays_ptr->secr_elem_count_arr[i] <= game_arrays_ptr->guess_elem_count_arr[i]) {
                Z += game_arrays_ptr->secr_elem_count_arr[i];
                
            }
        };
    };
    return Z;
};

int play_round(t_game_state* game_state_ptr, t_game_arrays* game_arrays_ptr) {
    int round_num = 0; 
    while (round_num < game_state_ptr->tries) {
        printf("---\n");
        printf("Round %d\n", round_num);
        int round_complete = 0;
            while (round_complete == 0) {    
            int bytes;
            char* buffer = (char *)(calloc(4, sizeof(char)));
            bytes = read(0, buffer, 5);
            if (bytes == 0) {
                printf("Read EOF!\n");
                return 0;
            };
            if (is_code_valid(buffer) != 1){
                printf("Wrong input! \n");
                }
            else {
                buffer[bytes] = '\0';
                if (is_code_valid(buffer) == 1) { 
                    fill_guess_array(game_arrays_ptr, buffer);
                    int X = compare_for_X(game_state_ptr, buffer); 
                    int Z = compare_for_Z(game_arrays_ptr); 
                    int Y = Z - X;
                    if (X == 4) {
                            printf("Congratz! You did it!\n");
                            return 0;
                        };
                    printf("Well placed pieces: %d\n", X);
                    printf("Misplaced pieces: %d\n", Y);
                    round_complete = 1;   
                    round_num++;
                };
            };
        };
        if (round_num >= game_state_ptr->tries) {
            printf("Sorry, too many tries. The code was: %s\n", game_state_ptr->secret);
            return 0;
        };
    };
    return 0;
}


int play_game(t_game_state* game_state_ptr) {
    t_game_arrays game_arrays = {
        .secr_elem_count_arr = {0, 0, 0, 0, 0, 0, 0, 0},
        .guess_elem_count_arr = {0, 0, 0, 0, 0, 0, 0, 0},
    };
    t_game_arrays *game_arrays_ptr = &game_arrays;
    fill_sec_array(game_arrays_ptr, game_state_ptr);
    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    play_round(game_state_ptr, game_arrays_ptr);
return 0;
}