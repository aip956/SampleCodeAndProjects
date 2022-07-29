/*
go through arguments
fill array with occurrences
print the array
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_ARRAY_SIZE 128


void fill_array(int* array, char* str) {
    int index;
    printf("CURRENT STRING: %s\n", str);
    for (index = 0; str[index] != '\0'; index++) {
        if (array[(int)str[index]] != '"') { 
            // str = input string
            // str[index] = element of input string; char or ascii int
            // array[(int)str[index]] is the count of the character
        array[(int)str[index]] += 1;
        } // Closes if
    } // Closes for
} // Closes function

void print_array(int* array, int size_array) {
    int index;
    for (index = 0; index < size_array; index++){
        // bypass garbage characters
        if (array[index] > 0) {
            printf("%c:%d\n", index, array[index]);
            // ^ prints the char and count
        } // Closes if
    } // Closes for
} // Closes function


int main(int ac, char **av) {
    int index;
    int array[MAX_ARRAY_SIZE] = {0};
    for (index = 1; index < ac; index++){
        fill_array(&array[0], av[index]);
        // av[index] is the string input
    }; // Closes for
    print_array(&array[0], MAX_ARRAY_SIZE);
    return 0;
}


