#include <iostream>
using namespace std;

int** createMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void delMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void inputMatrix(int** matrix, int rows, int cols) {
    cout << "Enter the matrix elements: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at row " << i + 1 << ", column " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** addMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

int** mulMatrices(int** matrix1, int** matrix2, int r1, int c1, int c2) {
    int** result = createMatrix(r1, c2);
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < c1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    int r1, c1, r2, c2;
    cout << "Enter the number of rows and columns for the first matrix: " << endl;
    cin >> r1 >> c1;

    cout << "Enter the number of rows and columns for the second matrix: " << endl;
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1;
    }

    int** matrix1 = createMatrix(r1, c1);
    int** matrix2 = createMatrix(r2, c2);

    cout << "Enter the elements of the first matrix:" << endl;
    inputMatrix(matrix1, r1, c1);

    cout << "Enter the elements of the second matrix:" << endl;
    inputMatrix(matrix2, r2, c2);

    cout << "First matrix:" << endl;
    displayMatrix(matrix1, r1, c1);

    cout << "Second matrix:" << endl;
    displayMatrix(matrix2, r2, c2);

    int** sum = addMatrices(matrix1, matrix2, r1, c1);
    cout << "Sum of matrices:" << endl;
    displayMatrix(sum, r1, c1);

    int** product = mulMatrices(matrix1, matrix2, r1, c1, c2);
    cout << "Product of matrices:" << endl;
    displayMatrix(product, r1, c2);

    delMatrix(matrix1, r1);
    delMatrix(matrix2, r2);

    return 0;
}