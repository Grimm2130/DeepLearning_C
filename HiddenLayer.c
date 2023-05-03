#include "HiddenLayer.h"

void input_to_hidden(double input[LEN], double hidden_weights[LEN][LEN], double hidden_layer[LEN], 
                int input_len, int weight_row_len, int weight_col_len, int hidden_len){
    
    for(int i = 0; i < hidden_len && i < weight_col_len; i++){
        for(int j = 0; (j < input_len) && (j < weight_row_len); j++){
            hidden_layer[i] += input[j]*hidden_weights[i][j];
        }
    }
}

void hidden_to_output(double hidden[LEN], double output_weights[LEN][LEN], double output_layer[LEN],
                    int hidden_len, int weight_row_len, int weight_col_len, int output_len){
    for(int i = 0; i < output_len && i < weight_col_len; i++){
        for(int j = 0; (j < hidden_len) && (j < weight_row_len); j++){
            output_layer[i] += hidden[j]*output_weights[i][j];
        }
    }
}