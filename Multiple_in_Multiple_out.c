#include "Multiple_in_Multiple_out.h"

void mult_in_mult_out(double inputs[LEN], double weights[LEN][LEN], double outputs[LEN],
                    int input_len, int weight_row_len, int weight_col_len, int output_len){
    // Loop through the rows
    for(int i = 0; i < input_len && i < weight_row_len; i++){
        // Loop through the columns
        for(int j = 0; j < weight_col_len; j++){
            // Calculate the outputs
            outputs[i] += inputs[j]*weights[i][j];
        }
    }
}