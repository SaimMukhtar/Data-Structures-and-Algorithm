#include <iostream>

using namespace std;

struct Node {
	
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {

private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool is_prime(int num) {
        if (num <= 1)
            return false;
        if (num <= 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }

    int product_of_prime_nodes()
	
	 {
        long long product = 1;
        
        Node* current = head;
        
        while (current != nullptr)
		 {
		 	
            if (is_prime(current->data))
                product *= current->data;
            current = current->next;
        }
        
        // Casting the product from long long to int to fit the return type
        return static_cast<int>(product);
    }
};

int main() {
    DoublyLinkedList list;

    int n, value;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    
    for (int i = 0; i < n; ++i)
	 {
        cin >> value;
        list.insert(value);
    }
    

    cout << "Product of prime node numbers: " << list.product_of_prime_nodes() << endl;

    return 0;
}

