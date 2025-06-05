#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome(string str) {
    stack<char> charStack;

    for (char c : str) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            charStack.push(tolower(c));
        }
    }

    for (char c : str) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (charStack.top() != tolower(c)) {
                return false;
            }
            charStack.pop();
        }
    }

    return true;
}

int main() {
    string text;
    cout << "Enter a line of text: ";
    getline(cin, text);

    if (isPalindrome(text)) {
        cout << "The text is a palindrome." << endl;
    }
    else {
        cout << "The text is not a palindrome." << endl;
    }

    return 0;
}
