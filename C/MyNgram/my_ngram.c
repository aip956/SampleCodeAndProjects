/*
go through arguments
fill array with occurrences
print the array
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_ARRAY_SIZE 128

void fill_array(int* array, int size_array, char* str) {
    int index = 0;
    // printf("CURRENT STRING: %s\n", str);
    while (str[index] != '\0') {
        if (array[str[index]] != '"') {
        array[str[index]] += 1;
        // printf("%c <=> %d\n", str[index], array[index]);
        index += 1;
        } // Closes if
    } // Closes while
} // Closes function

void print_array(int* array, int size_array) {
    int index = 0;
    while (index < size_array) {
        // bypass garbage characters
        if (array[index] > 0) {
            printf("%c:%d\n", index, array[index]);
            } // Closes if
        index += 1;
    } // Closes while
} // Closes function


int main(int ac, char **av) {
    int index = 1;
    int array[MAX_ARRAY_SIZE] = {0};
    
    while (index < ac) {
        fill_array(&array[0], MAX_ARRAY_SIZE, av[index]);
        index += 1;
    }
    print_array(&array[0], MAX_ARRAY_SIZE);
    return EXIT_SUCCESS;
}

