#ifndef lib_matrix
#define lib_matrix
#endif

struct Matrix{
    int r_size;
    int c_size;
    double* data;
};

struct Matrix* mat_init(int, int, int, double *);

struct Matrix* mat_initEmpty(int, int);

struct Matrix* mat_initRandom(int, int, int);

void mat_del(struct Matrix*);

int mat_getSize(struct Matrix*);

int mat_add(struct Matrix*, struct Matrix*, struct Matrix*);

void mat_addScalar(struct Matrix*, double);

int mat_product(struct Matrix*, struct Matrix*, struct Matrix**);

void mat_append(struct Matrix*, int, double*);

void mat_reshape(struct Matrix*, int, int);

void mat_display(struct Matrix*);
