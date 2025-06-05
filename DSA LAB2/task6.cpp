#include <iostream>
#include <fstream>

using namespace std;

const int rows = 5;
const int cols = 5;

void read(int arr[][cols]) {
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Unable to open file data.txt" << endl;
        exit(1);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(inputFile >> arr[i][j])) {
                cerr << "Error reading from file" << endl;
                exit(1);
            }
        }
    }

    inputFile.close();
}

void sum(int arr[][cols], int rowSum[]) {
    for (int i = 0; i < rows; ++i) {
        rowSum[i] = 0;
        for (int j = 0; j < cols; ++j) {
            rowSum[i] += arr[i][j];
        }
    }
}

int main() {
    int data[rows][cols];
    int rowSum[rows];

    read(data);

    sum(data, rowSum);

    cout << "Row-wise sums:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Row " << i + 1 << " sum: " << rowSum[i] << endl;
    }

    return 0;
}
