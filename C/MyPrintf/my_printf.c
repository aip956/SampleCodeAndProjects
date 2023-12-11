#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "my_printf.h"
#include "printing.h"



int my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int total_chars_printed = 0;

    while (*format) {
        if (*format == '%') {
            format++;
            int chars_printed = 0;

            switch (*format) {
                // d and i
                case 'd' :
                case 'i' : {
                    int value = va_arg(args, int);
                    chars_printed = my_print_integer(value, 10);
                    break;
                }
                // String; checks size with strlen
                case 's' : {
                    char *str = va_arg(args, char *);
                    if (str != NULL) {
                        my_puts(str);
                        chars_printed += strlen(str);
                    } 
                    else {
                        my_puts("(null)");
                        chars_printed += 6;
                    }
                    break;
                }
                // Char
                case 'c' : {
                    char c = va_arg(args, int);
                    my_putchar(c);
                    chars_printed++;
                    break;
                }
                // Pointer
                case 'p' : {
                    void *ptr = va_arg(args, void *);
                    chars_printed = my_print_integer_pointer((unsigned long)ptr);
                    break;
                }
                // Octal
                case 'o' : {
                    unsigned int value = va_arg(args, unsigned int);
                    chars_printed = my_print_integer(value, 8);
                    break;
                }
                // Unsigned
                case 'u' : {
                    unsigned int value = va_arg(args, unsigned int);
                    chars_printed = my_print_integer(value, 10);
                    break;
                }
                // Hex
                case 'x' : {
                    unsigned int value = va_arg(args, unsigned int);
                    chars_printed = my_print_integer(value, 16);
                    break;
                }
                default:
                    my_putchar(*format);
                    chars_printed++;
                    break;
            }
            total_chars_printed += chars_printed; 
        } else {
            my_putchar(*format);
            total_chars_printed++;
        }
        format++;
    }
    va_end(args);
    // printf("108IndCount: %d\n", index_count);
    return total_chars_printed;
}
