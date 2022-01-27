#include <stdlib.h>
#include <stdio.h>
#include "lib_csv.h"

int main()
{
    struct Matrix* mat1 = read_csv("/home/leorjj/APPL-main/Datasets/PanelData.csv");
    printf("Matrix 1- \n");
    mat_display(mat1);
    int rows = mat1->r_size;
    int columns = mat1->c_size; 
    int inputSize = columns-1;
    int layers;
    printf("Enter number of layers- ");
    scanf("%d", &layers);
    int* layerSize = (int*)calloc(layers, sizeof(int));
    
    for(int i = 0; i < layers; i++){
        printf("Layer %d size: ", i);
        scanf("%d", &layerSize[i]);
    }
    
    double cost;
    
    struct Matrix* inputMat = mat_initEmpty(rows-1, inputSize);

    for(int i = 1; i < rows; i++){
        for(int j = 0; j < columns-1; j++){
          inputMat->data[(i-1)*(inputSize)+j] = mat1->data[i*(columns)+j];
        }
    }
    mat_display(inputMat);
    
    struct Matrix* expectedOutput = mat_initEmpty(rows-1, 1);

    
    for(int i = 1; i < rows; i++){
          expectedOutput->data[i-1] = mat1->data[i*columns + inputSize];
    }
    
    mat_display(expectedOutput);
    
    struct Matrix** weights = (struct Matrix**)calloc(layers, sizeof(struct Matrix*));
    for(int i = 0; i < layers+1; i++){
        weights[i] = mat_initRandom(layerSize[i], 1, 0);
    }
    
    for(int i = 0; i < layers+1; i++){
        mat_display(weights[i]);
    }
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
