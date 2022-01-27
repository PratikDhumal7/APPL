#ifndef lib_appl
#define lib_appl
#endif
#include "lib_csv.h"

double nn_relu(double inputVal);

void nn_activation(struct Matrix* mat);

int nn_addBias(struct Matrix* mat1, struct Matrix* bias);

struct Matrix* nn_forwardPropogate(struct Matrix* input, struct Matrix** weights, struct Matrix** biases, int layers);
