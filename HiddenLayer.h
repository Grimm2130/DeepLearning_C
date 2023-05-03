#ifndef HIDDEN_LAYER_H
#define HIDDEN_LAYER_H

#define LEN     3

void input_to_hidden(double input[LEN], double hidden_weights[LEN][LEN], double hidden_layer[LEN], 
                int input_len, int weight_row_len, int weight_col_len, int hidden_len);

void hidden_to_output(double hidden[LEN], double output_weights[LEN][LEN], double output_layer[LEN],
                    int hidden_len, int weight_row_len, int weight_col_len, int output_len);

#endif