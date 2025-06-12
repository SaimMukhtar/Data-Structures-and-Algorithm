#include <iostream>
using namespace std;

// Node struct to represent each element in the linked list
struct Node {
    int data;
    Node* next;
};

// LinkedList class to manage the linked list
class LinkedList {
private:
    Node* head; // Pointer to the head of the linked list
    Node* tail; // Pointer to the tail of the linked list

public:
    // Constructor to initialize the linked list
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor to free the dynamically allocated memory
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert a new node at the beginning of the linked list
    void insertAtHead(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    // Insert a new node at the end of the linked list
    void insertAtEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Insert a new node at a specified position in the linked list
    void insertAtPosition(int position, int data) {
        if (position < 0) {
            cerr << "Error: Position out of range." << endl;
            return;
        }

        if (position == 0) {
            insertAtHead(data);
            return;
        }

        Node* newNode = new Node();
        newNode->data = data;

        Node* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            cerr << "Error: Position out of range." << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    // Insert a new node before a specified value in the linked list
    void insertBeforeValue(int value, int data) {
        if (head == nullptr) {
            cerr << "Error: List is empty." << endl;
            return;
        }

        if (head->data == value) {
            insertAtHead(data);
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* newNode = new Node();
                newNode->data = data;
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }

        cerr << "Error: Value not found in the list." << endl;
    }

    // Insert a new node after a specified value in the linked list
    void insertAfterValue(int value, int data) {
        if (head == nullptr) {
            cerr << "Error: List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                Node* newNode = new Node();
                newNode->data = data;
                newNode->next = current->next;
                current->next = newNode;

                if (newNode->next == nullptr) {
                    tail = newNode;
                }
                return;
            }
            current = current->next;
        }

        cerr << "Error: Value not found in the list." << endl;
    }

    // Utility function to display the current linked list
    void printList() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;

    int choice;
    int position, value, data;

    do {
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at end" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Insert before value" << endl;
        cout << "5. Insert after value" << endl;
        cout << "6. Print list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at head: ";
                cin >> data;
                list.insertAtHead(data);
                break;
            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                list.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter position to insert: ";
                cin >> position;
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAtPosition(position, data);
                break;
            case 4:
                cout << "Enter value to insert before: ";
                cin >> value;
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertBeforeValue(value, data);
                break;
            case 5:
                cout << "Enter value to insert after: ";
                cin >> value;
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAfterValue(value, data);
                break;
            case 6:
                cout << "List: ";
                list.printList();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}