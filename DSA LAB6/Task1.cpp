#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* mergeLists(Node* L1, Node* L2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (L1 != nullptr && L2 != nullptr) {
        if (L1->data < L2->data) {
            tail->next = L1;
            L1 = L1->next;
        }
        else {
            tail->next = L2;
            L2 = L2->next;
        }
        tail = tail->next;
    }

    if (L1 != nullptr) {
        tail->next = L1;
    }
    else {
        tail->next = L2;
    }

    return dummy.next;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void displayList(Node* head, string listName) {
    cout << listName << " : ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* L1 = new Node(1);
    L1->next = new Node(3);
    L1->next->next = new Node(5);
    L1->next->next->next = new Node(7);

    Node* L2 = new Node(2);
    L2->next = new Node(4);
    L2->next->next = new Node(6);
    L2->next->next->next = new Node(8);

    displayList(L1, "L1 Before Merging");
    displayList(L2, "L2 Before Merging");

    Node* mergedList = mergeLists(L1, L2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
