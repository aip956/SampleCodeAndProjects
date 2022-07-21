#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct beautiful_square {
    int size;
    char **array;
} square;


square *my_Square(int cols, int rows) {
    square *result;
    int i, j;
    result = NULL;
        if ((result = (malloc(sizeof(square))))) {
        result->size = rows; 
        result->array = malloc(sizeof(char *) * rows);
        
        for (i = 0; i < rows; i++) {
            // last char is \0
            // i is each line/row
            // allocate memory
            result->array[i] = malloc(sizeof(char *) * cols);
            if (i == 0 || i == rows - 1) {
                // 1st and last rows
                for (j = 0; j < cols; j++) {
                    if (j == 0 || j == cols - 1) {
                        result->array[i][j] = 'o';
                    } // ends if j
                    else {result->array[i][j] = '-';
                    }; // ends else
                }; // ends for j
            } // ends if i
            else {
                for (j = 0; j < cols; j++) {
                    if (j == 0 || j == cols - 1) {
                        result->array[i][j] = '|';
                    } // ends if j
                    else {result->array[i][j] = ' ';}
                }; // ends for j
            }; // ends else i = 0
        result->array[i][cols] = '\0';
        } // ends for each row
    } // ends if malloc
    return result;
}

int main(int ac, char **av) {
    int i;
    square *mySquare; 
    if (ac != 3) {
        return 0;
    }
    int cols = atoi(av[1]);
    int rows = atoi(av[2]);
   
    if (rows == 0 || cols == 0) {
        return 0;
    }
    mySquare = my_Square(cols, rows);
        for (i = 0; i < rows; i++) {
            printf("%s\n", mySquare->array[i]);
        }
        for (i = 0; i < rows; i++) {
            free(mySquare->array[i]);
        }
        free(mySquare->array);
    free(mySquare);
return 0;
};