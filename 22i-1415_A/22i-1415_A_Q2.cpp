//Saim Mukhtar
//22i-1415
//Assignment 1 (AI-A)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertIntoSortedList(Node*& head, int value) {
    Node* newNode = new Node{ value, nullptr };
    if (!head || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list = nullptr;
    int n, value;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    cout << "Enter the elements in sorted order: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        insertIntoSortedList(list, value);
    }

    cout << "List after insertion: ";
    printList(list);

    return 0;
}
