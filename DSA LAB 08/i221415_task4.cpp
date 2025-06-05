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
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sort() {
        if (head == nullptr || head->next == nullptr)
            return;

        bool swapped;
        Node* current;
        Node* last = nullptr;

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    swap(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }

            last = current;
        } while (swapped);
    }

private:
    void swap(Node* node1, Node* node2) {
        if (node1 == nullptr || node2 == nullptr || node1 == node2)
            return;

        if (node1->prev != nullptr)
            node1->prev->next = node2;
        else
            head = node2;

        if (node2->prev != nullptr)
            node2->prev->next = node1;
        else
            head = node1;

        if (node1->next != nullptr)
            node1->next->prev = node2;
        else
            tail = node2;

        if (node2->next != nullptr)
            node2->next->prev = node1;
        else
            tail = node1;

        // Swap the next and prev pointers of node1 and node2
        Node* tempPrev = node1->prev;
        node1->prev = node2->prev;
        node2->prev = tempPrev;

        Node* tempNext = node1->next;
        node1->next = node2->next;
        node2->next = tempNext;
    }

};

int main() {
    DoublyLinkedList list;

   
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(6);
    list.insert(9);

    cout << "Original list: ";
    list.display();

    list.sort();

    cout << "Sorted list: ";
    list.display();

    return 0;
}

