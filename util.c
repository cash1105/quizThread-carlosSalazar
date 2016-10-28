#include "util.h"
#include <stdio.h>

void inicializar1(double *A, double *B) {
	int i,j;
	for (i = 0; i < DIM; i++)
		for (j = 0; j < DIM; j++) {
			if (i == j){ 
				*(B+i*DIM+j) = 1;
			//printf("B[%d][%d]:%lf\n",i,j,*(B+i*DIM+j));
			}
			else{
				*(B+i*DIM+j) = 0;
			*(A + i*DIM + j) = i*DIM + j;
			//printf("A[%d][%d]:%lf\n",i,j,*(A + i*DIM + j));
			}

		}

	printf("Matrix A:\n");
	printMatrix(A);
	printf("\n\n\n");
	printf("Matrix B:\n");
	printMatrix(B);
	printf("\n\n\n");

}

void inicializar2(double *A, double *B) {
	inicializar1(A,B);
}

// Esta funcion debe recibir como argumento la variable C
int validar1(double *C) {
	int i,j;
	printf("Entro\n");
	double contador = 0.0;
	for (int i = 0; i < DIM; i++)
		for (int j = 0; j < DIM; j++) {
		 	//printf("C[%d][%d]=%lf, contador:%lf\n",i,j,*(C+i*DIM+j),contador);

			if (*(C + i*DIM + j) != contador)
				return 1;
			contador++;
		}

	return 0;
}

double validar2(double *C) {
	int i,j;
	double contador = 0.0;
	for (int i = 0; i < DIM; i++)
		for (int j = 0; j < DIM; j++) {
			contador += *(C + i*DIM + j);
		}

	return contador;
}

void printMatrix(double* mat) {
	int i, j;
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++)
			printf("%7.3lf  ", *(mat+i*DIM+j));
		printf("\n");
	}
}
