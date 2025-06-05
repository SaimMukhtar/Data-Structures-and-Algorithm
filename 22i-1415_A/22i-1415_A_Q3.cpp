//Saim Mukhtar
//22i-1415
//Assignment 1 (AI-A)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

double findMedian(Node* head) {
    if (!head) return 0;

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == nullptr) {
        return (prev->data + slow->data) / 2.0;
    }
    else {
        return slow->data;
    }
}

int main() {
    Node* list = nullptr;
    int n, value;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    cout << "Enter the elements in sorted order: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        Node* newNode = new Node{ value, nullptr };
        if (!list) {
            list = newNode;
        }
        else {
            Node* current = list;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    cout << "Median: " << findMedian(list) << endl;

    return 0;
}
