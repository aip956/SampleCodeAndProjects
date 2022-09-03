#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>




int my_strlen(char* param_1) {
// a = param_1 // param_1 is my pointer; = a = Program
    int index = 0;
    int length = 0;
    for (index = 0; param_1[index] != '\0'; index++) {
        // printf("20 ind: %d\n", index);
        if (param_1[index] > 30) {
            // printf("ascii: %d\n", param_1[index]);
            length++;
            // printf("23 Ind/Len: %d\n", length);
        } // Closes if
    } // Closes for
    return length;
 } // Closes function

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

char is_code_valid(char* inp_secret, int secret_len) {
    int is_code_valid = 1;
    // Check input secret is valid, and paste into secret array
    // inp_secret is the input string after -c flag
    for (int i = 0; i < secret_len; i++) {
        if (inp_secret[i] < 48 || inp_secret[i] > 55) {
            printf("Wrong input! \n");
            return is_code_valid = 0;
        } // Closes if not ascii 0 - 9
    } // Closes for length of secret
    return is_code_valid;
} // Closes function

char make_secret_and_tries(char* av) {
    // if length of av > 1
    // if there's a C flag and it's valid
    // index of C plus one is secret
    // index of T plus one is tries
    if (isFlagC == 1 && is_code_valid == 1) {
        int secret_length = my_strlen(*av);
        secret_and_tries = {
            .length = secret_length,
            .secret = *av,
            .tries = *av,
        };
    }
    
};