#ifndef MULTIPLE_IN_MULTIPLE_OUT_H
#define MULTIPLE_IN_MULTIPLE_OUT_H

#define LEN     3

void mult_in_mult_out(double inputs[LEN], double weights[LEN][LEN], double outputs[LEN],
                    int input_len, int weight_row_len, int weight_col_len, int output_len);

#endif