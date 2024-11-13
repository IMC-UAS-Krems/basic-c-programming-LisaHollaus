#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>




int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;
    
    // 1
    // When the program is called with a number of arguments different from 2, the code will output the following text to the standard output:
    if (argc != 3) {  // 3 = 2 arguments
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 1; // stop the program
    }


    // 2
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    // check if all arguments passed are integers greater than 0.
    if (rows < 0 || cols < 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return 1; // stop the program
    };


    // 3
    // create a dynamically allocated matrix of integers using the dimensions passed as parameters. 
    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *)); // pointer to an array of row pointers
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int)); 
    };

    // nested for loop to assign random integers 
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          matrix[i][j] = minrand + rand() % (maxrand - minrand + 1); 
        };
    };


    // 4 
    // create a file containing the generated matrix 
    FILE *pFile = NULL; // empty file
    pFile = fopen("matrix.txt", "w"); // Opening the file in writing mode
    
    // writting into the File with a nested for loop
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           fprintf(pFile, "%d", matrix[i][j]); 
           if (j + 1 != cols) {
            fprintf(pFile, " "); // whitespace separator between each entry
           } 
           else {
            fprintf(pFile, "\n"); // one row on each line and no whitespace at the end of each line
           }
        };
    };

    //  The last row ends with a carriage return
    //fprintf(pFile, "\r");

    fclose(pFile); 


    // Free the dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // free each row
    }
    free(matrix); // free pointer array

    return 0;
}


