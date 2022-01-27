#include <stdio.h>
#include <stdlib.h>
#include "lib_csv.h"


double nn_relu(double inputVal){
  if(inputVal > 0) return 0.01*inputVal;
  else return 0;
}


void nn_activation(struct Matrix* mat){
    for(int i = 0; i < mat_getSize(mat); i++){
        mat->data[i] = nn_relu(mat->data[i]);
    }
}


int nn_addBias(struct Matrix* mat1, struct Matrix* bias){
    int size1 = mat_getSize(mat1), size2 = mat_getSize(bias);
    for(int i = 0, j = 0; i < mat_getSize(mat1); i++, j++){
        if(j >= size2) j = 0;
        mat1->data[i] += bias->data[j];
    }
}


struct Matrix* nn_forwardPropogate(struct Matrix* input, struct Matrix** weights, struct Matrix** biases, int layers){
    struct Matrix* output, *old_output;
    if(mat_product(input, weights[0], &output) != 0){
        return NULL;
    }
    nn_addBias(output, biases[0]);
    nn_activation(output);
    //mat_display(output);
    old_output = output;
    for(int i = 1; i < layers-1; i++){
        if(mat_product(output, weights[i], &output) != 0){
            return NULL;
        }
        nn_addBias(output, biases[i]);
        nn_activation(output);
        mat_del(old_output);
        old_output = output;
        //printf("Layer %d:", i);
        //mat_display(output);
    }
    return output;
}

/*
double sigmoid(double inputVal){
  return 1 / (1 + exp(-inputVal));
}

double sigmoidDerivative(double inputVal){
  return inputVal * (1 — inputVal);
}

double costFunc(struct Neuron* layer[],struct Matrix* expectedOutput,int rows){

  int size = sizeof(layer1)/sizeof(layer1[0]);
  double cost = 0;

  for(int i=0;i<size;i++){
    cost = cost + 0.5((expectedOutput->data[i] - layer[i].output)*(expectedOutput->data[i] - layer[i].output));
  }

  return cost/rows;

}

struct Matrix* forward_propogate(struct Matrix* input, struct Matrix** weights, struct Matrix** biases, int layers){
    struct Matrix* output, *old_output;
    if(mat_product(input, weights[0], output) != 0){
        return NULL;
    }
    old_output = output;
    for(int i = 1; i < layers; i++){
        if(mat_product(output, weights[i], output) != 0){
            return NULL;
        }
        mat_del(old_output);
        old_output = output;
    }
}
*/
