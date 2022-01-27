#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib_matrix.h"

#define BUFFER_SIZE 2048

struct Matrix* read_csv(char* path){
    FILE* fptr;
    char line[BUFFER_SIZE];
    double a = 0;
    struct Matrix * mat = mat_initEmpty(0, 0);
    fptr = fopen(path, "r");
    if(fptr == NULL){
	    return NULL;
    }
	long rows = 0, size = 0;

    while(fgets(line, BUFFER_SIZE, fptr)){
        line[strlen(line)-1] = '\0';
        rows++;

	    char * vals = strtok(line, ",");
	    char * eptr;

	    while(vals != NULL){
            double a = strtod(vals, &eptr);
	        vals = strtok(NULL, ",");
	        mat_append(mat, 1, &a);
	        size++;
	    }
    }
    // mat_display(mat);
    mat_reshape(mat, rows, size/rows);
    return mat;
}
