//Saim Mukhtar
//22i-1415
//Assignment 1 (AI-A)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* concatenate(Node* list1, Node* list2) {
    if (!list1) return list2;
    Node* current = list1;
    while (current->next) {
        current = current->next;
    }
    current->next = list2;
    return list1;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    int n, value;
    cout << "Enter the number of elements for list 1: ";
    cin >> n;
    cout << "Enter the elements for list 1: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        Node* newNode = new Node{ value, nullptr };
        if (!list1) {
            list1 = newNode;
        }
        else {
            Node* current = list1;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    cout << "Enter the number of elements for list 2: ";
    cin >> n;
    cout << "Enter the elements for list 2: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        Node* newNode = new Node{ value, nullptr };
        if (!list2) {
            list2 = newNode;
        }
        else {
            Node* current = list2;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    cout << "List 1 before concatenation: ";
    printList(list1);

    list1 = concatenate(list1, list2);

    cout << "List 1 after concatenation: ";
    printList(list1);

    return 0;
}
