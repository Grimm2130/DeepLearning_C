#ifndef TESTING_FUNCS_H
#define TESTING_FUNCS_H

#include "testingFuncs.h"

#define LEN     3


/*======== Function Definitions =========*/
void run_simple_functions(){
    // input and weight arrays
    double in [] = {10, 23.0, 34.5},
        weights[] = {-1, 2.0, 4};
    /*Single input and Output neural network*/
    printf("\nFor a single input, single output neural network, we have the following\nInput:%f\nWeight:%f\nOutput:%f\n\n",in[1], weights[1], simple_nn(in[1], weights[1]));

    /*Single input and Multiple Output Neural network*/
    double* mult_out = multiple_output(in[1], weights, LEN);
    printf("\nFor a Single input, multiple output neural network, we have the following\n");
    printf("Input:%f\n", in[1]);
    printf("Weights: ");
    for(int i = 0; i < LEN; i++){
        printf("%f ",weights[i]);
    }
    printf("\n");
    printf("Outputs: ");
    for(int i = 0; i < LEN; i++){
        printf("%f ",mult_out[i]);
    }
    printf("\n");
    /*Multiple inputs and Single Outputs*/
    double mult_in_sing_out = mult_in_single_out(in, weights, LEN, LEN);
    printf("\nFor a Multiple input, Single output neural network, we have the following\n");
    printf("Inputs: ");
    for(int i = 0; i < LEN; i++){
        printf("%f ", in[i]);
    }
    printf("\n");
    printf("Weights: ");
    for(int i = 0; i < LEN; i++){
        printf("%f ", weights[i]);
    }
    printf("\n");
    printf("Output: %f", mult_in_sing_out);
    /*Memory release*/
    // free(mult_out);
}

void run_multiple_in_out_function(){
    double inputs[LEN] = {10,20,30};
    double weights [LEN][LEN] = {   {0.2, 0.3, 0.4},
                                    {0.4, 0.9, 1.6},
                                    {0.8, 1.8, 6.4}   };
    double output[3] = {0.0};
    
    // Calculate the outputs
    mult_in_mult_out(inputs, weights, output, LEN, LEN, LEN, LEN);

    printf("\nFor a Multiple input, Multiple output neural network, we have the following\n");
    printf("Inputs: ");
    for(int i = 0; i < LEN; i++){
        printf("%f ", inputs[i]);
    }
    printf("\n");
    printf("Weights: ");
    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < LEN; j++){
            printf("%f ", weights[i][j]);
        }
        printf("\n");
    }
    printf("Output: ");
    for(int i = 0; i < LEN; i++){
        printf("%f ", output[i]);
    }
    printf("\n");
}

void hidden_layer_processing(){
    double inputs[LEN] = {30, 87, 110};
                                                    // temp, hum, air_q
    double input_to_hidden_weights[LEN][LEN] = {    {-2, 9.5, 2.01},      // Hid[0]
                                                    {-0.8, 7.2, 6.3},       // Hid[1]
                                                    {-0.5, 0.45, 0.9} };    // Hid[2]
    
    // Hidden to output weights
    double hidden_to_output_weights[LEN][LEN] = {   {-1.0, 1.15, 0.11},       // Sad
                                                    {-0.18, 0.15, -0.01},   // Sick
                                                    {0.25, -0.25, -0.1} };  // Active

    double hidden[LEN] = {0.0};

    double outputs[LEN] = {0.0};

    /*Calculate the Hidden and output layers*/
    input_to_hidden(inputs, input_to_hidden_weights, hidden, LEN, LEN, LEN, LEN);
    hidden_to_output(hidden, hidden_to_output_weights, outputs, LEN, LEN, LEN, LEN);

    printf("\nFor a Multiple input, Multiple output neural network, with a hidden layer we have the following\n");
    printf("Inputs: ");
    for(int i = 0; i < LEN; i++){
        printf("%f ", inputs[i]);
    }
    printf("\n");
    printf("Hidden layer weights: ");
    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < LEN; j++){
            printf("%f ", input_to_hidden_weights[i][j]);
        }
        printf("\n");
    }
    printf("Output layer weights: ");
    for(int i = 0; i < LEN; i++){
        for(int j = 0; j < LEN; j++){
            printf("%f ", hidden_to_output_weights[i][j]);
        }
        printf("\n");
    }

    printf("Hidden: ");
    for(int i = 0; i < LEN; i++){
        printf("%f ", hidden[i]);
    }
    printf("\n");

    printf("\nOutputs:\n");
    printf("Sad: %f\n", outputs[0]);
    printf("Sick: %f\n", outputs[1]);
    printf("Active: %f\n", outputs[2]);
    
    printf("\n");
}


void run_brute_force(){
    double input = 10,
            weight = 0.3,
            expected = 40,
            step_amount = 0.1;
    long epochs = 20;

    // Run the Brute force function
    printf("A Simple Bruteforce Learning Algorithm\n");
    brute_force_learning(input, weight, expected, step_amount, epochs);
}


void forward_propagation(){
    // Define constants
    const long  num_of_features = 2,
                num_of_examples = 3,

                num_of_hidden_nodes = 3,
                num_of_output_nodes = 1;

    /* initialize inputs */
    double  *hrs_of_workout = calloc(num_of_examples, sizeof(*hrs_of_workout)),
            *hrs_of_rest = calloc(num_of_examples, sizeof(*hrs_of_rest)),
            *muscle_gain = calloc(num_of_examples, sizeof(*muscle_gain));

    // Workout values initialization
    hrs_of_workout[0] = 2;
    hrs_of_workout[1] = 5;
    hrs_of_workout[2] = 1;

    // Rest values initialization
    hrs_of_rest[0] = 8;
    hrs_of_rest[1] = 5;
    hrs_of_rest[2] = 8;

    // Muscle gain values
    muscle_gain[0] = 200;
    muscle_gain[1] = 90;
    muscle_gain[2] = 190;

    double** raw_x = calloc(num_of_features, sizeof(*raw_x));
    raw_x[0] = hrs_of_workout;
    raw_x[1] = hrs_of_rest;

    double** raw_y = calloc(num_of_output_nodes, sizeof(*raw_y));
    raw_y[0] = muscle_gain;

    /* Initialize weights */
    double  **input_to_hidden = calloc(num_of_hidden_nodes, sizeof(*input_to_hidden)),
            **hidden_to_output = calloc(num_of_output_nodes, sizeof(*hidden_to_output));
    // Initialize columns in rows
    for(long i = 0; i < num_of_features; i++){
        input_to_hidden[i] = calloc(num_of_features, sizeof(*(input_to_hidden[i])));

        if(i < num_of_hidden_nodes)
            hidden_to_output[i] = calloc(num_of_hidden_nodes, sizeof(*(hidden_to_output[i])));
    }
}


void test_matrix_mult_func(){
    const int len = 4;
    double in_1[len] = {1,2,3,4};
    double in_2[len] = {5,6,7,8};

    double* val = matrixMult_1D_to_1D(in_1, in_2, len, len);
    printf("The result of the 1D multiplication is: \n");
    for(int i = 0; i < len; i++){
        printf("%f\t", val[i]);
    }
    printf("\n");
}


void test_matrix_mult_2D_func(){
    const int row_1 = 2,
        row_2 = 3,
        col_1 = 3,
        col_2 = 2;
    // declare the Static array
    double static_in_1[row_1][col_1] =  {   {1,2,3},
                                            {4,5,6}},

            static_in_2[row_2][col_2] = {   {7,8},
                                            {9,10},
                                            {11,12}};
    // Copy the static arrays to the dynamic array
    double** in_1 = copy_static_to_dynamic_array_2D(row_1, col_1, static_in_1);
    double** in_2 = copy_static_to_dynamic_array_2D(row_2, col_2, static_in_2);

    // Compute the result of the matrix multiplication
    double** res = matrixMult_2D_to_2D(in_1, in_2, row_1, row_2, col_1, col_2);
    printf("Result of multiplying A and B:\n");
    for(int i = 0; i < row_1; i++){
        for(int j = 0; j < col_2; j++){
            printf("%f\t", res[i][j]);
        }
        printf("\n");
    }
    // Deallocate the memory for the dynamic arrays
    deallocate_double_pointer(in_1, row_1);
    deallocate_double_pointer(in_2, row_2);
    deallocate_double_pointer(res, row_1);
}


void test_flatten_function(){
    const int   row_1 = 1,
                col_1 = 3;
    double static_in_1[row_1][col_1] =  {   {1,2,3} };
    double** in_1 = copy_static_to_dynamic_array_2D(row_1, col_1, static_in_1);

    // flatten the function
    double* res = flatten(in_1, col_1);
    printf("initial pointer:\n");
    for(int i = 0; i < col_1; i++){
        printf("%f\t", in_1[0][i]);
    }
    printf("\n");

    printf("Flattened pointer:\n");
    for(int i = 0; i < col_1; i++){
        printf("%f\t", res[i]);
    }
    printf("\n");
    deallocate_double_pointer(in_1, row_1);
    free(res);
}

void test_make_range_func(double start, double end, double step, int start_inclusive, int end_inclusive){
    double* range = make_range(start, end, step, start_inclusive, end_inclusive);
    // validate all the array array
    if(start_inclusive & end_inclusive){
        long length = (long) (((end-start)/step)+1);
        // Check if the startt and end values are valid
        if(range[0] == start && range[length-1] == end){
            printf("Valid Boundaries!\n");
        }
    }
    else if(start_inclusive & (!end_inclusive)){
        long length = (long) ((end-start)/step);
        // Check if the startt and end values are valid
        if(range[0] == start && range[length-1] == end-step){
            printf("Valid Boundaries!\n");
        }
    }
    else if((!start_inclusive) & end_inclusive){
        long length = (long) ((end-start)/step);
        // Check if the startt and end values are valid
        if(range[0] == (start+step) && range[length-1] == end){
            printf("Valid Boundaries!\n");
        }
    }
    else{
        long length = (long) (((end-start)/step)-1);
        // Check if the startt and end values are valid
        if(range[0] == start+step && range[length-1] == end-step){
            printf("Valid Boundaries!\n");
        }
    }
    free(range);
}


void test_sigmoid_func(){
    double  start = -100,
            end = 100,
            step = 0.5;
    long    start_inc = 1,
            end_inc = 1;
    long len = (long) (((end - start)/step)+1);

    double *values = make_range(start, end, step, start_inc, end_inc);
    printf("Printing values:\n");
    for(long i = 0; i < len; i++){
        printf("%f\t", values[i]);
    }
    printf("\n");

    // Apply sigmoid function
    printf("Applying the sigmoid function\n");
    for(long i = 0; i < len; i++){
        values[i] = apply_sigmoid(values[i]);
    }
    printf("\n");
    printf("Printing results\n");
    for(long i = 0; i < len; i++){
        printf("%f\t", values[i]);
    }
    printf("\n");
    return;
}


void test_expand_on_axis_func(){
    long len = (10-0)+1;
    double* range = make_range(0,10, 1,1,1);
    printf("Vector to be expanded:\n");
    for(long i = 0; i < len; i++){
        printf("%f\t", range[i]);
    }
    printf("\n");
    double **range_expanded = expand_on_axis(range, len);
    // Expanded values
    printf("Expanded vector:n\n");
    for(long i = 0; i < len; i++){
        printf("%f\t", range_expanded[0][i]);
    }
}


void test_matrix_transpose(){
    long    row_size = 1,
            col_size = 11;
    double **mat = calloc(row_size, sizeof(*mat));
    for(long i = 0; i < row_size; i++){
        mat[i] = calloc(col_size, sizeof(*(mat[i])));
        mat[i] = make_range(0,10,1,1,1);
    }
    // Elements of the primary matrix
    printf("Original matrix: \n");
    for(long i = 0; i < row_size; i++){
        for(long j = 0; j < col_size; j++){
            printf("%f\t", mat[i][j]);
        }
        printf("\n");
    }

    double **mat_T = transpose_mat(mat, row_size, col_size);
    printf("Transposed matrix: \n");
    for(long i = 0; i < col_size; i++){
        for(long j = 0; j < row_size; j++){
            printf("%f\t", mat_T[i][j]);
        }
        printf("\n");
    }
}

#endif