#include <iostream>

using namespace std;

class ResizableArray {
private:
    int* arr;
    int capacity;
    int currentSize;

    void resize(int newCapacity) {
        int* temp = new int[newCapacity];
        for (int i = 0; i < currentSize; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }

public:
    ResizableArray() : arr(new int[1]), capacity(1), currentSize(0) {}

    ~ResizableArray() {
        delete[] arr;
    }

    void add(int value) {
        if (currentSize == capacity) {
            resize(2 * capacity);
        }
        arr[currentSize++] = value;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > currentSize) {
            return false;
        }
        if (currentSize == capacity) {
            resize(2 * capacity);
        }
        for (int i = currentSize; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        currentSize++;
        return true;
    }

    bool remove(int index) {
        if (index < 0 || index >= currentSize) {
            return false;
        }
        for (int i = index; i < currentSize - 1; i++) {
            arr[i] = arr[i + 1];
        }
        currentSize--;
        if (currentSize > 0 && currentSize <= capacity / 4) {
            resize(capacity / 2);
        }
        return true;
    }

    bool update(int index, int value) {
        if (index < 0 || index >= currentSize) {
            return false;
        }
        arr[index] = value;
        return true;
    }

    int get(int index) const {
        if (index < 0 || index >= currentSize) {
            return -1;
        }
        return arr[index];
    }

    int size() const {
        return currentSize;
    }

    void clear() {
        delete[] arr;
        arr = new int[1];
        capacity = 1;
        currentSize = 0;
    }

    void reverse() {
        for (int i = 0; i < currentSize / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[currentSize - i - 1];
            arr[currentSize - i - 1] = temp;
        }
    }

    int find(int value) const {
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1;
    }

    void printArray() const {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ResizableArray arr;
    int choice, value, index;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add an element\n";
        cout << "2. Insert an element at a specific position\n";
        cout << "3. Remove an element\n";
        cout << "4. Update an element\n";
        cout << "5. Get an element\n";
        cout << "6. Get the size of the array\n";
        cout << "7. Clear the array\n";
        cout << "8. Reverse the array\n";
        cout << "9. Find an element\n";
        cout << "10. Print the array\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                arr.add(value);
                break;

            case 2:
                cout << "Enter index and value to insert: ";
                cin >> index >> value;
                if (arr.insert(index, value)) {
                    cout << "Inserted successfully." << endl;
                } else {
                    cout << "Insertion failed. Index out of bounds." << endl;
                }
                break;

            case 3:
                cout << "Enter index to remove: ";
                cin >> index;
                if (arr.remove(index)) {
                    cout << "Removed successfully." << endl;
                } else {
                    cout << "Removal failed. Index out of bounds." << endl;
                }
                break;

            case 4:
                cout << "Enter index and value to update: ";
                cin >> index >> value;
                if (arr.update(index, value)) {
                    cout << "Updated successfully." << endl;
                } else {
                    cout << "Update failed. Index out of bounds." << endl;
                }
                break;

            case 5:
                cout << "Enter index to get value: ";
                cin >> index;
                value = arr.get(index);
                if (value != -1) {
                    cout << "Element at index " << index << " is " << value << endl;
                } else {
                    cout << "Get failed. Index out of bounds." << endl;
                }
                break;

            case 6:
                cout << "Size of the array is: " << arr.size() << endl;
                break;

            case 7:
                arr.clear();
                cout << "Array cleared." << endl;
                break;

            case 8:
                arr.reverse();
                cout << "Array reversed." << endl;
                break;

            case 9:
                cout << "Enter value to find: ";
                cin >> value;
                index = arr.find(value);
                if (index != -1) {
                    cout << "Element found at index " << index << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;

            case 10:
                cout << "Array contents: ";
                arr.printArray();
                break;

            case 11:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 11);

    return 0;
}
