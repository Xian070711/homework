#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

/* Basic */
void mat_add(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);
void mat_sub(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);
void mat_elem_mul(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);

/* Linear */
void mat_mul(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]);
void mat_transpose(int A[SIZE][SIZE], int T[SIZE][SIZE]);

/* Advanced */
int mat_det(int A[SIZE][SIZE]);
void mat_adjoint(int A[SIZE][SIZE], int adj[SIZE][SIZE]);
int mat_inverse(int A[SIZE][SIZE], float inv[SIZE][SIZE]);

#endif

