#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "functions.h"
#define MAX_SECRET_SIZE 128
#include <time.h>

int max_Tries = 10;
char secrArr[MAX_SECRET_SIZE] = {0};
int secret_len = 4;
int secr_elem_count_arr[MAX_SECRET_SIZE] = {0};
int i, X, Y, Z, round_num;



int main(int ac, char** av) {
    if (ac >= 3) {
        for (int av_ind = 1; av_ind <= ac-2; av_ind+=2) {
            // If flag is a c for av[1] or av[3]
            if (isFlagC(av[av_ind]) == 1) {
                secret_len = my_strlen(av[av_ind+1]);
                makeSecretArr(av[av_ind+1], secret_len, secrArr);
            } // Closes if it's "-c"
            // Check if flag is a t
            if (isFlagT(av[av_ind]) == 1) {
                max_Tries = makeMaxTries(av[av_ind+1]);
            } // Closes if it's "-t"
        } // For ac = 3 or 5 
    } // If ac > 3
    else {
        // secret_len = 4; // Default secret length = 4
        // max_Tries = 8;
        printf("I'll generate a secret of length 4 \n");
        // printf("%s\n", ranSecret(secret_len, secrArr));
    } // Closes if no -c

// Input

    fill_array(secr_elem_count_arr, secrArr);
    // print_array(secr_elem_count_arr, MAX_SECRET_SIZE);
    // printf("sec_len: %d\n", secret_len);
    printf("192 maxTries: %d\n", max_Tries);
    // printf("secrArr: %s\n", secrArr);
    printf("Will you find the secret code?\nPlease enter a valid guess of length %d, numbers 0 - 7\n", secret_len);

    for (round_num = 0; round_num < max_Tries; round_num++) {
        printf("---\n");
        printf("Round %d\n", round_num);
        top:;
        char* buffer = (char *)(calloc(secret_len, sizeof(char)));
        read(0, buffer, 10);
        int guess_len = my_strlen(buffer);

        if (guess_len != secret_len) { // Validate guess length
            printf("Wrong number of inputs\n");
            goto top;
        };
        if (checkSecret(buffer, guess_len) != 1) { // Validate guess is char numbers
            // printf("Wrong type input\n");
            goto top;
        };

        if (guess_len == secret_len) {
            if (checkSecret(buffer, guess_len) == 1) {
                int guess_elem_count_arr[MAX_SECRET_SIZE] = {0};
                fill_array(guess_elem_count_arr, buffer); // Create guess element count array
                // print_array(guess_elem_count_arr, MAX_SECRET_SIZE);
                compareForX(secrArr, buffer, secret_len); 
                compareForZ(&secr_elem_count_arr[0], &guess_elem_count_arr[0]); 
                Y = Z - X;
                printf("Well placed pieces: %d\n", X);
                printf("Misplaced pieces: %d\n", Y);
                if (X == secret_len) {
                    printf("Congratz! You did it!\n");
                    return 0;
                } // Closes check for win
            } // Closes check for valid guess are num chars
        } // Closes if guess = secret length 
    } // Closes for tries < max tries

    if (round_num >= max_Tries) {
        printf("Sorry, too many tries. The code was: %s\n", secrArr);
        return 0;
    }
    return 0;
} // Closes main



//  ./my_mastermind -c "0123" -t "4"

