#include <iostream>

using namespace std;

// Function prototypes
void inputMatrix(int** matrix, int rows, int columns);
void displayMatrix(int** matrix, int rows, int columns);
int calculateSumOfElements(int** matrix, int rows, int columns);
void displayRowWiseSum(int** matrix, int rows, int columns);
void displayColumnWiseSum(int** matrix, int rows, int columns);
int** createTranspose(int** matrix, int rows, int columns);

int main() {
    int rows, columns;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> columns;

    // Allocate memory for the matrix
    int** userMatrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        userMatrix[i] = new int[columns];
    }

    int choice;

    for (;;) {
        cout << "\nMenu:\n";
        cout << "1. Input elements into matrix\n";
        cout << "2. Display elements of matrix\n";
        cout << "3. Calculate sum of all elements of matrix\n";
        cout << "4. Display row-wise sum of matrix\n";
        cout << "5. Display column-wise sum of matrix\n";
        cout << "6. Create transpose of matrix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            inputMatrix(userMatrix, rows, columns);
        }
        else if (choice == 2) {
            displayMatrix(userMatrix, rows, columns);
        }
        else if (choice == 3) {
            cout << "Sum of all elements: " << calculateSumOfElements(userMatrix, rows, columns) << endl;
        }
        else if (choice == 4) {
            displayRowWiseSum(userMatrix, rows, columns);
        }
        else if (choice == 5) {
            displayColumnWiseSum(userMatrix, rows, columns);
        }
        else if (choice == 6) {
            int** transposedMatrix = createTranspose(userMatrix, rows, columns);
            cout << "Transpose of matrix:\n";
            displayMatrix(transposedMatrix, columns, rows);

            // Deallocate memory for transposed matrix
            for (int i = 0; i < columns; ++i) {
                delete[] transposedMatrix[i];
            }
            delete[] transposedMatrix;
        }
        else if (choice == 0) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    // Deallocate memory for the matrix
    for (int i = 0; i < rows; ++i) {
        delete[] userMatrix[i];
    }
    delete[] userMatrix;

    return 0;
}

void inputMatrix(int** matrix, int rows, int columns) {
    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int** matrix, int rows, int columns) {
    cout << "Matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int calculateSumOfElements(int** matrix, int rows, int columns) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void displayRowWiseSum(int** matrix, int rows, int columns) {
    cout << "Row-wise sum:\n";
    for (int i = 0; i < rows; ++i) {
        int rowSum = 0;
        for (int j = 0; j < columns; ++j) {
            rowSum += matrix[i][j];
        }
        cout << "Sum of elements in row " << i + 1 << ": " << rowSum << endl;
    }
}

void displayColumnWiseSum(int** matrix, int rows, int columns) {
    cout << "Column-wise sum:\n";
    for (int j = 0; j < columns; ++j) {
        int colSum = 0;
        for (int i = 0; i < rows; ++i) {
            colSum += matrix[i][j];
        }
        cout << "Sum of elements in column " << j + 1 << ": " << colSum << endl;
    }
}

int** createTranspose(int** matrix, int rows, int columns) {
    // Allocate memory for the transposed matrix
    int** transposedMatrix = new int* [columns];
    for (int i = 0; i < columns; ++i) {
        transposedMatrix[i] = new int[rows];
    }

    // Fill the transposed matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    return transposedMatrix;
}
