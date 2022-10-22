#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


int sumnum(int num, ...) {
    // num = number of integers
    printf("7num: %d\n", num);
    int sum = 0;
    va_list argptr;
    int count = 0;
    va_start(argptr, num);
    while (count < num) {
        // printf("14va_arg: %d\n", va_arg(argptr, int));
        sum += va_arg(argptr, int); // argptr, type int
        printf("15sum: %d\n", sum);
        count++;
    }
    va_end(argptr);
    return sum;
}

void printstr(int num, ...){
    int count = 0;
    char *ptr;
    va_list argptr;
    va_start(argptr, num);
    while(count < num) {
        ptr = va_arg(argptr, char*);
        printf("ptr = %s\n", ptr);

        count++;
    }
    va_end(argptr);

}

int main(int argc, char** argv) {
    // printf("argv: %s\n", argv[2]);
    int total;
    total = sumnum(5,  3, 5, 7, 6 ,4); // 5 integers 3,5,7,6,4 = 25
    // printf("argc: %d\n", argc); // argc is 1; filename
    printf("Total: %d\n", total);
    printstr(3, "one", "two", "three");
    char a[100] = "-1234";
    int b = atoi(a);
    printf("b: %d\n", b);
    printf("b: %p\n", b);

    return 0;
}