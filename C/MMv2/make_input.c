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
 }; // Closes function

 char* ranSecret(int secret_len, char* secret) {
    // printf("I'm generating a random secret \n");
    // printf("13strlen: %d\n", secret_len);
    char ranNum;
    int i;
    srand(time(NULL));
    for (i = 0; i < secret_len; i++) {
        ranNum =  (48 + (rand() % 8));
        // printf("%d %c\n", i, ranNum);
        secret[i] = ranNum;
    } // Closes for int i
    secret[i] = '\0';
    // printf("19: %s\n", secret);
    return secret;
} // Closes function

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
}; // Closes function


// will output char secret
char make_secret (char* av){
    int i, av_index, count, secret_len;
    int av_len = my_strlen(av);
    char *flag_c = "-c";
    int isFlagC = 0;
    char *secret;
    for (av_index = 1; av_index < av_len; av_index++) {
        // for each flag in av
        char* flag = av[av_index];
        int flag_len = my_strlen(av[av_index]);
        for (i = 0; i < flag_len; i++) {
            if (flag_c[i] == flag[i]) {
                count ++;
                if (count == 2) { // found -c
                    secret = av[av_index+1];
                    isFlagC = 1;
                    secret_len = my_strlen(secret);
                    if (is_code_valid(*secret, secret_len) == 0) {
                            secret = NULL;
                        };
                } // Closes if -c
            } // closes search on av element
            if (isFlagC = 0) {
                create_secret(secret_len, secret);
            };
        }; // closes for av_index
    }; // closes for av
    return secret;
}; // Closes make_secret

int make_max_tries (char* av){
 int i, av_index, count, tries_len;
    int av_len = my_strlen(av);
    char *flag_t = "-t";
    int isFlagT = 0;
    char *tries;
    for (av_index = 1; av_index < av_len; av_index++) {
        // for each flag in av
        char* flag = av[av_index];
        int flag_len = my_strlen(av[av_index]);
        for (i = 0; i < flag_len; i++) {
            if (flag_t[i] == flag[i]) {
                count ++;
                if (count == 2) { // found -t
                    tries = av[av_index+1];
                    return atoi(tries);
                } // Closes if -t
            } // closes search on av element
        }; // closes for av_index
    return tries;
    };
};


char make_secret_and_tries(char* av) {
    // if length of av > 1
    // if there's a C flag and it's valid
    // index of C plus one is secret
    // index of T plus one is tries
    


        int secret_length = my_strlen(*av);
        secret_and_tries = {
            .length = secret_length,
            .secret = make_secret(*av);
            .tries = make_max_tries(*av),
        };

    
};