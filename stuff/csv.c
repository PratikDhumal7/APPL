#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lib_matrix.h"

#define BUFFER_SIZE 2048

struct Matrix* read_csv(char* path){
    FILE* fptr;
    char line[BUFFER_SIZE];
    double a = 0;
    struct Matrix * mat = mat_initEmpty();
    fptr = fopen(path, "r");
    if(fptr == NULL){
	return NULL;
    }

    while(fgets(line, BUFFER_SIZE, fptr)){
        line[strlen(line)-1] = '\0';

	char * vals = strtok(line, ",");
	char * eptr;

	while(vals != NULL){
            double a = strtod(vals, &eptr);
	    vals = strtok(NULL, ",");
	    mat_append(mat, 1, &a);
	}
    }
    // mat_display(mat);
    return mat;
}
