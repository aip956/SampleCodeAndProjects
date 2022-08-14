#ifndef MY_HEADER
#define MY_HEADER 
#define MAX_SECRET_SIZE 128
// If MyHeader is defined, if not define here
int max_Tries;
// char secrArr[MAX_SECRET_SIZE] = {0};
int secret_len;
// int secr_elem_count_arr[MAX_SECRET_SIZE] = {0};
int i, X, Y, Z, round_num;


char* ranSecret(int, char*);
int my_strlen(char*);
int isFlagC (char*);
int isFlagT (char*);
char checkSecret(char*, int);
char makeSecretArr(char*, int, char*);
char makeMaxTries(char*);
void fill_array(int*, char*);
void print_array(int*, int);
int compareForX(char*, char*, int);
int compareForZ(int*, int*);

// void main();


#endif