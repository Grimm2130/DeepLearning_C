#include "MuscleGain.h"


/************************************************************************/
/*========================= Function Declarations ======================*/
/************************************************************************/


/**
 * @brief Function to Normalize an array of doubles
 * 
 * @param input         :   1D array of inputs
 * @param input_len     :   Length of 1D array
 */
void normalizeData_1D(double* input, long input_len){
    // Find the max value
    double max = FLT_MIN;
    for(int i = 1; i < input_len; i++){
        max = max < input[i] ? input[i] : max;
    }
    // Compute the normalized data
    for(int i = 0; i < input_len; i++){
        input[i] /= max;
    }
}

/**
 * @brief                   :       Function to Normalize a 2D array of doubles
 * 
 * @param input             :       2D input array
 * @param input_col_len     :       Number of examples per feature
 * @param input_row_len     :       Number of Features
 */
void normalizeData_2D(double** input, long input_col_len, long input_row_len){
    double max = FLT_MIN;
    // Find the max value of input array
    for(long i = 0; i < input_row_len; i++){
        for(int j = 0; j < input_col_len; j++){
            if(max < input[i][j]){
                max = input[i][j];
            }
        }
    }
    // Normalize with the max value and assign to the normalized array
    for(long i = 0; i < input_row_len; i++){
        for(int j = 0; j < input_col_len; j++){
            input[i][j] /= max;
        }
    }
}

/**
 * @brief               Function to initialize random weights for a 1D array.
 *                      
 *                      * Matrix Should be flattened before being passed into this
 *                          fuction
 * 
 * @param weights       1D array
 * @param len           Lenght of array
 */
void init_random_weight_1D(double* weights, long len){
    // Initialize random generator
    srand(44);
    for(long i = 0; i < len; i++){
        weights[i] = (rand()%10)/1000;
    }
}


/**
 * @brief               Function to initialize random weights for a 2D Array
 * 
 * @param weights       2D array 
 * @param row_len       Number of rows
 * @param col_len       Number of cols
 */
void init_random_weight_2D(double** weights, long row_len, long col_len){
    // Initialize random generator
    srand(44);
    for(long i = 0; i < row_len; i++){
        for(long j = 0; j < col_len; j++){
            // Set random weights
            weights[i][j] = (rand()%10)/1000;
        }
    }
}

/**
 * @brief               Function to perform 1D vector multiplication
 * 
 * @param vector_1      input vector 1
 * @param vector_2      input vector 2
 * @param len_1         length 1
 * @param len_2         Length 2
 * @return double*      Result of vector multiplication
 */
double* matrixMult_1D_to_1D(double* vector_1, double* vector_2, long len_1, long len_2){
    if(len_1 != len_2){
        printf("Vector Sizes not equal\n");
    }
    double* res = calloc(len_1, sizeof(*res));
    // Perform vector multiplication
    for(long i = 0; i < len_1; i++){
        res[i] = vector_1[i] * vector_2[i];
    }
    // return result
    return res;
}

/**
 * @brief               Function to perform 2D matrix Multiplication
 * 
 * 
 * @param mat_1         2D matrix 1
 * @param mat_2         2D matrix 2
 * @param row_1         Row Len for 2D matrix 1
 * @param row_2         Row Len for 2D matrix 2
 * @param col_1         Col Len for 2D matrix 1
 * @param col_2         Col Len for 2D matrix 2
 * @return double**     Returning matrix for matrix multiplication
 */
double** matrixMult_2D_to_2D(double** mat_1, double** mat_2, long row_1, long row_2, long col_1, long col_2){
    // Check if the matrix's are compatible
    if(col_1 != row_2){
        printf("Matrices are not compatible!\n");
        return (double**)NULL;
    }
    // define the result matrix
    // initialize rows
    double **res = calloc(row_1, sizeof(*res));                         // rows == row_1
    // initialize columns for each row
    for(long i = 0; i < row_1; i++){
        res[i] = calloc(col_2, sizeof(*(res[i])));                      // Cols == col2
    }
    // Multiply the matrix
    for(long i = 0; i < row_1; i++){
        for(long j = 0; j < col_2; j++){
            for(long k = 0; k < row_2; k++){
                res[i][j] += mat_1[i][k]*mat_2[k][j];
            }
        }
    }
    return res;
}


/**
 * @brief               Function to apply a sigmoid
 * 
 * @param val           Value to be transformed
 * @return double       
 */
double apply_sigmoid(double val){
    return (double) (1/(1+exp(-val)));
}