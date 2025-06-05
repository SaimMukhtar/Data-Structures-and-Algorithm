#include <iostream>

using namespace std;

void product(float arr[], int size) {
    float product = 1.0;

    for (int i = 0; i < size; ++i) {
        arr[i] /= 2.0;
        product *= arr[i];
    }

    cout << "Modified Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Product is: " << product << endl;
}

int main() {
    float arr[] = { 5.36, 31.7854, 1.43, 2.2, 62.21 };
    int size = sizeof(arr) / sizeof(arr[0]);
    product(arr, size);

    return 0;
}
