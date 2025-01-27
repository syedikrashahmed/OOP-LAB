/*Task 3
Write a C++ program that:  Dynamically allocates a 2D array using pointers (not using vector or standard containers). 
     Fills the array with random integers between 1 and 100. 
     Pass the 2D array to function to perform these tasks: 
     Calculates and prints The sum of all elements in the array. 
     Calculates and prints The sum of each row and each column. 
     Calculates and prints The row and column with the highest sum. 
     Pass the 2D array to a function to transpose the matrix and print the resulting matrix.Free the dynamically allocated memory.
Note:
Use functions to perform the calculations and matrix operations (do not write all code inside main()). Handle edge cases, such as when the array has no elements or is improperly allocated.
Sample Output:

Original Matrix:
[ 12 35 56 ]
[ 8 45 67 ]
[ 23 54 34 ]

Sum of all elements: 434
Row sums: 103, 120, 111
Column sums: 43, 134, 157
Row with highest sum: Row 2
Column with highest sum: Column 3

Transposed Matrix:
[ 12 8 23 ]
[ 35 45 54 ]
[ 56 67 34 ]*/
#include <iostream>
#include <cstdlib>  
#include <ctime>  
using namespace std;

void sumall(int **matrix, int row, int col);
void sumrow(int **matrix, int row, int col);
void sumcol(int **matrix, int row, int col);
void maxr(int **matrix, int row, int col);
void maxc(int **matrix, int row, int col);
void transpose(int **matrix, int row, int col);

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    int** matrix = new int*[rows];  
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];  
    }
    srand(time(0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    sumall(matrix, rows, cols);
    sumrow(matrix, rows, cols);
    sumcol(matrix, rows, cols);
    maxr(matrix, rows, cols);
    maxc(matrix, rows, cols);
    transpose(matrix, rows, cols);

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i]; 
    }
    delete[] matrix;  
}

void sumall(int **matrix, int row, int col) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum = sum + matrix[i][j];  
        }
    }
    cout << "Sum of all elements: " << sum << endl;
}

void sumrow(int **matrix, int row, int col) {
    cout << "Row sums: " ;
    for (int i = 0; i < row; i++) {
        int rowsum = 0;
 
        for (int j = 0; j < col; j++) {
            rowsum += matrix[i][j]; 
        }
        cout << rowsum << " , ";
    }
    cout << endl;
}

void sumcol(int **matrix, int row, int col) {
    cout << "Column sums: " ;
    for (int j = 0; j < col; j++) {
        int colsum = 0;
        for (int i = 0; i < row; i++) {
            colsum += matrix[i][j]; 
        }
        cout << colsum << " , ";
    }
}

void maxr(int **matrix, int row, int col) {
    int maxrow = 0;
    for (int i = 0; i < row; i++) {
        int rowsum = 0;
        for (int j = 0; j < col; j++) {
            rowsum += matrix[i][j]; 
        }
        if (maxrow < rowsum) {
            maxrow = rowsum;
        }
    }
}

void maxc(int **matrix, int row, int col) {
    int maxcol = 0;
    for (int j = 0; j < col; j++) {
        int colsum = 0;
        for (int i = 0; i < row; i++) {
            colsum += matrix[i][j]; 
        }
        if (maxcol < colsum) {
            maxcol = colsum;
        }
    }
}

void transpose(int **matrix, int row, int col) {
    int** t = new int*[col];
    for (int i = 0; i < col; i++) {
        t[i] = new int[row];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            t[j][i] = matrix[i][j];
        }
    }

    cout << "\nTransposed Matrix:" << endl;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}


