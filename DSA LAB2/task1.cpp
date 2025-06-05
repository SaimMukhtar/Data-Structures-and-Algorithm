#include <iostream>

using namespace std;

void fun(int arr[], int size) {
    if (size <= 0) {
        cout << "Array is empty." << endl;
        return;
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Smallest element: " << min << endl;
    cout << "Largest element: " << max << endl;
}

int main() {
    int arr[] = { 4, 7, 2, 9, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    fun(arr, size);

    return 0;
}
