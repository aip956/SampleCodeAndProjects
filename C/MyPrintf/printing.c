#include <stdio.h>
#include "my_printf.h"

void my_putchar(char c) {
    putchar(c);
}

void my_puts(const char *s) {
    while(*s) {
        my_putchar(*s);
        s++;
    }
}


// All int cases except pointer
int my_print_integer(int value, int base) {
    char buffer[20];
    int i = 0;
    int count = 0;
    if (value < 0) {
        my_putchar('-');
        value = -value;
        count++;
    }
    do {
        buffer[i++] = "0123456789ABCDEF"[value % base];
        value /= base;
    } while (value);
    
    while (i > 0) {
        my_putchar(buffer[--i]);
        count++;
    }
    buffer[i++] = 'x';
    buffer[i++] = '0';
    buffer[i] = '\0';
    return count;
}

// use this for Pointer
int my_print_integer_pointer(unsigned long value) {
    my_puts("0x");
    int leading_zero = 1;
    int count = 2;
    int index = 0;
    char *hex_str = (char *)malloc(sizeof(char) * 17);
    if (hex_str == NULL) {
        return 0;
    }
    for (int j = 15; j >= 0; j--) {
        unsigned char digit =(value >> (j * 4)) & 0xF;
        if (digit !=0 || !leading_zero) {
            hex_str[index++] = "0123456789abcdef"[digit];
            count++;
            leading_zero = 0;
        }
    } 
    hex_str[index] = '\0';
    my_puts(hex_str);
    free(hex_str);
    return count;
}