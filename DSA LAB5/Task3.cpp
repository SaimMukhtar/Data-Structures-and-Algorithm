#include <iostream>
using namespace std;

int power(int base, int exponent) 
{
    int result = 1;
    for (int i = 0; i < exponent; ++i)
    {
        result *= base;
    }
    return result;
}

void push(int stack[], int& top, int value)
{
    stack[++top] = value;
}

int pop(int stack[], int& top) 
{
    if (top == -1)
    {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    return stack[top--];
}

void decimalToBinary(int decimal) 
{
    const int sizet = 100;
    int binaryStack[sizet];
    int top = -1;

    while (decimal > 0) 
    {
        push(binaryStack, top, decimal % 2);
        decimal /= 2;
    }

    cout << "Binary representation: ";
    while (top != -1)
    {
        cout << pop(binaryStack, top);
    }
    cout << endl;
}

int main() 
{
    int decimal;

    cout << "Enter decimal number: ";
    cin >> decimal;

    decimalToBinary(decimal);

    return 0;
}