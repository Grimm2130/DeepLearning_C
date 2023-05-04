#include "MuscleGain.h"

#define         INPUT_TRAIN_ROW         2
#define         INPUT_SAMPLE_SIZE       1

/*========== Global Variable Declarations ==========*/

// Input matrix
static double input_mat[NUM_OF_EXAMPLES][NUM_OF_FEATURES] = {   {2,8},
                                                                {5,5},
                                                                {1,8}   };

// Output matrix
static double output_vec[NUM_OF_EXAMPLES][NUM_OF_OUTPUT_NODES] = {  {200},
                                                                    {90},
                                                                    {190}   };

/************************************************************************/
/*========================= Function Declarations ======================*/
/************************************************************************/


/**
 * @brief Function to Normalize an array of doubles
 * 
 * @param input         :   1D array of inputs
 * @param input_len     :   Length of 1D array
 */
double* normalizeData_1D(double* input, long input_len){
    // Find the max value
    double max = FLT_MIN;
    for(int i = 1; i < input_len; i++){
        max = max < input[i] ? input[i] : max;
    }
    // Compute the normalized data
    for(int i = 0; i < input_len; i++){
        input[i] /= max;
    }
    return input;
}

/**
 * @brief                   :       Function to Normalize a 2D array of doubles
 *
 * @param input             :       2D input array
 * @param input_col_len     :       Number of examples per feature
 * @param input_row_len     :       Number of Features
 */
double** normalizeData_2D(double** input, long input_row_len, long input_col_len){
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
    return input;
}

/**
 * @brief               Function to initialize random weights for a 1D array.
 *
 *                      Matrix Should be flattened before being passed into this
 *                      fuction
 *
 * @param weights       1D array
 * @param len           Lenght of array
 */
double* init_random_weight_1D(long len){
    double* weights = calloc(len, sizeof(*weights));
    // Initialize random generator
    srand(44);
    for(long i = 0; i < len; i++){
        weights[i] = (rand()%10)/1000;
    }
    return weights;
}


/**
 * @brief               Function to initialize random weights for a 2D Array
 *
 * @param weights       Null pointer to 2D array
 * @param row_len       Number of rows
 * @param col_len       Number of cols
 */
double** init_random_weight_2D(long row_len, long col_len){
    double** weights = calloc(row_len, sizeof(*weights));
    for(long j = 0; j < row_len; j++){
        weights[j] = calloc(col_len, sizeof(*(weights[j])));
    }
    // Initialize random generator
    srand(2);
    for(long i = 0; i < row_len; i++){
        for(long j = 0; j < col_len; j++){
            // Set random weights
            weights[i][j] = (rand()%1000000)/1000000.0;
        }
    }
    return weights;
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

/**
 * @brief           Function to perform a forward propagation
 *
 */
void forward_Propagation(){
    
    // Convert static arrays to dynamic arrays
    double* input_mat_dyn = copy_static_to_dynamic_array_1D(NUM_OF_FEATURES, input_mat[INPUT_TRAIN_ROW]);
    printf("Input matrix:\n");
    print_1D_matrix(input_mat_dyn,  NUM_OF_FEATURES);

    // double** output_vec_dyn = copy_static_to_dynamic_array_2D(NUM_OF_OUTPUT_NODES, NUM_OF_EXAMPLES, output_vec);
    // printf("Original Output matrix:\n");
    // print_2D_matrix(output_vec_dyn, NUM_OF_EXAMPLES, NUM_OF_OUTPUT_NODES);

    // initialize random Hidden weight vectors
    // Synapse for input to hidden nodes
    double  **synapse_0 = init_random_weight_2D(NUM_OF_FEATURES, NUM_OF_HIDDEN_NODES);        // Input to hidden layer
    printf("Synapse 0:\n");
    print_2D_matrix(synapse_0, NUM_OF_FEATURES, NUM_OF_HIDDEN_NODES);
    // Synapse for hidden to output nodes
    double  **synapse_1 = init_random_weight_2D(NUM_OF_HIDDEN_NODES, NUM_OF_OUTPUT_NODES);    // hidden to output layer
    printf("Synapse 1:\n");
    print_2D_matrix(synapse_1, NUM_OF_HIDDEN_NODES, NUM_OF_OUTPUT_NODES);

    // Normalize the arrays
    input_mat_dyn = normalizeData_1D(input_mat_dyn,NUM_OF_FEATURES);
    printf("Normalized input matrix:\n");
    print_1D_matrix(input_mat_dyn, NUM_OF_FEATURES);

    // output_vec_dyn = normalizeData_2D(output_vec_dyn, NUM_OF_OUTPUT_NODES, NUM_OF_EXAMPLES);

    // Compute forward propagation for input to hidden node

    // Expand the dimensions of the input matrix
    double **input_mat_dyn_expanded = expand_on_axis(input_mat_dyn, NUM_OF_FEATURES);

    double** input_to_hidden_mat = matrixMult_2D_to_2D(input_mat_dyn_expanded, synapse_0, INPUT_SAMPLE_SIZE, NUM_OF_FEATURES, NUM_OF_FEATURES, NUM_OF_HIDDEN_NODES);   
    printf("Raw output of first hidden layer:\n");
    print_2D_matrix(input_to_hidden_mat, INPUT_SAMPLE_SIZE, NUM_OF_HIDDEN_NODES);

    // apply the activation sigmoid function to the current output
    for(long i = 0; i < INPUT_SAMPLE_SIZE; i++){
        for(long j = 0; j < NUM_OF_HIDDEN_NODES; j++){
            input_to_hidden_mat[i][j] = apply_sigmoid(input_to_hidden_mat[i][j]);
        }
    }

    printf("Modified output of first hidden layer:\n");
    print_2D_matrix(input_to_hidden_mat, INPUT_SAMPLE_SIZE, NUM_OF_HIDDEN_NODES);

    // Compute forward propagation for the hidden to output layer
    double** hidden_to_output = matrixMult_2D_to_2D(input_to_hidden_mat, synapse_1, INPUT_SAMPLE_SIZE, NUM_OF_HIDDEN_NODES, NUM_OF_HIDDEN_NODES, NUM_OF_OUTPUT_NODES);    
    printf("Output of second hidden layer:\n");
    print_2D_matrix(input_to_hidden_mat, INPUT_SAMPLE_SIZE, NUM_OF_OUTPUT_NODES);

    // matrix computed will have dimensions (3x1)
    // thus the matrix can be transposed and flattened
    hidden_to_output = transpose_mat(hidden_to_output, INPUT_SAMPLE_SIZE, NUM_OF_OUTPUT_NODES);         // transpose
    double* hidden_to_output_flattened = flatten(hidden_to_output, NUM_OF_EXAMPLES);               // Flatten

    // Apply the activation function
    for(long i = 0; i < INPUT_SAMPLE_SIZE; i++){
        hidden_to_output_flattened[i] = apply_sigmoid(hidden_to_output_flattened[i]);
    }

    // print the array
    printf("Final Output:\n");
    for(long i = 0; i < INPUT_SAMPLE_SIZE; i++){
        printf("%f\n", hidden_to_output_flattened[i]);
    }

    // deallocate memory
    free(input_mat_dyn);
    deallocate_double_pointer(input_mat_dyn_expanded, INPUT_SAMPLE_SIZE);
    // deallocate_double_pointer(output_vec_dyn, NUM_OF_OUTPUT_NODES);
    deallocate_double_pointer(synapse_0, NUM_OF_FEATURES);
    deallocate_double_pointer(synapse_1, NUM_OF_HIDDEN_NODES);
    deallocate_double_pointer(input_to_hidden_mat, INPUT_SAMPLE_SIZE);
    deallocate_double_pointer(hidden_to_output, NUM_OF_OUTPUT_NODES);
    free(hidden_to_output_flattened);
}