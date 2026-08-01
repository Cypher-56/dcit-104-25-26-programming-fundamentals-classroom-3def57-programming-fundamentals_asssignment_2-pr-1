// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int MAX = 10;

void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int transposed[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transposed, cols, rows);
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int sum[MAX][MAX];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(A, rows, cols);

    cout << "\nMatrix B:\n";
    displayMatrix(B, rows, cols);

    cout << "\nSum of Matrices:\n";
    displayMatrix(sum, rows, cols);
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int rowsA, int colsA, int colsB) {
    int product[MAX][MAX] = {0};

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            product[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(A, rowsA, colsA);

    cout << "\nMatrix B:\n";
    displayMatrix(B, colsA, colsB);

    cout << "\nProduct of Matrices (A x B):\n";
    displayMatrix(product, rowsA, colsB);
}

void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

int main() {
    int choice;
    cout << "Matrix Operations Menu:\n";
    cout << "1. Transpose a Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    int rows, cols, rowsA, colsA, colsB;
    int A[MAX][MAX], B[MAX][MAX];

    switch (choice) {
        case 1:
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            readMatrix(A, rows, cols);
            transposeMatrix(A, rows, cols);
            break;

        case 2:
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            cout << "\nEnter Matrix A:\n";
            readMatrix(A, rows, cols);
            cout << "\nEnter Matrix B:\n";
            readMatrix(B, rows, cols);
            addMatrices(A, B, rows, cols);
            break;

        case 3:
            cout << "Enter number of rows for Matrix A: ";
            cin >> rowsA;
            cout << "Enter number of columns for Matrix A: ";
            cin >> colsA;
            cout << "\nEnter Matrix A:\n";
            readMatrix(A, rowsA, colsA);

            cout << "Enter number of columns for Matrix B: ";
            cin >> colsB;
            cout << "\nEnter Matrix B:\n";
            readMatrix(B, colsA, colsB);

            multiplyMatrices(A, B, rowsA, colsA, colsB);
            break;

        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
