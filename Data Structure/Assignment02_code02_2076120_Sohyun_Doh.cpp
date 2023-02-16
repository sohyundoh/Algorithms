#include <iostream>
#define X 3
#define Y 2
#define Z 4

using namespace std;

void mem_alloc_3D_double(double*** A) {
	for (int i = 0; i < X; i++) {
		A[i] = (double**)malloc(Z * sizeof(double*));
		for (int j = 0; j < Z; j++) {
			A[i][j] = (double*)malloc(Y * sizeof(double));
		}
	}
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Z; j++) {
			for (int k = 0; k < Y; k++) {
				A[i][j][k] = 0.1 + k + j + i;
			}
		}
	}
}
double*** addition_3D(double*** A, double*** B) {
	double*** C = (double***)malloc(sizeof(double***) * X);
	//allocation of addition matrix
	for (int i = 0; i < X; i++) {
		C[i] = (double**)malloc(Z * sizeof(double*));
		for (int j = 0; j < Z; j++) {
			C[i][j] = (double*)malloc(Y * sizeof(double));
		}
	}
	//implement of addition
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Z; j++) {
			for (int k = 0; k < Y; k++) {
				C[i][j][k] = A[i][j][k] + B[i][j][k];
			}
		}
	}
	return C;
}
void main() {

	//Define two matrices A and B using 'mem_alloc_3D_double'
	double*** A = (double***)malloc(sizeof(double**) * X);
	double*** B = (double***)malloc(sizeof(double**) * X);
	mem_alloc_3D_double(A);
	mem_alloc_3D_double(B);
	//print matrix A and B;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Z; j++) {
			for (int k = 0; k < Y; k++) {
				cout << A[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Z; j++) {
			for (int k = 0; k < Y; k++) {
				cout << B[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	//Perform addition of two matrices using 'addition_3D()'
	double*** C = addition_3D(A, B);
	//Printing the addition of A and B
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Z; j++) {
			for (int k = 0; k < Y; k++) {
				cout << C[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	//Deallocate A and B
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Z; j++) {
			free(A[i][j]);
			free(B[i][j]);
		}
		free(A[i]);
		free(B[i]);
	}
	free(A);
	free(B);
}