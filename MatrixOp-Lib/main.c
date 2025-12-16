#include <stdio.h>
#include "matrix_op.h"

void print_int(int M[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            printf("%4d ", M[i][j]);
        printf("\n");
    }
}

int main() {
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,5,4},{3,2,1}};
    int C[3][3];

    mat_add(A, B, C);
    printf("A + B:\n");
    print_int(C);

    return 0;
}
