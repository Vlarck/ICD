#include <stdio.h>
#include "matrix.c"

int main(void){
    struct matrix minhaMatrix;
    ///struct matrix minhaMatrix2;
    struct matrix zero_Matrix;
    struct matrix i_Matrix;
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

    printf("%d\n", maximo);

    return 0;
}
