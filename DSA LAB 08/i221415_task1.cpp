#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void remove(int value) {
        if (head == nullptr)
            return;

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                if (temp == head) {
                    head = temp->next;
                    if (head != nullptr)
                        head->prev = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next != nullptr)
                        temp->next->prev = temp->prev;
                }
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    bool is_empty() {
        return head == nullptr;
    }

    bool is_full() {
        return false;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value;

    do {
        cout << "\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Check if empty\n";
        cout << "4. Check if full\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.remove(value);
                break;
            case 3:
                if (list.is_empty())
                    cout << "The list is empty.\n";
                else
                    cout << "The list is not empty.\n";
                break;
            case 4:
                if (list.is_full())
                    cout << "The list is full.\n";
                else
                    cout << "The list is not full.\n";
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

