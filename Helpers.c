#include "Helpers.h"

/**
 * @brief                   Function to instantiate a double array of a specified range
 * 
 * @param start             Starting index of the range
 * @param end               End index of the range
 * @param step              Step size between each value in the range
 * @param start_inclusive   Range is inclusive of start index
 * @param end_inclusive     Range is inclusive of end range
 * 
 * @note                    "inclusive" args must be binary
 * @return double*          
 */
double* make_range(double start, double end, double step, int start_inclusive, int end_inclusive){
    if(start_inclusive >= 0 && start_inclusive <= 1 && end_inclusive >= 0 && end_inclusive <= 1 ){
        // declare returning array of range
        double* range = (double*)NULL;
        // Inclusive of start and end
        if(start_inclusive & end_inclusive){
            // Allocate memory for range vector
            long len = (long) (((end - start)/step)+1);
            range = calloc(len, sizeof(*range));
            long index = 0;
            // make range
            while(start <= end+(step/2.0)){
                range[index++] = start;
                start += step;
            }
        }
        else if(start_inclusive & (!end_inclusive)){
            long len = (long) ((end - start)/step);
            end -= step;
            range = calloc(len, sizeof(*range));
            long index = 0;
            // make range
            while(start <= end + (step/2.0)){
                range[index++] = start;
                start += step;
            }
        }
        else if((!start_inclusive) & end_inclusive){
            long len = (long) ((end - start)/step);
            start += step;
            range = calloc(len, sizeof(*range));
            long index = 0;
            // make range
            while(start <= end + (step/2.0)){
                range[index++] = start;
                start += step;
            }
        }
        else{
            long len = (long) (((end - start)/step)-1);
            start += step;
            end -= step;
            range = calloc(len, sizeof(*range));
            long index = 0;
            // make range
            while(start <= end + (step/2.0)){
                range[index++] = start;
                start += step;
            }
        }
        return range;
    }
    printf("invalid arguments for inclusivity\n");
    return (double*) NULL;
}

/**
 * @brief           Function to convert a 1D static array to a 1D dynamic array
 * 
 * @param len       Length of the  vector
 * @param vec       Static array
 * @return double* 
 */
double* copy_static_to_dynamic_array_1D(const long len, double vec[len]){
    double* ret = calloc(len, sizeof(*ret));
    for(long i = 0; i < len; i++){
        ret[i] = vec[i];
    }
    return ret;
}

/**
 * @brief               Function to Copy the contents of a static array to a dynamic array
 * 
 * @param row_len       Rows in the 2D array
 * @param col_len       Columns in the 2D array
 * @param static_array  Static 2D array
 * @return double**
 */
double** copy_static_to_dynamic_array_2D(const long row_len, const long col_len, double static_array[row_len][col_len]){
    // Define a 2D array
    double** ret = calloc(row_len, sizeof(*ret));
    for(long i = 0; i < row_len; i++){
        ret[i] = calloc(col_len, sizeof(*(ret[i])));
    }
    for(long i = 0; i < row_len; i++){
        for(long j = 0; j < col_len; j++){
            ret[i][j] = static_array[i][j];
        }
    }
    return ret;
}


/**
 * @brief           Function to deallocated a double pointer
 * 
 * @param ptr       Double Pointer to type of double 
 * @param size      Size of double pointer - number of pointers it points to
 */
void deallocate_double_pointer(double** ptr, long size){
    // Deallocate the pointers of the double pointer
    for(long i = 0; i < size; i++){
        free(ptr[i]);
    }
    free(ptr);
    // Notify user that the memory has been released
    printf("Memory cleared!!\n");
}

/**
 * @brief            Function to flatten a double pointer that points to only one pointer
 * 
 * @param mat        Double Pointer
 * @return double* 
 */
double* flatten(double** mat, long internal_size){
    // Allocate pointer
    double* ret = calloc(internal_size, sizeof(*ret));
    long i = 0;
    for(; i < internal_size; i++){
        *ret = *(mat[0]);
        ret++;
        (mat[0])++;
    }
    // return pointers to base addresses
    ret-=i;
    mat[0]-=i;
    // return flattened pointer
    return ret;
}

/**
 * @brief               Function to expand a 1D matrix to a 2D matrix
 * 
 * @param vec           1D vector
 * @return double** 
 */
double** expand_on_axis(double* vec, long len){
    double** res = calloc(1, sizeof(*res));
    *res = calloc(len, sizeof(**res));
    // copy the contents of the vector to the matrix
    for(long i = 0; i < len; i++){
        res[0][i] = vec[i];
    }
    return res;
}


/**
 * @brief               Function to transpose a matrix
 *
 * @param mat           2D matrix to be transposed
 * @param row_len       Row size of the matrix
 * @param col_len       Column size of the matrix
 * @return double** 
 */
double** transpose_mat(double** mat, long row_len, long col_len){
    // Declare a new matrix with the dimensions flipped
    double** ret = calloc(col_len, sizeof(*ret));
    for(long i = 0; i < col_len; i++){
        ret[i] = calloc(row_len, sizeof(*(ret[i])));
    }
    // Perform transpose operation
    for(long i = 0; i < row_len; i++){
        for(long j = 0; j < col_len; j++){
            ret[j][i] = mat[i][j];
        }
    }
    // return the transposed matrix
    return ret;
}

/**
 * @brief               Print  contents of a 1D matrix
 * 
 * @param mat           1D matrix
 * @param len           Number of items in matrix
 */
void print_1D_matrix(double* mat, long len){
    for(long i = 0; i < len; i++){
        printf("%f\t", mat[i]);
    }
    printf("\n");
}


/**
 * @brief               Print contents of a 2D matrix
 *
 * @param mat           2D matrix
 * @param row_len       Number of rows of 2D matrix
 * @param col_len       Number of cols of 2D matrix
 */
void print_2D_matrix(double** mat, long row_len, long col_len){
    for(long i = 0; i < row_len; i++){
        print_1D_matrix(mat[i], col_len);
    }
    printf("\n");
}