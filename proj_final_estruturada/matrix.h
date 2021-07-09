#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

struct matrix{
    int *data;
    int n_rows;
    int n_cols;
    int stride_rows;
    int stride_cols;
    int offset;
};

struct matrix create_matrix(int *data, int n_rows, int n_cols);

struct matrix zeros_matrix(int n_rows, int n_cols);

int get_element(struct matrix a_matrix, int ri, int ci);

void print_matrix(struct matrix a_matrix);

struct matrix i_matrix(int n);

struct matrix flatten(struct matrix a_matrix);

struct matrix slice(struct matrix a_matrix, int rs, int re, int cs, int ce);

int sum(struct matrix a_matrix);

float mean(struct matrix a_matrix);

int min(struct matrix a_matrix);

int max(struct matrix a_matrix);

#endif // MATRIX_H_INCLUDED
