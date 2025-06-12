#include <iostream>

using namespace std;

template <typename T>
void swapValues(T& a, T& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int choice;
    
    cout << "Choose the type of values to swap:\n";
    cout << "1. Integer\n";
    cout << "2. Double\n";
    cout << "3. Float\n";
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int x, y;
            cout << "Enter two integers to swap:\n";
            cout << "Enter first integer: ";
            cin >> x;
            cout << "Enter second integer: ";
            cin >> y;
            cout << "Before swapping: x = " << x << ", y = " << y << endl;
            swapValues(x, y);
            cout << "After swapping: x = " << x << ", y = " << y << endl;
            break;
        }
        case 2: {
            double p, q;
            cout << "Enter two doubles to swap:\n";
            cout << "Enter first double: ";
            cin >> p;
            cout << "Enter second double: ";
            cin >> q;
            cout << "Before swapping: p = " << p << ", q = " << q << endl;
            swapValues(p, q);
            cout << "After swapping: p = " << p << ", q = " << q << endl;
            break;
        }
        case 3: {
            float m, n;
            cout << "Enter two floats to swap:\n";
            cout << "Enter first float: ";
            cin >> m;
            cout << "Enter second float: ";
            cin >> n;
            cout << "Before swapping: m = " << m << ", n = " << n << endl;
            swapValues(m, n);
            cout << "After swapping: m = " << m << ", n = " << n << endl;
            break;
        }
        default:
            cout << "Invalid choice. Exiting..." << endl;
            break;
    }

    return 0;
}
