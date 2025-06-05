//Saim Mukhtar
//22i-1415
//Assignment 1 (AI-A)

#include <iostream>
#include <string>
using namespace std;

struct Visitor {
    int ID;
    string name;
    string ticketType;
    string ridePref;
    Visitor* next;
};

class CircularQueue {
private:
    Visitor* rear;
public:
    CircularQueue() : rear(nullptr) {}

    void enqueue(int id, const string& name, const string& ticket, const string& ride) {
        Visitor* temp = new Visitor{ id, name, ticket, ride, nullptr };
        if (!rear) {
            rear = temp;
            rear->next = rear;
        }
        else {
            temp->next = rear->next;
            rear->next = temp;
            rear = temp;
        }
    }

    void displayQueue() {
        if (!rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        Visitor* temp = rear->next;
        do {
            cout << "ID: " << temp->ID << ", Name: " << temp->name << ", Ticket: " << temp->ticketType << ", Ride: " << temp->ridePref << endl;
            temp = temp->next;
        } while (temp != rear->next);
    }

    void dequeue() {
        if (!rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        Visitor* temp = rear->next;
        if (temp == rear) {
            delete temp;
            rear = nullptr;
        }
        else {
            rear->next = temp->next;
            delete temp;
        }
    }
};

int main() {
    CircularQueue queue;

    char choice;
    do {
        int id;
        string name, ticket, ride;
        cout << "Enter visitor ID: ";
        cin >> id;
        cout << "Enter visitor name: ";
        cin >> name;
        cout << "Enter ticket type: ";
        cin >> ticket;
        cout << "Enter ride preference: ";
        cin >> ride;
        queue.enqueue(id, name, ticket, ride);
        cout << "Do you want to add another visitor? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Queue status:" << endl;
    queue.displayQueue();

    cout << "Visitor enters the ride." << endl;
    queue.dequeue();

    cout << "Updated queue status:" << endl;
    queue.displayQueue();

    return 0;
}
