#include <iostream>
using namespace std;

class Stack {
public:
    int size;
    int top;
    int* arr;

    Stack(int size) : size(size), top(-1) 
    {
        arr = new int[size];
    }

    ~Stack() 
    {
        delete[] arr;
    }

    bool isEmpty() 
    {
        return top == -1;
    }

    bool isFull() 
    {
        return top == size - 1;
    }

    void push(int val) 
    {
        if (isFull())
        {
            cout << "Stack Overflow! " << endl;
        }
        else
        {
            arr[++top] = val;
        }
    }

    int pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow! " << endl;
            return -1; 
        }
        else 
        {
            return arr[top--];
        }
    }

    int peek() 
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        else 
        {
            return arr[top];
        }
    }
};

int main() 
{
    Stack s(15); 
  
    s.push(9); 
    cout << "Peek value: " << s.peek() << endl; 

    if (!s.isEmpty()) 
    {
        cout << "Popped value: " << s.pop() << endl; 
    }

    if (s.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    if (!s.isFull()) 
    {
        cout << "Stack is not full" << endl;
    }

    return 0;
}
