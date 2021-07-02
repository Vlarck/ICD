#include <stdio.h>
#include "matrix.c"

int main(){
    struct matrix minhaMatrix;
    struct matrix zero_Matrix;
    int array[4] = {10,20,30,40};

    minhaMatrix = create_matrix(array, 2, 2);
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

}
