#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//int main() {
//	int** mas1;
//	int n = 2;
//	int m = 3;
//	int i, j;
//	mas1 = (int**)malloc(m * sizeof(int*));	
//	for (i = 0; i < m; i++)
//	{
//		mas1[i] = (int**)malloc(n * sizeof(int*));
//	}
//	printf("¬ведите элементы матрицы\n"); //¬вод элементов матрицы
//	for (i = 0; i < m; i++) {
//		for (j = 0; j < n; j++)
//		{
//			scanf("%f", &mas1[i][j]);
//			printf("%f\n", &mas1[i][j]);
//		}
//	}
//	printf("%f\n", mas1[0][n - 1]);
//	
//}
//void main() {
//    int n = 2;
//    int m = 3;
//    float** A;
//    int i, j;
//    A = (float**)malloc(m * sizeof(float*));
//
//    for (i = 0; i < m; i++) {
//        A[i] = (float*)malloc(n * sizeof(float));
//    }
//
//    for (i = 0; i < m; i++) {
//        for (j = 0; j < n; j++)
//        {
//            scanf("%f", &A[i][j]);
//            //printf("%d\n", A[i][j]);
//        }
//    }
//    printf("%f\n", A[0][n-1]);
//    for (i = m - 1; i > 0; i--) {
//        free(A[i]);
//    }
//    free(A);
//}