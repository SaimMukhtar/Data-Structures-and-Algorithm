#include <iostream>
using namespace std;

class ArrayList {
private:
    int* arr1; 
    int size;
    int capacity;

public:
    ArrayList() {
        capacity = 7;
        arr1 = new int[capacity];
        size = 0; 
    }

    ~ArrayList() {
        delete[] arr1;
    }

    void add(int element) {
        if (size == capacity) {
            capacity *= 2;
            int* tempAr = new int[capacity];
            for (int i = 0; i < size; ++i) {
                tempAr[i] = arr1[i];
            }
            delete[] arr1;
            arr1 = tempAr;
        }
        arr1[size++] = element;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index." << endl;
            return;
        }
        for (int i = index; i < size - 1; ++i) {
            arr1[i] = arr1[i + 1];
        }
        size--;
    }

    void display() {
        cout << "ArrayList: ";
        for (int i = 0; i < size; ++i) {
            cout << arr1[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayList intArrayList;

    intArrayList.add(5);
    intArrayList.add(8);
    intArrayList.add(2);
    intArrayList.add(21);
    intArrayList.add(15);
    intArrayList.add(17);

    intArrayList.display();

    intArrayList.remove(3);

    intArrayList.display();

    return 0;
}