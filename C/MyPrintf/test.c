#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int count, ...) {
    va_list args;
    va_start(args, count);

    int sum = 0;
    int i;
    for (i = 0; i < count; i++) {
        // x is each element in args
        int x = va_arg(args, int);
        printf("13x:  %d\n", x);
        sum += x;
    }
    va_end(args);
    return sum;
}

int main (int argc, char*argv[]) {
    printf("Sum is: %d\n", sum(3, 1,2,3));
    return 0;
}
