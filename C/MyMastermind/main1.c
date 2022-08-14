#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "ranSecret.h"
#define MAX_SECRET_SIZE 128
#include <time.h>

int max_Tries;
char secrArr[MAX_SECRET_SIZE] = {0};
int secret_len;
int secr_elem_count_arr[MAX_SECRET_SIZE] = {0};
int guess_elem_count_arr[MAX_SECRET_SIZE] = {0};
int i, X, Y, Z, round_num;


int my_strlen(char* param_1) {
// a = param_1 // param_1 is my pointer; = a = Program
    int index = 0;
    while (param_1[index] != '\0') {
    index++;
    }
    return index;
 }

int isFlagC (char* inp_flag){
    int i;
    int flag_len = my_strlen(inp_flag);
    char *flag_c = "-c";
    int isFlagC = 1;
        for (i = 0; i < flag_len; i++) {
            if (flag_c[i] != inp_flag[i]) {
                return isFlagC = 0;
            } // Closes if, not a "c"
        } // Closes for
    return isFlagC;
} // Closes isFlagC


int isFlagT (char* inp_flag){
    int i;
    int flag_len = my_strlen(inp_flag);
    char *flag_t = "-t";
    int isFlagT = 1;
        for (i = 0; i < flag_len; i++) {
            if (flag_t[i] != inp_flag[i]) {
                return isFlagT = 0;
            } // Closes if, not a "t"
        } // Closes for
    return isFlagT;
} // Closes isFlagT

char checkSecret(char* inp_secret, int secret_len) {
    int isInpSecrValid = 1;
    // Check input secret is valid, and paste into secret array
    // inp_secret is the input string after -c flag
    for (int i = 0; i < secret_len; i++) {
        if (inp_secret[i] < 48 || inp_secret[i] > 55) {
            printf("Wrong input! \n");
            return isInpSecrValid = 0;
        } // Closes if not ascii 0 - 9
    } // Closes for length of secret
    return isInpSecrValid;
} // Closes function


// pass in the pointer to secrArr to first char
char makeSecretArr(char* inp_secret, int secret_len, char* secrArr) {
    int i;
    // int secret_len = my_strlen(inp_secret);
    printf("66strlen: %d\n", secret_len);
    printf("64inpsec: %s\n", inp_secret);
    printf("65: %d\n", checkSecret(inp_secret, secret_len) == 1);
    if (checkSecret(inp_secret, secret_len) == 1) {
        for (i = 0; i < secret_len; i++) {
            secrArr[i] = inp_secret[i];
            printf("68: %c\n", secrArr[i]);
        } // Closes for
    }
    //   else // if inp_secret is not valid
    //   {
    //      printf("run ranSecret"); 
    //      // pass the pointer itself
    //     ranSecret(4, secrArr);
    //     printf("127ranSecr: %s\n", secrArr);
    //     }
     // Closes if checkSecret valid
    // if checkSecret not valid, return 0
    printf("74: %s\n", secrArr);
    return *secrArr;
} // Closes function

char makeMaxTries(char* inp_tries) {
    return atoi(inp_tries);
} // Closes function


void fill_array(int* array, char* str) {
    int index;
    // printf("CURRENT STRING: %s\n", str);
    for (index = 0; str[index] != '\0'; index++) {
        // if (array[(int)str[index]] != '"') 
        // {
        array[(int)str[index]] += 1;
        // printf("%c <=> %d\n", str[index], array[(int)str[index]]);
        // printf("ascii: %d\n", str[index]);
        // } // Closes if
    } // Closes for
} // Closes function

void print_array(int* array, int size_array) {
    int index;
    for (index = 0; index < size_array; index++){
        // bypass garbage characters
        // printf("index: %d\n", index);
        if (array[index] > 0) {
            // printf("%c:%d\n", index, array[index]);
        } // Closes if
    } // Closes for
} // Closes function

// Exact matches
int compareForX(char* secrArr, char* guess, int secret_len) {
    X = 0;
    for (i = 0; i < secret_len; i++) {
        if (secrArr[i] == guess[i]) {
            X++;
            // printf("ind: %d, X: %d\n", i, X);
        } // Closes if
    } // Closes for
    return X;
} // Closes function

// Right number, wrong place matches
int compareForZ(int* secr_elem_count_arr, int* guess_elem_count_arr) {
    Z = 0;
    for (i = 48; i < 56; i++) {
        // printf("i: %d %c\n", i, i);
        // printf("secrArr[i]: %c\n", secrArr[i]);
        // printf("142secElAr[i] %d\n", secr_elem_count_arr[i]);
        // printf("143guessElAr[i] %d\n", guess_elem_count_arr[i]);

        if (secr_elem_count_arr[i] > 0 && guess_elem_count_arr[i] > 0) {
            if (secr_elem_count_arr[i] <= guess_elem_count_arr[i]) {
                Z += secr_elem_count_arr[i];
                // printf("144 Z: %d\n", Z);
            } // Closes if secr count < guess count
            else {
                // printf("147 Z: %d\n", Z);
                Z += guess_elem_count_arr[i];
                // printf("149 Z: %d\n", Z);
            } // Closes else
        } // Closes if not = 0
    } // Closes for
    return Z;
} // Closes function

int main(int ac, char** av) {
    if (ac >= 3) {
        // printf("59: %d\n", ac);

        for (int av_ind = 1; av_ind <= ac-2; av_ind+=2) {
            // Is av[1] a "-c" or "-t"
            // If flag is a c for av[1] or av[3]
            // printf("70 isflagC: %d\n", isFlagC(av[av_ind]));
            if (isFlagC(av[av_ind]) == 1) {
                secret_len = my_strlen(av[av_ind+1]);
                makeSecretArr(av[av_ind+1], secret_len, secrArr);
                // printf("98 %s\n", secrArr);
            } // Closes if it's "-c"
            // else {
            //     // printf("125 ranSecret");
            //     printf("I'll generate a secret of length 4 %c\n", ranSecret(4, *secrArr));
            //     } // Closes if no -c flag
            // printf("90 isflagT: %d\n", isFlagT(av[av_ind]));
            if (isFlagT(av[av_ind]) == 1) {
                max_Tries = makeMaxTries(av[av_ind+1]);
                printf("177 maxTries: %d\n", max_Tries);
            } // Closes if it's "-t"
            printf("179 maxTries: %d\n", max_Tries);
        } // For ac = 3 or 5 

    } // If ac > 3
    else {
        secret_len = 4;
        printf("I'll generate a secret of length 4 \n");
        printf("%s\n", ranSecret(secret_len, secrArr));

    } // Closes if no -c

// Input
    printf("sec_len: %d\n", secret_len);
    printf("192 maxTries: %d\n", max_Tries);
    printf("secrArr: %s\n", secrArr);
    printf("Input section \n");
    printf("Will you find the secret code?\nPlease enter a valid guess of length %d, numbers 0 - 7\n", secret_len);
    round_num = 0;
        // printf("Round: %d\n", round_num);
    while (round_num < max_Tries) {
    printf("---\n");
    printf("Round %d\n", round_num);
        char* buffer = (char *)(calloc(secret_len, sizeof(char)));
        char inp_guess = read(0, buffer, 10);
        printf("guess: %s\n", buffer);
        // for (int i = 0; i < 10; i++) {
        //     printf("i: %d\n", i);
        //     printf("buffer[i]: %c\n", buffer[i]);
        // }
        printf("guess: %c\n", inp_guess);

        // is guess right length?
        int guess_len = my_strlen(buffer)-1;
        printf("guess_len: %d\n", guess_len);

        // is guess valid characters?
        if (guess_len != secret_len) {
            printf("Wrong number of inputs\n");
        }

    
        // Validate; are they all numbers; right length?
        if (checkSecret(buffer, guess_len) == 1) {
            printf("Right kind of input\n");
        }
        // COMPARE()
        // Input the secrArr and guessArr
            printf("182 \n");
            fill_array(secr_elem_count_arr, secrArr);
            print_array(secr_elem_count_arr, MAX_SECRET_SIZE);
            fill_array(guess_elem_count_arr, buffer);
            print_array(guess_elem_count_arr, MAX_SECRET_SIZE);
            printf("X: %d\n", compareForX(secrArr, buffer, secret_len)); 
            printf("Z: %d\n", compareForZ(&secr_elem_count_arr[0], &guess_elem_count_arr[0])); 
            Y = Z - X;
            // printf("Y: %d\n", Y);
            printf("Well placed pieces: %d\n", X);
            printf("Misplaced pieces: %d\n", Y);

        round_num++;
    } // Closes tries



// game loop
// until end of file






    return 0;
} // Closes main



//  ./my_mastermind -c "0123" -t "4"

// input validation vs. basic loop of game
// allocate space for new string or array; fill with input



// if (secr_elem_count_arr[i] > 0 && guess_elem_count_arr[(int)secrArr[i]] > 0) {
//             if (secr_elem_count_arr[(int)secrArr[i]] <= guess_elem_count_arr[(int)secrArr[i]]) {
//                 Z += secr_elem_count_arr[(int)secrArr[i]];
//                 printf("144 Z: %d\n", Z);
//             } // Closes if secr count < guess count
//             else {
//                 printf("147 Z: %d\n", Z);
//                 Z += guess_elem_count_arr[(int)secrArr[i]];
//                 printf("149 Z: %d\n", Z);
//             } // Closes else
//         } // Closes if not = 0