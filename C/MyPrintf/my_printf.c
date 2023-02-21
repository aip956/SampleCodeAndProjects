#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

// 
void print_char(char* ch) {
// printf("%c\n", *ch);
write(1, ch, 10);
write(1, "\n", 1);
}

// void print_int(int ) {
// // printf("%c\n", *ch);
// write(1, ch, 10);
// write(1, "\n", 1);
// }


void my_pr(char* string, ...) {
    va_list args;
    int ind = 0, j = 0;
    char buffer[50] = {};
    char temp[50] = {};
    char* string_out;
    va_start(args, str);

    while (args[ind] != '\0') {
        printf("Form[ind]: %c\n", args[ind]);
        if (args[ind] == '%') {
            printf("%c\n", args[ind+1]);
            switch (args[i+1]) {
                case 'd': {
                    itoa(va_arg(args, int));
                }
            }
            
            print_int(va_arg("%d", va_arg(args, int)))

        }
        ind ++; 
    }
}

int main() {
    char c[100] = "%d\n";
    // char p = &c;
    int d = 5;

    // reg_printf(c);
    my_pr(d);

    // my_printf("%c\n", c);
    // my_printf("%p\n", *p);
    // my_printf("%d\n", d);
    // my_printf("%i\n", d); // 
    // my_printf("%o\n", d); // octal
    // my_printf("%u\n", d); // unsigned int
    // my_printf("%x\n", d); // hexadecimal
    // y_printf("%f\n", d); // float

    return 0;
}

// main has thing to print
// function to determine cases
// function for 