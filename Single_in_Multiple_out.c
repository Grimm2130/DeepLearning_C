#include "Single_in_Multiple_out.h"
#include <stdlib.h>

double* multiple_output(double input, double* weights, int weight_len){
    double* outputs = calloc(weight_len, sizeof(double));
    for(int i = 0; i < weight_len; i++){
        outputs[i] = input*weights[i];
    }   
    return outputs;
}