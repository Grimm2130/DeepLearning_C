#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <string.h>


// Iterators
double* make_range(double start, double end, double step, int start_inclusive, int end_inclusive);

// Memory manipulation
double** copy_static_to_dynamic_array(const long row_len, const long col_len, double static_array[row_len][col_len]);

// Matrix manipulation
void deallocate_double_pointer(double** ptr, long size);
double* flatten(double** mat, long internal_size);
double** expand_on_axis(double* vec, long len);
double** transpose_mat(double** mat, long row_len, long col_len);

#endif