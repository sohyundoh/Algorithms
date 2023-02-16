#include <iostream>
#define ROWS 6
#define COLS 6
#define MAX_TERMS 10
using namespace std;
typedef struct {
	int row;
	int col;
	int value;
} element;
typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms; //A number of elements 
} SparseMatrix;
void main() {
	// B_origin = { {0,0,0,7,0,0},{9,0,0,0,0,8},{0,0,0,0,0,0},{6,5,0,0,0,0},{0,0,0,0,0,1},{0,0,2,0,0,0} };
	SparseMatrix B = { {{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},6,6,7 };
	int B_origin[ROWS][COLS] = { 0, };
	int B_transpose[COLS][ROWS] = { 0, };
	//make original matrix
	for (int i = 0; i < B.terms; i++) {
		for (int k = 0; k < B.cols; k++) {
			if (B.data[i].col == k) {
				B_origin[B.data[i].row][k] = B.data[i].value;
			}
		}
	}
	//Transpose B_origin
	for (int i = 0; i < COLS; i++) {
		for (int k = 0; k < ROWS; k++) {
			B_transpose[k][i] = B_origin[i][k];
		}
	}
	SparseMatrix B_T; //Making Output data
	B_T.cols = B.rows;
	B_T.rows = B.cols;
	B_T.terms = B.terms;
	int num_terms = 0;
	for (int i = 0; i < COLS; i++) {
		for (int k = 0; k < ROWS; k++) {
			if (B_transpose[i][k] == 0) {
				continue;
			}
			B_T.data[num_terms] = { i,k,B_transpose[i][k] };
			num_terms++;
		}
	}
	//Printing non_zero matrix of B_T 
	cout << "Dense B_T = " << '\n';
	for (int i = 0; i < num_terms; i++) {
		cout << B_T.data[i].row << ' ' << B_T.data[i].col << ' ' << B_T.data[i].value << '\n';
	}
	cout << '\n';
	//Printing B_origin 
	cout << "B = " << '\n';
	for (int i = 0; i < ROWS; i++)
	{
		for (int k = 0; k < COLS; k++) {
			cout << B_origin[i][k] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	//Printing B_transpose
	cout << "B_T = " << '\n';
	for (int i = 0; i < COLS; i++)
	{
		for (int k = 0; k < ROWS; k++) {
			cout << B_transpose[i][k] << ' ';
		}
		cout << '\n';
	}
}