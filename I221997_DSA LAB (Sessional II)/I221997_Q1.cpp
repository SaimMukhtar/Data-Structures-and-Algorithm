#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int x) : value(x), next(nullptr) {}
};

// Function to take input for a linked list
Node* Input_Node(int list_num) {
    int val;
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter elements of linked list " << list_num << endl;
    cout << "(enter -1 to end input) " << endl;

    while (true) {
        cin >> val;
        if (val == -1) break;
        if (!head) {
            head = new Node(val);
            tail = head;
        }
        else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }

    return head;
}

// Function to add input of linked list
Node* Add_Nodes(Node* l1, Node* l2) {
    Node* temp = new Node(0);
    Node* current = temp;
    int carry = 0;

    while (l1 || l2 || carry) {
        if (l1) {
            carry += l1->value;
            l1 = l1->next;
        }
        if (l2) {
            carry += l2->value;
            l2 = l2->next;
        }

        current->next = new Node(carry % 10);
        current = current->next;
        carry /= 10;
    }

    return temp->next;
}

// Function to print the linked list
void Print_Node(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to delete the linked list 
void Delete_Node(Node* head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    // Input for the first linked list
    Node* l1 = Input_Node(1);

    // Input for the second linked list
    Node* l2 = Input_Node(2);

    // Calculate the sum of the two linked lists
    Node* result = Add_Nodes(l1, l2);
    cout << "Sum of the two linked lists: ";
    Print_Node(result);

    // Delete dynamically allocated memory to avoid memory leaks
    Delete_Node(l1);
    Delete_Node(l2);
    Delete_Node(result);

    return 0;
}
