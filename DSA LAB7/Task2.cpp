#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* frontPtr;
    Node* rearPtr;

public:
    Queue() {
        frontPtr = rearPtr = nullptr;
    }

    bool isEmpty() {
        return frontPtr == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            frontPtr = rearPtr = newNode;
        }
        else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = frontPtr;
        frontPtr = frontPtr->next;
        delete temp;
        if (frontPtr == nullptr)
            rearPtr = nullptr;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return frontPtr->data;
    }

    void display() {
        Node* temp = frontPtr;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int returnMiddle() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        Node* slow = frontPtr;
        Node* fast = frontPtr;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

void driverFunction() {
    Queue q;
    int data;
    cout << "Enter data to enqueue (-1 to stop): ";
    while (cin >> data && data != -1) {
        q.enqueue(data);
    }

    cout << "Middle element: " << q.returnMiddle() << endl;

    q.dequeue();
    cout << "Middle element after dequeue: " << q.returnMiddle() << endl;

    cout << "Queue elements: ";
    q.display();
}

int main() {
    driverFunction();
    return 0;
}
