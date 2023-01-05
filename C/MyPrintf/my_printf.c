#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

// 
void reg_printf(char* ch) {
// printf("%c\n", *ch);
write(1, ch, 1);
write(1, "\n", 1);
}

int main() {
    char c[1] = "f";
    // char p = &c;
    int d = 5;

    reg_printf(c);

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