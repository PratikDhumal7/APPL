#include <stdlib.h>
#include <stdio.h>
#include "lib_appl.h"


/*
double nn_relu(double inputVal){
  if(inputVal > 0) return 0.01*inputVal;
  else return 0;
}


void nn_activation(struct Matrix* mat){
    for(int i = 0; i < mat_getSize(mat); i++){
        mat->data[i] = nn_relu(mat->data[i]);
    }
}


void nn_addBias(struct Matrix* mat1, struct Matrix* bias){
    int rows = mat1->r_size, columns = mat1->c_size;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            mat1->data[i*columns+j] += bias->data[i];
        }
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
*/


int main()
{
    struct Matrix* mat1 = read_csv("/home/leorjj/APPL-main/Datasets/PanelData.csv");
    printf("Matrix 1- \n");
    mat_display(mat1);
    int rows = mat1->r_size;
    int columns = mat1->c_size; 
    int inputSize = columns-1;
    int layers;
    
    struct Matrix* inputMat = mat_initEmpty(rows-1, inputSize);

    for(int i = 1; i < rows; i++){
        for(int j = 0; j < columns-1; j++){
          inputMat->data[(i-1)*(inputSize)+j] = mat1->data[i*(columns)+j];
        }
    }
    printf("Input matrix- ");
    mat_display(inputMat);
    
    struct Matrix* expectedOutput = mat_initEmpty(rows-1, 1);

    
    for(int i = 1; i < rows; i++){
          expectedOutput->data[i-1] = mat1->data[i*columns + inputSize];
    }
    
    printf("\n\nExpected output- ");
    mat_display(expectedOutput);
    
    
    printf("\n\nEnter number of layers- ");
    scanf("%d", &layers);
    
    layers += 2; //adding output layer
    int* layerSize = (int*)calloc(layers, sizeof(int));
    layerSize[0] = inputSize;
    layerSize[layers-1] = 1;
    
    for(int i = 1; i < layers-1; i++){
        printf("Layer %d size: ", i);
        scanf("%d", &layerSize[i]);
    }
    
    
    struct Matrix** weights = (struct Matrix**)calloc(layers, sizeof(struct Matrix*));
    struct Matrix** biases = (struct Matrix**)calloc(layers, sizeof(struct Matrix*));
    for(int i = 0; i < layers-1; i++){
        weights[i] = mat_initRandom(layerSize[i], layerSize[i+1], 0);
        biases[i] = mat_initRandom(layerSize[i+1], 1, 10);
    }
    biases[layers-1] = mat_initRandom(1, 1, 10);
    
    //printf("Weights & biases- ");
    //for(int i = 0; i < layers-1; i++){
        //printf("Layer %d", i);
        //mat_display(weights[i]);
        //mat_display(biases[i]);
    //}
    
    struct Matrix* output = nn_forwardPropogate(inputMat, weights, biases, layers);
    printf("Output- ");
    mat_display(output);
    
    // check weights initialization range 
/*
    // check bias initialization range

    // struct Matrix* hiddenLayer1 = mat_initEmpty(); // No_of_nodes x 1
    // struct Matrix* temp = mat_initEmpty(); // No_of_nodes x 1

    // no_of_outputs = y
    struct Matrix* weights_1_2 = mat_initEmpty(); // y x No_of_nodes
    // struct Matrix* bias2 = mat_initEmpty(); // y * 1
    // struct Matrix* output = mat_initEmpty(); // y x 1
    // struct Matrix* cost = mat_initEmpty(); // y x 1

    struct Neuron* layer2[y];

    // Initialize random weight and bias values

    mat_dot(weights_I_1,inputDataMat,layer1);
    mat_add(layer1);
    activationFunction(Layer1);

    // temp = mat_initEmpty(); // y x 1
    mat_dot(weights_1_2,layer1.output,layer2);
    mat_add(layer2);
    activationFunction(layer2);

    cost = costFunc(layer2,expectedOutput,rows);

    // // BACK-PROPOGATION
    // //While loop based on cost value
    //
    // // get new prediction
    // // get cost
    // // calculate derivates and updating weights and biases
    //
    // mat_display(output);
    */
    return 0;
}
