#include "Multiple_in_Single_out.h"

double mult_in_single_out(double* inputs, double* weights, int input_len, int weight_len){
    double output = 0.0;
    for(int i = 0; i < input_len && i < weight_len; i++){
        output += inputs[i]*weights[i];
    }
    return output;
}