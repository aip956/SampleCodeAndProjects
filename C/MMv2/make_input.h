
#ifndef STRUCT_CHAR_STRUCT
#define STRUCT_CHAR_STRUCT

typedef struct s_char_array
{
    int length;
    int tries;
    char* secret;
} char_struct;
#endif


int my_strlen(char*);
char* ranSecret(int, char*);
char is_code_valid(char*, int);
char make_secret(char*);
int make_max_tries(char*);
char make_secret_and_tries(char*, char_struct*);
