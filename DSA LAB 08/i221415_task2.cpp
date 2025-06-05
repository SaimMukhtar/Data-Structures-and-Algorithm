#include <iostream>
using namespace std;

// Structure for a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
	
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert a node at the end of the list
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

    // Function to remove duplicates from the list
    void remove_duplicates() {
        Node* current = head;

        while (current != nullptr)
		
		 {
            Node* runner = current->next;
            
            
            while (runner != nullptr)
			
			 {
                if (runner->data == current->data) 
				
				{
                    Node* duplicate = runner;
                    runner->prev->next = runner->next;
                    
                    if (runner->next != nullptr)
                        runner->next->prev = runner->prev;
                        
                        
                    runner = runner->next;
                    
                    delete duplicate;
                }
                
                
                else
				
				 {
                    runner = runner->next;
                }
            }
            
            current = current->next;
        }
    }

    // Function to display the list
    void display() 
	
	{
        Node* temp = head;
        
        while (temp != nullptr)
		 {
            cout << temp->data;
            
            if (temp->next != nullptr)
                cout << "->";
            temp = temp->next;
        }
        
        cout << "->NULL" << endl;
    }
};


int main()

 {
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

    cout << "Original list: ";
    list.display();

    // Removing duplicates
    list.remove_duplicates();

    cout << "List after removing duplicates: ";
    
    list.display();

    return 0;
}

