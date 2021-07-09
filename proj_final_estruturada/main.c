#include <stdio.h>
#include "matrix.c"

int main(void){
    struct matrix minhaMatrix;
    struct matrix minha_Matrix;
    ///struct matrix minhaMatrix2;
    struct matrix zero_Matrix;
    struct matrix i_Matrix;
    struct matrix s_lice;
    int soma;
    int media;
    int minimo;
    int maximo;

    int array[4] = {10,20,30,40};
    ///int array_2[4] = {100,200,300,400};

    minhaMatrix = create_matrix(array, 2, 2);
    ///minhaMatrix2 = create_matrix(array_2, 2, 2);
    soma = sum(minhaMatrix);
    media = mean(minhaMatrix);
    minimo = min(minhaMatrix);
    maximo = max(minhaMatrix);

    printf("\n");

    for(int i=0; i<4; i++){
        printf("%d ", minhaMatrix.data[i]);
    }

    printf("\n");
    printf("\n");

    zero_Matrix = zeros_matrix(3,3);

    printf("\n");

    printf("Elemento[0][1] = %d\n", get_element(minhaMatrix, 0, 0));
    printf("Elemento[1][1] = %d\n", get_element(minhaMatrix, 1, 1));

    printf("\n");

    print_matrix(minhaMatrix);

    i_Matrix = i_matrix(4);

    printf("\n");

    print_matrix(i_Matrix);

    printf("\n");

    printf("%d\n", soma);

    printf("\n");

    printf("%d\n", media);

    printf("\n");

    printf("%d\n", minimo);

    printf("\n");

    printf("%d\n\n", maximo);


    int array_2[9]={6,2,4,12,16,30,60,70,80};
    int array_3[9]={2,1,2,3,4,5,6,7,8};
    minha_Matrix = create_matrix(array_2, 3, 3);
    print_matrix(minha_Matrix);
    printf("\n\n");
    s_lice = slice(minha_Matrix, 0, 2, 1, 3);
    printf("\n\n");
    print_matrix(s_lice);
    printf("\n\n");



    struct matrix somatrix_a;
    struct matrix somatrix_b;

    somatrix_a = create_matrix(array_2, 3, 3);
    somatrix_b = create_matrix(array_3, 3, 3);



    somatrix_a=division(somatrix_a,somatrix_b);
    print_matrix(somatrix_a);
    printf("\n\n");
    somatrix_a=transpose(somatrix_a);
    print_matrix(somatrix_a);
    printf("\n\n");
    print_matrix(somatrix_b);
    printf("\n\n");
    somatrix_b=transpose(somatrix_b);
    print_matrix(somatrix_b);
    printf("\n\n");
    return 0;
};
