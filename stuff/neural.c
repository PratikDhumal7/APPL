#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Neuron{
    double input;
    double output;
    double bias;

    // derivates 
};

int add_bias(struct Neuron* layer1[]){

    int size = sizeof(layer1)/sizeof(layer1[0]);

    for(int i = 0; i < size; i++){
      layer1[i].input = layer1[i].input + layer[i].bias;
    }
    return 0;
}

int activationFunction(struct Neuron* layer1[]){

  int size = sizeof(layer1)/sizeof(layer1[0]);

  for(int i=0;i<size;i++){
    layer1[i].output = sigmoid(layer1[i].input);
  }
}

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
