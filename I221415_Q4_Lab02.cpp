#include <iostream>

using namespace std;

class CustomerList {
private:
    int* customerIds;
    int capacity;
    int currentSize;

    void resize(int newCapacity) {
        int* temp = new int[newCapacity];
        for (int i = 0; i < currentSize; i++) {
            temp[i] = customerIds[i];
        }
        delete[] customerIds;
        customerIds = temp;
        capacity = newCapacity;
    }

public:
    CustomerList() : customerIds(new int[1]), capacity(1), currentSize(0) {}

    ~CustomerList() {
        delete[] customerIds;
    }

    void addCustomer(int customerId) {
        if (currentSize == capacity) {
            resize(2 * capacity);
        }
        customerIds[currentSize++] = customerId;
    }

    int findCustomer(int customerId) const {
        for (int i = 0; i < currentSize; i++) {
            if (customerIds[i] == customerId) {
                return i;
            }
        }
        return -1;
    }

    bool removeCustomer(int customerId) {
        int index = findCustomer(customerId);
        if (index == -1) {
            return false;
        }
        for (int i = index; i < currentSize - 1; i++) {
            customerIds[i] = customerIds[i + 1];
        }
        currentSize--;
        if (currentSize > 0 && currentSize <= capacity / 4) {
            resize(capacity / 2);
        }
        return true;
    }

    void printList() const {
        for (int i = 0; i < currentSize; i++) {
            cout << customerIds[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CustomerList list;
    int choice, customerId;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a customer\n";
        cout << "2. Find a customer\n";
        cout << "3. Remove a customer\n";
        cout << "4. Print list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1/2/3/4/5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer ID to add: ";
                cin >> customerId;
                list.addCustomer(customerId);
                cout << "Customer added successfully." << endl;
                break;

            case 2:
                cout << "Enter customer ID to find: ";
                cin >> customerId;
                int index;
                index = list.findCustomer(customerId);
                if (index != -1) {
                    cout << "Customer found at index " << index << endl;
                } else {
                    cout << "Customer not found." << endl;
                }
                break;

            case 3:
                cout << "Enter customer ID to remove: ";
                cin >> customerId;
                if (list.removeCustomer(customerId)) {
                    cout << "Customer removed successfully." << endl;
                } else {
                    cout << "Customer not found. Removal failed." << endl;
                }
                break;

            case 4:
                cout << "Customer List: ";
                list.printList();
                break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
