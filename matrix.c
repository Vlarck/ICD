#include <stdlib.h>
#include "matrix.h"

struct matrix create_matrix(int* data, int n_rows, int n_cols){
    struct matrix matrix;

    matrix.data = data;
    matrix.n_rows = n_rows;
    matrix.n_cols = n_cols;
    matrix.stride_rows = n_cols;
    matrix.stride_cols = 1;
    matrix.offset = 0;

    return matrix;
}

struct matrix zeros_matrix(int n_rows, int n_cols){
    int size = n_rows * n_cols;
    int* array = (int*) malloc(size * sizeof(int));

    for(int i = 0; i < size; i++){
        array[i] = 0;
    }

    struct matrix matrix = create_matrix(array, n_rows, n_cols);

    print_matrix(matrix);

    return matrix;
}

int get_element(struct matrix a_matrix, int ri, int ci){
    return a_matrix.data[a_matrix.stride_rows * ri + ci];
}

void print_matrix(struct matrix a_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    for(int i=0; i<size; i++){
        printf("%d ", a_matrix.data[i]);
        if((i+1)%a_matrix.stride_rows == 0){
            printf("\n");
        }
    }
}