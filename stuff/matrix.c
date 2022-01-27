#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Matrix{
    int r_size;
    int c_size;
    double* data;
};


struct Matrix* mat_init(int rows, int columns, int no_of_elems, double* elems){
    int i, j, k;
    struct Matrix* new_matrix = (struct Matrix*)malloc(sizeof(struct Matrix));

    new_matrix->r_size = rows;
    new_matrix->c_size = columns;
    new_matrix->data = (double*)calloc(rows*columns, sizeof(double));

    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){

            k = i*columns+ j;

            if(k >= no_of_elems){
                break;
            }
            new_matrix->data[k] = elems[k];
        }
    }

    return new_matrix;
}


struct Matrix* mat_initEmpty(int rows, int columns){
    int size = rows*columns;
    struct Matrix* new_matrix = (struct Matrix*)malloc(sizeof(struct Matrix));
    new_matrix->r_size = rows;
    new_matrix->c_size = columns;
    if(size > 0){  
        new_matrix->data = (double*)calloc(size, sizeof(double));
    } else {
        new_matrix->data = (double*)malloc(sizeof(double));
    }

    return new_matrix;
}


struct Matrix* mat_initRandom(int rows, int columns, int range){
    int size = rows*columns;
    struct Matrix* new_matrix = (struct Matrix*)malloc(sizeof(struct Matrix));
    new_matrix->r_size = rows;
    new_matrix->c_size = columns;
    new_matrix->data = (double*)calloc(size, sizeof(double));
    
    if(range == 0){
        for(int i = 0; i < size; i++){
            new_matrix->data[i] = (double)rand()/(double)RAND_MAX;
        }
    } else {
        for(int i = 0; i < size; i++){
            new_matrix->data[i] = rand()%range;
        }
    }
    return new_matrix;
}


void mat_del(struct Matrix* mat){
    free(mat->data);
    free(mat);
}


int mat_getSize(struct Matrix* mat){
    return mat->r_size * mat->c_size;
}


int mat_add(struct Matrix* mat1, struct Matrix* mat2, struct Matrix* mat3){
    int size1, size2, size3;

    if(mat3 == NULL) return 1;

    size1 = mat_getSize(mat1), size2 = mat_getSize(mat2), size3 = mat_getSize(mat3);

    if(size1 != size2 || size2 != size3) return 1;

    for(int i = 0; i < size1; i++){
        mat3->data[i] = mat1->data[i] + mat2->data[i];
    }
    return 0;
}


void mat_addScalar(struct Matrix* mat, double scalar){
    int size = mat->r_size * mat->c_size;
    for(int i = 0; i < size; i++){
        mat->data[i]+=scalar;
    }
}


int mat_dot(struct Matrix* mat1, struct Matrix* mat2, struct Matrix* res_mat){
    int size1, size2, size3;

    size1 = mat_getSize(mat1), size2 = mat_getSize(mat2), size3 = mat_getSize(res_mat);

    if(size1 != size2 || size1 != size3) return 2;

    for(int i = 0; i < size1; i++){
        res_mat->data[i] = mat1->data[i] * mat2->data[i];
    }
}

void mat_append(struct Matrix* mat, int no_of_elems, double* elem){
    int i, j, k, rows, columns;
    rows = mat->r_size;
    columns = mat->c_size;

    if(rows == 0 && columns == 0){
        mat->data[0] = elem[0];
        rows = mat->r_size = 1;
	    columns = mat->c_size = 1;
	    if(no_of_elems == 1) return;
    }

    rows += ceil((float)no_of_elems/columns);

    double* new_data = (double*)calloc(rows * columns, sizeof(double));

    for(i = 0; i < mat->r_size; i++){
        for(j = 0; j < columns; j++){
            new_data[i * columns + j] = mat->data[i * columns + j];
        }
    }

    k = 0;
    for(i = mat->r_size; i < rows; i++){
        for(j = 0; (j < columns && k < no_of_elems); j++){
            new_data[i * columns + j] = elem[k];
            k++;
        }
    }

    mat->r_size = rows;
    free(mat->data);
    mat->data = new_data;
}


void mat_reshape(struct Matrix* mat, int rows, int columns){
    int total = mat->r_size * mat->c_size, new_total = rows*columns;

    if(total != new_total) return;

    mat->r_size = rows;
    mat->c_size = columns;
}


void mat_display(struct Matrix* mat){
    int i, j;
    printf("\n");
    for(i = 0; i < mat->r_size; i++){
        for(j = 0; j < mat->c_size; j++){
            printf("%f  ", mat->data[i * mat->c_size + j]);
        }
        printf("\n");
    }
}
