#include <stdlib.h>
#include "Single_in_Single_out.h"
#include "Single_in_Multiple_out.h"
#include "Multiple_in_Single_out.h"
#include "Multiple_in_Multiple_out.h"
#include "HiddenLayer.h"
#include "BruteForceLearning.h"
#include "MuscleGain.h"
#include "Helpers.h"


void run_simple_functions();
void run_multiple_in_out_function();
void hidden_layer_processing();
void run_brute_force();

void test_matrix_mult_func();
void test_matrix_mult_2D_func();
void test_flatten_function();
void test_sigmoid_func();
void test_make_range_func(double start, double end, double step, int start_inclusive, int end_inclusive);
void test_expand_on_axis_func();
void test_matrix_transpose();