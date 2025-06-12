//i221415
//Saim Mukhtar
//DS Lab 5 T2

#include <iostream>
#include <string>

using namespace std;

struct Carriage {
    int id;               
    int capacity;         
};

struct Node {
    Carriage data;        
    Node* next;          
    Node* prev;        
};

class Train {
private:
    Node* head;          
    Node* tail;          

public:
    Train() : head(nullptr), tail(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void addCarriageToFront(int id, int capacity) {
        Node* newNode = new Node{{id, capacity}, nullptr, nullptr};
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Carriage added to front: ID=" << id << ", Capacity=" << capacity << endl;
    }

    void addCarriageToEnd(int id, int capacity) {
        Node* newNode = new Node{{id, capacity}, nullptr, nullptr};
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Carriage added to end: ID=" << id << ", Capacity=" << capacity << endl;
    }

    void removeCarriageFromFront() {
        if (isEmpty()) {
            cout << "Train is empty. No carriage to remove from front." << endl;
            return;
        }

        Node* temp = head;
        cout << "Removed carriage from front: ID=" << temp->data.id 
             << ", Capacity=" << temp->data.capacity << endl;

        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else { 
            tail = nullptr;
        }

        delete temp; 
    }

    void removeCarriageFromEnd() {
        if (isEmpty()) {
            cout << "Train is empty. No carriage to remove from end." << endl;
            return;
        }

        Node* temp = tail;
        cout << "Removed carriage from end: ID=" << temp->data.id 
             << ", Capacity=" << temp->data.capacity << endl;

        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else { 
            head = nullptr;
        }

        delete temp; 
    }

    void displayAllCarriages() {
        if (isEmpty()) {
            cout << "Train is empty." << endl;
            return;
        }

        Node* current = head;
        cout << "Carriages in Train:" << endl;

        while (current != nullptr) {
            cout << "ID: " << current->data.id 
                 << ", Capacity: " << current->data.capacity << endl;
            current = current->next;
        }
    }

    void findCarriageByID(int id) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data.id == id) {
                cout << "Found Carriage: ID=" << current->data.id 
                     << ", Capacity=" << current->data.capacity << endl;
                return;
            }
            current = current->next;
        }
        
        cout << "Carriage with ID=" << id << " not found." << endl;
    }

    ~Train() { 
        while (!isEmpty()) {
            removeCarriageFromFront();
        }
    }
};

int main() {
    Train train;

    int choice, id, capacity;

    do {
        cout << "\nTrain Carriage Management System" << endl;
        cout << "1. Add Carriage to Front" << endl;
        cout << "2. Add Carriage to End" << endl;
        cout << "3. Remove Carriage from Front" << endl;
        cout << "4. Remove Carriage from End" << endl;
        cout << "5. Display All Carriages" << endl;
        cout << "6. Find Carriage by ID" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Carriage ID and Capacity: ";
                cin >> id >> capacity;
                train.addCarriageToFront(id, capacity);
                break;

            case 2:
                cout << "Enter Carriage ID and Capacity: ";
                cin >> id >> capacity;
                train.addCarriageToEnd(id, capacity);
                break;

            case 3:
                train.removeCarriageFromFront();
                break;

            case 4:
                train.removeCarriageFromEnd();
                break;

            case 5:
                train.displayAllCarriages();
                break;

            case 6:
                cout << "Enter Carriage ID to find: ";
                cin >> id;
                train.findCarriageByID(id);
                break;

            case 7:
                cout << "Exiting..."<<endl; 
                break;

            default:
                cout<< "Invalid choice! Please try again."<<endl; 
                break; 
       }
       
   } while (choice != 7);

   return 0; 
}