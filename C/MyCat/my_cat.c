#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int main(int ac, char **av) {
    char fname[20];
    FILE *fp;
    int numfiles = ac - 1;
    int c;

// Check if at least one file input
if (ac < 2) {
    return 0;
} // Closes if

// Print for each file
for (int i = 1; i <= numfiles; i++) {
    // Open the file
    fp = fopen(av[i], "r");

    if(fp == NULL) {
        printf("Error");
    }
    // Read the file
    else {
    while ((c = getc(fp)) != EOF)
    putchar(c);
    fclose(fp);
    } // closes else
    
    } // Closes for each file
return 0;
}
