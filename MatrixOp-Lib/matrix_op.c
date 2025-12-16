#include "matrix_op.h"

/* Addition */
void mat_add(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            C[i][j] = A[i][j] + B[i][j];
}

/* Subtraction */
void mat_sub(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            C[i][j] = A[i][j] - B[i][j];
}

/* Element-wise Multiplication */
void mat_elem_mul(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            C[i][j] = A[i][j] * B[i][j];
}

/* Matrix Multiplication */
void mat_mul(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

/* Transpose */
void mat_transpose(int A[SIZE][SIZE], int T[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            T[j][i] = A[i][j];
}

/* Determinant 3x3 */
int mat_det(int A[SIZE][SIZE]) {
    return
        A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) -
        A[0][1]*(A[1][0]*A[2][2] - A[1][2]*A[2][0]) +
        A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);
}

/* Adjoint */
void mat_adjoint(int A[SIZE][SIZE], int adj[SIZE][SIZE]) {
    adj[0][0] =  (A[1][1]*A[2][2] - A[1][2]*A[2][1]);
    adj[0][1] = -(A[1][0]*A[2][2] - A[1][2]*A[2][0]);
    adj[0][2] =  (A[1][0]*A[2][1] - A[1][1]*A[2][0]);

    adj[1][0] = -(A[0][1]*A[2][2] - A[0][2]*A[2][1]);
    adj[1][1] =  (A[0][0]*A[2][2] - A[0][2]*A[2][0]);
    adj[1][2] = -(A[0][0]*A[2][1] - A[0][1]*A[2][0]);

    adj[2][0] =  (A[0][1]*A[1][2] - A[0][2]*A[1][1]);
    adj[2][1] = -(A[0][0]*A[1][2] - A[0][2]*A[1][0]);
    adj[2][2] =  (A[0][0]*A[1][1] - A[0][1]*A[1][0]);
}

/* Inverse */
int mat_inverse(int A[SIZE][SIZE], float inv[SIZE][SIZE]) {
    int det = mat_det(A);
    if (det == 0) return 0;

    int adj[SIZE][SIZE];
    mat_adjoint(A, adj);

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            inv[i][j] = adj[i][j] / (float)det;

    return 1;
}
