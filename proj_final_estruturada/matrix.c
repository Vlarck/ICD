#include <stdlib.h>
#include "matrix.h"

struct matrix create_matrix(int *data, int n_rows, int n_cols){
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
    int j=a_matrix.offset;
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int row=0;
    for(int i=0; i<size; i++){
        printf("%d ", a_matrix.data[j]);
        j=j+a_matrix.stride_cols;
        if((i+1)%a_matrix.n_cols == 0){
            row++;
            j=a_matrix.offset+row*a_matrix.stride_rows;
            printf("\n");
        }

    }
}
void print_matrix_(struct matrix a_matrix){
    int j=0;
    for(int i = 0; i < a_matrix.n_rows; i++){
        j=a_matrix.offset+i*a_matrix.stride_rows;
        for(int i=0; i < a_matrix.n_cols;i++){
            printf("%d ", a_matrix.data[j]);
            j=j+a_matrix.stride_cols;}
    printf("\n");
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

float mean(struct matrix a_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    float sum=0;
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


struct matrix slice(struct matrix a_matrix, int rs, int re, int cs, int ce){
    a_matrix.offset=rs*a_matrix.n_cols+cs;
    a_matrix.n_cols=ce-cs;
    a_matrix.n_rows=re-rs;

  return a_matrix;
};


struct matrix add(struct matrix a_matrix, struct matrix b_matrix){
    int a=a_matrix.offset;
    int b=b_matrix.offset;
    int size = a_matrix.n_rows * a_matrix.n_cols;
    for(int i=0; i<size; i++){
        a_matrix.data[a]=a_matrix.data[a]+b_matrix.data[b];
        if((a+1)%a_matrix.stride_rows == 0){
            a=a+a_matrix.offset;
        }
        if((b+1)%a_matrix.stride_rows == 0){
            b=a+a_matrix.offset;
        }
        a++;
        b++;
    }
    return a_matrix;
};

struct matrix sub(struct matrix a_matrix, struct matrix b_matrix){
    int a=a_matrix.offset;
    int b=b_matrix.offset;
    int size = a_matrix.n_rows * a_matrix.n_cols;
    for(int i=0; i<size; i++){
        a_matrix.data[a]=a_matrix.data[a]-b_matrix.data[b];
        if((a+1)%a_matrix.stride_rows == 0){
            a=a+a_matrix.offset;
        }
        if((b+1)%a_matrix.stride_rows == 0){
            b=a+a_matrix.offset;
        }
        a++;
        b++;
    }
    return a_matrix;

};

struct matrix mul(struct matrix a_matrix, struct matrix b_matrix){
    int a=a_matrix.offset;
    int b=b_matrix.offset;
    int size = a_matrix.n_rows * a_matrix.n_cols;
    for(int i=0; i<size; i++){
        a_matrix.data[a]=a_matrix.data[a]*b_matrix.data[b];
        if((a+1)%a_matrix.stride_rows == 0){
            a=a+a_matrix.offset;
        }
        if((b+1)%a_matrix.stride_rows == 0){
            b=a+a_matrix.offset;
        }
        a++;
        b++;
    }
    return a_matrix;

};

struct matrix division(struct matrix a_matrix, struct matrix b_matrix){
    int a=a_matrix.offset;
    int b=b_matrix.offset;
    int size = a_matrix.n_rows * a_matrix.n_cols;
    for(int i=0; i<size; i++){
        a_matrix.data[a]=a_matrix.data[a]/b_matrix.data[b];
        if((a+1)%a_matrix.stride_rows == 0){
            a=a+a_matrix.offset;
        }
        if((b+1)%a_matrix.stride_rows == 0){
            b=a+a_matrix.offset;
        }
        a++;
        b++;
    }
    return a_matrix;

};
struct matrix transpose(struct matrix a_matrix){
    int temp_a=a_matrix.n_cols;
    int temp_b=a_matrix.stride_cols;
    a_matrix.n_cols=a_matrix.n_rows;
    a_matrix.stride_cols=a_matrix.stride_rows;
    a_matrix.n_rows=temp_a;
    a_matrix.stride_rows=temp_b;
    return a_matrix;
};

struct matrix flatten(struct matrix a_matrix){
    a_matrix.n_cols=a_matrix.n_cols*a_matrix.n_rows;
    a_matrix.stride_rows=a_matrix.n_cols*a_matrix.n_rows;
    a_matrix.n_rows=1;


    return a_matrix;
};

struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols){
    a_matrix.n_rows=new_n_rows;
    a_matrix.n_cols=new_n_cols;
    a_matrix.stride_rows=a_matrix.n_cols;
    return a_matrix;
};


