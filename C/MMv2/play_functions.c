#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "make_input.h"
#include "play_functions.h"
#include <time.h>

int my_strlen(char* param_1) {
// a = param_1 // param_1 is my pointer; = a = Program
    int index = 0;
    int length = 0;
    for (index = 0; param_1[index] != '\0'; index++) {
        // printf("20 ind: %d\n", index);
        if (param_1[index] > 32) {
            // printf("ascii#: %d\n", param_1[index]);
            // printf("ascii char: %c\n", param_1[index]);
            // printf("ascii char: %c\n", param_1[index]);
            length++;
        } // Closes if
    } // Closes for
    printf("21Len: %d\n", length);
    return length;
 }; // Closes function

// game_state_ptr->secret = 2468
// game_arrays_ptr->secr_elem_count_arr
void fill_sec_array(t_game_arrays* game_arrays_ptr, t_game_state* game_state_ptr) {
    int index;
    for (index = 0; game_state_ptr->secret[index] != '\0'; index++) {
        // printf("30index: %d\n", index);
        // printf("31element: %c\n", game_state_ptr->secret[index]);
        int sec_ind = (game_state_ptr->secret[index]) - 48;
        // printf("33: %d\n", sec_ind);
        // printf("34: %d <=> %d\n", sec_ind, game_arrays_ptr->secr_elem_count_arr[sec_ind]);
        game_arrays_ptr->secr_elem_count_arr[sec_ind] += 1;
        // printf("36: %d <=> %d\n", sec_ind, game_arrays_ptr->secr_elem_count_arr[sec_ind]);
    } // Closes for
     for (int i = 0; i < 8; i++) {
        printf("39 i, elem_arr[ind]: %d, %d\n", i, game_arrays_ptr->secr_elem_count_arr[i]);
        }
} // Closes function
 

 // buffer[index] = char 1
 // buffer [0] = char 0 = ascii 48
 // buffer_elem = buffer[index] - 48 = 0
//  game_arrays_ptr->guess_elem_count_arr[index] = 

void fill_guess_array(t_game_arrays* game_arrays_ptr, char* buffer) {
    game_arrays_ptr->guess_elem_count_arr = {0, 0, 0, 0, 0, 0, 0, 0};
    int index;
    for (index = 0; index < 4; index++) {

        for (int i = 0; i < 8; i++) {
        printf("51 i, elem_arr[ind]: %d %d\n", i, game_arrays_ptr->guess_elem_count_arr[i]);
        }

        printf("43index: %d\n", index);  
        printf("44element: %c\n", buffer[index]);
        int guess_ind = (buffer[index]) - 48;
        printf("46: %d\n", guess_ind);        
        printf("47: %d <=> %d\n", guess_ind, game_arrays_ptr->guess_elem_count_arr[guess_ind]);
        game_arrays_ptr->guess_elem_count_arr[guess_ind] += 1;
        printf("49: %d <=> %d\n", guess_ind, game_arrays_ptr->guess_elem_count_arr[guess_ind]);

        for (int i = 0; i < 8; i++) {
        printf("63 i, elem_arr[ind]: %d %d\n", i,game_arrays_ptr->guess_elem_count_arr[i]);
        }
    } // Closes for
} // Closes function

int compareForX(t_game_state* game_state_ptr, char* buffer) {
    int X = 0; 
    for (int i = 0; i < 4; i++) {
        printf("74i: %d\n", i);
        printf("75secret_i: %c\n", game_state_ptr->secret[i]);
        printf("76guess_i: %c\n", buffer[i]);
        if (game_state_ptr->secret[i] == buffer[i]) {
            X++;
            printf("79i: %d, X: %d\n", i, X);
        }
    }
    return X;
} // closes

int compareForZ(t_game_arrays* game_arrays_ptr) {
    int Z = 0;
    for (int i = 0; i < 8; i++) {
        printf("68i: %d\n", i);
        printf("68secret[i]: %d\n",game_arrays_ptr->secr_elem_count_arr[i]);
        printf("69guess[i]: %d\n",game_arrays_ptr->guess_elem_count_arr[i]);
        printf("73: %d\n", game_arrays_ptr->secr_elem_count_arr[i] > 0 && game_arrays_ptr->guess_elem_count_arr[i] > 0);
        if (game_arrays_ptr->secr_elem_count_arr[i] > 0 && game_arrays_ptr->guess_elem_count_arr[i] > 0) {
            if (game_arrays_ptr->secr_elem_count_arr[i] <= game_arrays_ptr->guess_elem_count_arr[i]) {
                Z += game_arrays_ptr->secr_elem_count_arr[i];
                printf("70i: %d, Z: %d\n", i, Z);
            }
        } // if
    } // for
    return Z;
}

int play_round(t_game_state* game_state_ptr, t_game_arrays* game_arrays_ptr) {
    for (int round_num = 0; round_num < game_state_ptr->tries; round_num++) {
        printf("tries: %d\n", game_state_ptr->tries);
        printf("---\n");
        printf("Round %d\n", round_num);
        // top:; // Come back here if error
        int bytes;
        char* buffer = (char *)(calloc(4, sizeof(char)));
        bytes = read(0, buffer, 10);
        if (bytes == 0) {
            printf("36 bytes: %d\n", bytes);
            printf("Read EOF!\n");
            return 0;
        }
        else {
            buffer[bytes] = '\0';
            printf("56 bytes: %d\n", bytes);
            printf("57: %s\n", buffer);
            int guess_len = my_strlen(buffer);
            printf("guess_len: %d\n", guess_len);

            // if (guess_len != 4) { // Validate guess length
            //     printf("Wrong number of inputs\n");
            // };

            // while (checkSecret(buffer, guess_len) != 1) { // Validate guess is char numbers
            //     goto top;
            // };
            if (is_code_valid(buffer, 4) == 1) {
                fill_guess_array(game_arrays_ptr, buffer);
                int X = compareForX(game_state_ptr, buffer); 
                int Z = compareForZ(game_arrays_ptr); 
                int Y = Z - X;
                printf("Well placed pieces: %d\n", X);
                printf("Misplaced pieces: %d\n", Y);
                    if (X == 4) {
                        printf("Congratz! You did it!\n");
                        return 0;
                    } // Closes check for win
            } // if code valid
     
            if (round_num >= game_state_ptr->tries-1) {
                printf("Sorry, too many tries. The code was: %s\n", game_state_ptr->secret);
                return 0;
            }
        } // Closes else for EOF        
    } // Closes for tries < max tries
        
    return 0;

}



int play_game(t_game_state* game_state_ptr) {

t_game_arrays game_arrays = {
    .secr_elem_count_arr = {0, 0, 0, 0, 0, 0, 0, 0},
    .guess_elem_count_arr = {0, 0, 0, 0, 0, 0, 0, 0},
};
t_game_arrays *game_arrays_ptr = &game_arrays;
fill_sec_array(game_arrays_ptr, game_state_ptr);
printf("Will you find the secret code?\nPlease enter a valid guess of length 4, numbers 0 - 7\n");
play_round(game_state_ptr, game_arrays_ptr);

return 0;
}