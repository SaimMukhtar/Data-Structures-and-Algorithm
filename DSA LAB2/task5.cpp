#include <iostream>

using namespace std;

void middle_display(int arr[][3], int size) {
    int middle = size / 2;

    cout << "Middle Row: ";
    for (int j = 0; j < size; ++j) {
        cout << arr[middle][j] << " ";
    }
    cout << endl;

    cout << "Middle Column: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i][middle] << " ";
    }
    cout << endl;
}

int main() {
    int arr[][3] = { {2, 6, 9}, {3, 8, 5}, {2, 1, 8} };
    int size = 3;
    middle_display(arr, size);

    return 0;
}
