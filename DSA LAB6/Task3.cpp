#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    for (int i = 0; i <= n; ++i) {
        if (fast == nullptr) {
            cout << "Error: Invalid position." << endl;
            return head;
        }
        fast = fast->next;
    }

    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* list = nullptr;
    int n, val;
    int position;

    cout << "Enter the number of elements in the list: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of elements." << endl;
        return 0;
    }

    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        if (list == nullptr) {
            list = new ListNode(val);
        }
        else {
            ListNode* temp = list;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new ListNode(val);
        }
    }

    cout << "Enter the position from the end to remove (1-indexed): ";
    cin >> position;

    cout << "Input List: ";
    printList(list);

    ListNode* result = removeNthFromEnd(list, position);

    cout << "Output List: ";
    printList(result);

    return 0;
}
