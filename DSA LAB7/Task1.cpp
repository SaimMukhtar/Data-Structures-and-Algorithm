#include <iostream>

using namespace std;

const int Maximum_size = 100;

class Queue {
private:
    int arr[Maximum_size];
    int front;
    int rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int data) {
        if (rear == Maximum_size - 1) {
            cout << "Queue is full." << endl;
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    int Front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }
};

void driverFunction() {
    Queue q;
    int data;
    cout << "Enter data to enqueue (-1 to stop): ";
    while (cin >> data && data != -1) {
        q.enqueue(data);
    }

    cout << "Front element: " << q.Front() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.Front() << endl;
}

int main() {
    driverFunction();
    return 0;
}
