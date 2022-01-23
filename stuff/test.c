#include <stdlib.h>
#include <stdio.h>
#include "lib_csv.h"

int main()
{
    struct Matrix* mat1 = read_csv("/home/pratik/Documents/work/TY-MINIPROJECT/Datasets/PanelData.csv");

    printf("Matrix 1- \n");
    mat_reshape(mat1,91,6);
    // mat_display(mat1);
    //
    int rows = mat1->r_size;
    int columns = mat1->c_size; // features = col - 1
    int nodesInHiddenLayer = (rows-1)/(3*((columns-1) + 1)); //alpha = scaling factor between 2-10;
    double cost = 0;
    //
    struct Matrix* inputDataMat = mat_initEmpty();
    inputDataMat->r_size = rows-1;
    inputDataMat->c_size = columns-1;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns-1; j++){

          inputDataMat->data[i*(columns-1)+j] = mat1->data[i*(columns-1)+j];

        }
    }
    // mat_display(inputDataMat);


    struct Matrix* expectedOutput = mat_initEmpty();

    expectedOutput->r_size = rows-1;
    expectedOutput->c_size = 1;

    for(int i = 1; i < rows; i++){

          expectedOutput->data[i] = mat1->data[i];

    }
    // mat_display(expectedOutput);
    struct Matrix* weights_I_1 = mat_initEmpty(); // No_of_nodes x columns  Matrix for input to 1st hidden layer

    weights_I_1->r_size = nodesInHiddenLayer;
    weights_I_1->c_size = columns-1;

    // check weights initialization range 


    for(int i = 0; i < weights_I_1->r_size; i++){
        for(int j = 0; j < weights_I_1->c_size; j++){

          weights_I_1->data[i][j] = (double)rand())/((double)RAND_MAX);;

        }
    }

    struct Neuron* layer1[nodesInHiddenLayer];

    // check bias initialization range

    for(int i = 0; i < nodesInHiddenLayer; i++){

          nodesInHiddenLayer[i].bias = (double)rand())/((double)RAND_MAX);;

    }

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
    return 0;
}
