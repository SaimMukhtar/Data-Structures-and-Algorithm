#include <iostream>
using namespace std;

int main() {
    int size1, size2 = 0;
    cout << "Enter size of Array 1: ";
    cin >> size1;

    int* arr1 = new int[size1];
    cout << "Enter elements: ";

    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of Array 2: ";
    cin >> size2;

    int* arr2 = new int[size2];
    cout << "Enter elements: ";

    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }



    cout << "\nArray 1: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\nArray 2: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }



    cout << "\nCommon Elements: ";
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
            }
        }
    }

    delete[] arr1;
    delete[] arr2;

    return 0;

}