#ifndef MUSCLE_GAIN_H
#define MUSCLE_GAIN_H

#include "Helpers.h"

/*======= MATRIX DIMENSION MACROS ========*/
#define     NUM_OF_EXAMPLES         3
#define     NUM_OF_FEATURES         2
#define     NUM_OF_HIDDEN_NODES     3
#define     NUM_OF_OUTPUT_NODES     1



/*======== Normalization Functions =========*/
double*  normalizeData_1D(double* input, long input_len);
double** normalizeData_2D(double** input, long input_row_len, long input_col_len);

/*======= Random Weight initialization ===========*/
double* init_random_weight_1D(long len);
double** init_random_weight_2D(long row_len, long col_len);

/*======= Matrix Operational Functions ===========*/
double* matrixMult_1D_to_1D(double* vector_1, double* vector_2, long len_1, long len_2);
double** matrixMult_2D_to_2D(double** mat_1, double** mat_2, long row_1, long row_2, long col_1, long col_2);

/*======= Activation Functions ===========*/
double apply_sigmoid(double val);

/*====== Forward Propagation  Function ========*/
void forward_Propagation();

#endif