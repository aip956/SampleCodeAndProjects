#include <stdio.h>
#include "my_printf.h"
#define INT_MAX 10


int main(void){
    int len __attribute__((unused));
    int len2 __attribute__((unused));
    unsigned int ui;
    void *addr; 

    len = my_printf("Let's try to print a simple sentence.\n");
    len2 = printf("Let's try to print a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void*)0x7ffe637541f0;

    my_printf("Length: [%d, %u]\n", len, len);
    printf("Length: [%d, %u]\n", len2, len2);

    my_printf("Negative: [%d]\n", -762534);
    printf("Negative: [%d]\n", -762534);

    my_printf("Unsigned: [%u]\n", ui);
    printf("Unsigned: [%u]\n", ui);

    my_printf("Unsigned octal: [%o]\n", ui);
    printf("Unsigned octal: [%o]\n", ui);

    my_printf("Unsigned hexadecimal: [%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal: [%x, %X]\n", ui, ui);

    my_printf("Character: [%c]\n", 'H');
    printf("Character: [%c]\n", 'H');

    my_printf("String: [%s]\n", "I am a string!");
    printf("String: [%s]\n", "I am a string!");

    my_printf("Address: [%p]\n", addr);
    printf("Address: [%p]\n", addr);

    len = printf("Percent: [%%]\n");
    len2 = printf("Percent: [%%]\n");

    return 0;
}