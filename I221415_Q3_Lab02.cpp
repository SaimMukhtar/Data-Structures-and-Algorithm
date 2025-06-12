#include <iostream>

using namespace std;

class SortedCatalog {
private:
    int skus[10000]; 
    int size;        

public:
    SortedCatalog() : size(0) {}

    void addProduct(int sku) {
        int i = size - 1;
        while (i >= 0 && skus[i] > sku) {
            skus[i + 1] = skus[i]; 
            i--;
        }
        skus[i + 1] = sku; 
        size++; 
    }

    int findProduct(int sku) const {
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (skus[mid] == sku) {
                return mid; 
            } else if (skus[mid] < sku) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        return -1; 
    }

    void printCatalog() const {
        for (int i = 0; i < size; i++) {
            cout << skus[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SortedCatalog catalog;
    int choice, sku;

    do {
        cout << "\n1. Add a Product\n2. Find a Product\n3. Print Catalog\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter SKU to add: ";
                cin >> sku;
                catalog.addProduct(sku);
                break;
            case 2:
                cout << "Enter SKU to find: ";
                cin >> sku;
                int index;
                index = catalog.findProduct(sku);
                if (index != -1) {
                    cout << "Product " << sku << " found at index: " << index << endl;
                } else {
                    cout << "Product " << sku << " not found." << endl;
                }
                break;
            case 3:
                cout << "Catalog: ";
                catalog.printCatalog();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
