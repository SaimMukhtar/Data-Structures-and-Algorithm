#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};

class Stack
{
private:
    Node* top;
    int count;

public:
    Stack() : top(nullptr), count(0) {}

    ~Stack() 
    {
        Node* current = top;
        while (current != nullptr) 
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    bool isEmpty() 
    {
        return top == nullptr;
    }
    void push(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = top; 
        top = newNode; 
        count++;
    }

    int pop() {
        if (isEmpty()) 
        {
            cout << "Stack Underflow " << endl;
            return -1; 
        }
        else 
        {
            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp; 
            count--;
            return poppedValue;
        }
    }

    int peek()
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty." << endl;
            return -1; 
        }
        else
        {
            return top->value;
        }
    }

    int size()
    {
        return count;
    }
};

int main() 
{
    Stack s; 

    s.push(9); 
    cout << "Peek value: " << s.peek() << endl; 

    if (!s.isEmpty())
    {
        cout << "Popped value: " << s.pop() << endl; 
    }

    if (s.isEmpty())
    {
        cout << "Stack is empty!" << endl;
    }

    return 0;
}
