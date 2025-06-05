#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool Palindrome(string text) {
    // Convert uppercase letters to lowercase
    for (char& c : text) {
        if (isupper(c)) {
            c = tolower(c);
        }
    }

    // Initialize a queue and a stack
    queue<char> q;
    stack<char> s;

    // Place each character into the queue and stack
    for (char c : text) {
        if (isalpha(c) || isdigit(c)) {
            q.push(c);
            s.push(c);
        }
    }

    // Check if the text is a palindrome
    while (!q.empty() && !s.empty()) {
        if (q.front() != s.top()) {
            return false;
        }
        q.pop();
        s.pop();
    }

    // If both queue and stack are empty, it's a palindrome
    return q.empty() && s.empty();
}

int main() {
    string text;
    cout << "Enter a line of text: ";
    getline(cin, text);

    if (Palindrome(text)) {
        cout << text << "  ... The text is a palindrome." << endl;
    }
    else {
        cout << text << "  ... The text is not a palindrome." << endl;
    }

    return 0;
}
