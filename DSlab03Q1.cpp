#include <iostream>
using namespace std;

// Class template
template <typename T>
class List {
private:
    T* list;           // Dynamic array to store the list elements
    int capacity;      // Maximum capacity of the list
    int length;        // Current number of elements in the list

    void resize() {
        // Resize the array to double its current size
        T* newList = new T[capacity * 2];
        for (int i = 0; i < length; i++) {
            newList[i] = list[i];
        }
        delete[] list;
        list = newList;
        capacity *= 2;
    }

public:
    // Constructor to initialize the list with a fixed capacity
    List(int initialSize = 100) {
        capacity = initialSize;
        list = new T[capacity];
        length = 0;
    }

    // Destructor to free the dynamically allocated memory
    ~List() {
        delete[] list;
    }

    // Insert an element at a specific position (0-based index)
    void insert(int position, T value) {
        if (position < 0 || position > length) {
            cerr << "Error: Position out of range." << endl;
            return;
        }

        if (length == capacity) {
            resize();
        }

        for (int i = length; i > position; --i) {
            list[i] = list[i - 1];
        }
        list[position] = value;
        ++length;
    }

    // Delete an element by its value (first occurrence)
    bool deleteByValue(T value) {
        for (int i = 0; i < length; ++i) {
            if (list[i] == value) {
                for (int j = i; j < length - 1; ++j) {
                    list[j] = list[j + 1];
                }
                --length;
                return true;
            }
        }
        return false;
    }

    // Delete an element by its position (0-based index)
    bool deleteByPosition(int position) {
        if (position < 0 || position >= length) {
            return false;
        }

        for (int i = position; i < length - 1; ++i) {
            list[i] = list[i + 1];
        }
        --length;
        return true;
    }

    // Search for an element by its value, return the position if found, otherwise -1
    int search(T value) {
        for (int i = 0; i < length; ++i) {
            if (list[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // Access an element by its position (0-based index)
    T access(int position) {
        if (position < 0 || position >= length) {
            cerr << "Error: Position out of range." << endl;
            // Return a default value or handle it as needed
            return T(); // Assuming T has a default constructor
        }
        return list[position];
    }

    // Return the current number of elements in the list
    int size() {
        return length;
    }

    // Check if the list is empty
    bool isEmpty() {
        return length == 0;
    }

    // Display the elements of the list
    void display() {
        for (int i = 0; i < length; ++i) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    List<int> list;

    int choice;
    int position, value;

    do {
        cout << "1. Insert element" << endl;
        cout << "2. Delete by value" << endl;
        cout << "3. Delete by position" << endl;
        cout << "4. Search for element" << endl;
        cout << "5. Access element at position" << endl;
        cout << "6. Display list" << endl;
        cout << "7. Check if list is empty" << endl;
        cout << "8. Get size of list" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter value: ";
                cin >> value;
                list.insert(position, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                if (list.deleteByValue(value)) {
                    cout << "Element deleted successfully." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 3:
                cout << "Enter position to delete: ";
                cin >> position;
                if (list.deleteByPosition(position)) {
                    cout << "Element deleted successfully." << endl;
                } else {
                    cout << "Invalid position." << endl;
                }
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                position = list.search(value);
                if (position != -1) {
                    cout << "Element found at position " << position << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 5:
                cout << "Enter position to access: ";
                cin >> position;
                value = list.access(position);
                if (position >= 0 && position < list.size()) {
                    cout << "Element at position " << position << " is " << value << endl;
                }
                break;
            case 6:
                cout << "List: ";
                list.display();
                break;
            case 7:
                if (list.isEmpty()) {
                    cout << "List is empty." << endl;
                } else {
                    cout << "List is not empty." << endl;
                }
                break;
            case 8:
                cout << "Size of list: " << list.size() << endl;
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}