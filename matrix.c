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
    for(int i=a_matrix.offset; i<size; i++){
        printf("%d ", a_matrix.data[i]);
        if((i+1)%a_matrix.stride_rows == 0){
            printf("\n");
        }
    }
}

struct matrix i_matrix(int n){
    int i = n;
    int* array = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n*n; i++){
        if(i % (n+1) != 0){
            array[i] = 0;
        }
        else{
            array[i] = 1;
        }
    }
    return create_matrix(array,n,n);
}

int sum(struct matrix a_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int sum=0;
    for (int i=0; i<size; i++){
        sum = sum + a_matrix.data[i];
    }
    
    return sum;
}

int mean(struct matrix a_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int sum=0;
    for (int i=0; i<size; i++){
        sum = sum + a_matrix.data[i];
    } 
    
    return sum/size;
    
}

int min(struct matrix a_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int min=a_matrix.data[0];
    for (int i=0; i<size; i++){
        if(min > a_matrix.data[i]){
            min = a_matrix.data[i];
        }
    } 
    return min;
}

int max(struct matrix a_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int max=a_matrix.data[0];
    for (int i=0; i<size; i++){
        if(max < a_matrix.data[i]){
            max = a_matrix.data[i];
        }
    } 
    return max;
}

