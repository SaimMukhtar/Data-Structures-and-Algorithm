//i221415
//Saim Mukhtar
//DS Lab 5 T1

#include <iostream>
#include <string>

using namespace std;

struct Patient {
    string name;
    int age;
    int severity; 
};

struct Node {
    Patient data;
    Node* next;
};


class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(const Patient& patient) {
        Node* newNode = new Node{patient, nullptr};

        if (patient.severity >= 9) {
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                newNode->next = front; 
                front = newNode;
            }
        } else { 
            if (isEmpty()) {
                front = rear = newNode;
            } else {
                rear->next = newNode; 
                rear = newNode; 
            }
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No patient to dequeue." << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued Patient: " << temp->data.name << ", Age: " << temp->data.age 
             << ", Severity: " << temp->data.severity << endl;

        front = front->next; 
        delete temp; 

        if (front == nullptr) { 
            rear = nullptr; 
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Patients in Queue:" << endl;

        while (current != nullptr) {
            cout << "Name: " << current->data.name 
                 << ", Age: " << current->data.age 
                 << ", Severity: " << current->data.severity << endl;
            current = current->next;
        }
    }

    void peekFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front Patient: " << front->data.name 
             << ", Age: " << front->data.age 
             << ", Severity: " << front->data.severity << endl;
    }

    ~Queue() { 
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue hospitalQueue;

    int numPatients;

    cout << "Enter number of patients to add: ";
    cin >> numPatients;

    for (int i = 0; i < numPatients; ++i) {
        Patient patient;

        cout << "\nEnter details for patient " << (i + 1) << ":" << endl;

        cout << "Name: ";
        cin.ignore(); 
        getline(cin, patient.name);

        cout << "Age: ";
        cin >> patient.age;

        cout << "Illness Severity (1-10): ";
        cin >> patient.severity;

        while (patient.severity < 1 || patient.severity > 10) {
            cout << "Please enter a valid severity between 1 and 10: ";
            cin >> patient.severity;
        }

        hospitalQueue.enqueue(patient);
    }

    hospitalQueue.displayQueue();
    
    hospitalQueue.peekFront();
    
    hospitalQueue.dequeue();
    
    hospitalQueue.displayQueue();

    return 0;
}