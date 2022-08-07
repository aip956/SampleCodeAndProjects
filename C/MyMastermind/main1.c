#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "ranSecret.h"
#define MAX_SECRET_SIZE 128
#include <time.h>

int max_Tries;
int secrArr[MAX_SECRET_SIZE];
int secret_len;


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
        if (inp_secret[i] < 48 || inp_secret[i] > 57) {
            printf("Wrong input! \n");
            return isInpSecrValid = 0;
        } // Closes if not ascii 0 - 9
    } // Closes for length of secret
    return isInpSecrValid;
} // Closes function

char makeSecretArr(char* inp_secret, int secret_len) {
    int secrArr[MAX_SECRET_SIZE]={};
    // int secret_len = my_strlen(inp_secret);
    printf("strlen: %d\n", secret_len);
    printf("64inpsec: %s\n", inp_secret);
    printf("65: %d\n", checkSecret(inp_secret, secret_len) == 1);
    if (checkSecret(inp_secret, secret_len) == 1) {
        for (int i = 0; i < secret_len; i++) {
            secrArr[i] = atoi(&inp_secret[i]);
            printf("68: %d\n", secrArr[i]);
        } // Closes for
    } // Closes if checkSecret valid
    // if checkSecret not valid, return 0
        else {
            return 0;
        }
    printf("74: %d\n", *secrArr);
    return *secrArr;
} // Closes function

int ranSecret(secret_len) {
    srand(time(NULL));
    for (int i = 0; i < secret_len; i++) {
         secrArr[i] = (rand() % 8);
         printf("84 %d\n", secrArr[i]);
        // printf("%s\n", &secret[0]);
        // printf("%d\n", secret[i]);
    } // Closes for int i
    printf("85 %d\n", *secrArr);
     printf("87 %d\n", secrArr[1]);
      printf("88 %d\n", secrArr[2]);
    return *secrArr;
} // Closes function

char makeMaxTries(char* inp_tries) {
    return atoi(inp_tries);
} // Closes function

int main(int ac, char** av) {

    // printf("Input qty: %d\n", ac);
    // printf("%s\n", av[2]);

// if ac < 3, or no -c flag, or invalid code, generate a code
// randomSecret, length of secret default 4
// isFlagC != 1

        // test for ac3 / flag1, is it a c or t

    if (ac >= 3) {
        printf("59: %d\n", ac);
        for (int av_ind = 1; av_ind <= ac-2; av_ind+=2) {
            // Is av[1] a "-c" or "-t"
            // If flag is a c for av[1] or av[3]
            printf("70 isflagC: %d\n", isFlagC(av[av_ind]));
            if (isFlagC(av[av_ind]) == 1) {

                secret_len = my_strlen(av[av_ind+1]);
                int secrArr = makeSecretArr(av[av_ind+1], secret_len);
                // printf("97 %d\n", makeSecretArr(av[av_ind+1]));

                printf("98 %d\n", secrArr);
            } // Closes if it's "-c"
                // else {
                    int secrArr = ranSecret(secret_len);
                    printf("121ranSecr: %d\n", secrArr);
                // }
            printf("90 isflagT: %d\n", isFlagT(av[av_ind]));
            if (isFlagT(av[av_ind]) == 1) {
                int max_Tries = makeMaxTries(av[av_ind+1]);
                printf("maxTries: %d\n", max_Tries);
            } // Closes if it's "-t"

        } // For ac = 3 or 5 
    } // If ac > 3

    // else {
        // printf("131 %d\n", ranSecret());
    // }



        // for (int i = 0; i < secret_len; i++) {
        //     if (av[2][i] >= 48 && av[2][i] <= 57) {
        //         // printf("ascii: %d\n", av[2][i]);
        //     secret[i] = av[2][i];
        //     } // Closes if ascii 0 - 9
        //     else {
        //         return printf("Wrong input! \n");
        //     }
        // } // Closes for length of secret
    // printf("92 Secret: %s\n", secret);
    // } // Closes if my_strcmp

return 0;
}




//  ./my_mastermind -c "0123" -t "4"