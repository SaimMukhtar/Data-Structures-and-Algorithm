#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()

using namespace std;

// Hash Table Entry Structure
struct HashEntry {
    int key;
    int value;
    bool isOccupied;

    HashEntry() : key(0), value(0), isOccupied(false) {}
};

// Hash Table Class
class HashTable {
private:
    HashEntry *table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table = new HashEntry[size];
    }

    ~HashTable() {
        delete[] table;
    }

    void insertLinearProbing(int key, int value) {
        int index = hashFunction(key);
        for (int i = 0; i < size; i++) {
            int probeIndex = (index + i) % size;
            if (!table[probeIndex].isOccupied) {
                table[probeIndex].key = key;
                table[probeIndex].value = value;
                table[probeIndex].isOccupied = true;
                cout << "Inserted key " << key << " at index " << probeIndex << " (Linear Probing)\n";
                return;
            }
        }
        cout << "Hash Table is full! Could not insert key " << key << endl;
    }

    void insertQuadraticProbing(int key, int value) {
        int index = hashFunction(key);
        for (int i = 0; i < size; i++) {
            int probeIndex = (index + (i * i)) % size;
            if (!table[probeIndex].isOccupied) {
                table[probeIndex].key = key;
                table[probeIndex].value = value;
                table[probeIndex].isOccupied = true;
                cout << "Inserted key " << key << " at index " << probeIndex << " (Quadratic Probing)\n";
                return;
            }
        }
        cout << "Hash Table is full! Could not insert key " << key << endl;
    }

    void insertRandomProbing(int key, int value) {
        int index = hashFunction(key);
        srand(time(nullptr)); // Seed random number generator
        for (int i = 0; i < size; i++) {
            int probeIndex = (index + rand() % size) % size;
            if (!table[probeIndex].isOccupied) {
                table[probeIndex].key = key;
                table[probeIndex].value = value;
                table[probeIndex].isOccupied = true;
                cout << "Inserted key " << key << " at index " << probeIndex << " (Random Probing)\n";
                return;
            }
        }
        cout << "Hash Table is full! Could not insert key " << key << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        for (int i = 0; i < size; i++) {
            int probeIndex = (index + i) % size; // Linear probing for simplicity
            if (table[probeIndex].isOccupied && table[probeIndex].key == key) {
                cout << "Key " << key << " found at index " << probeIndex << " with value " << table[probeIndex].value << endl;
                return;
            }
        }
        cout << "Key " << key << " not found in the hash table.\n";
    }

    void display() {
        cout << "Hash Table Contents:\n";
        for (int i = 0; i < size; i++) {
            if (table[i].isOccupied) {
                cout << "[" << i << "] Key: " << table[i].key << ", Value: " << table[i].value << "\n";
            } else {
                cout << "[" << i << "] Empty\n";
            }
        }
    }
};

int main() {
    const int tableSize = 10;
    HashTable ht(tableSize);
    int choice, key, value, technique;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                cout << "Choose Collision Resolution Technique:\n";
                cout << "1. Linear Probing\n";
                cout << "2. Quadratic Probing\n";
                cout << "3. Random Probing\n";
                cout << "Enter your choice: ";
                cin >> technique;

                switch (technique) {
                    case 1:
                        ht.insertLinearProbing(key, value);
                        break;
                    case 2:
                        ht.insertQuadraticProbing(key, value);
                        break;
                    case 3:
                        ht.insertRandomProbing(key, value);
                        break;
                    default:
                        cout << "Invalid technique choice!\n";
                }
                break;
            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 3:
                ht.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
