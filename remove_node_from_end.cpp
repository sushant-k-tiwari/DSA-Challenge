#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);  // Create a dummy node to handle edge cases
    dummy->next = head;
    ListNode *first = dummy, *second = dummy;

    // Advance first pointer so that the gap between first and second is n nodes apart
    for (int i = 1; i <= n + 1; i++) {
        first = first->next;
    }

    // Move first to the end, maintaining the gap
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;
    
    // Return the new head
    ListNode* newHead = dummy->next;
    delete dummy;  // Don't forget to delete the dummy node to avoid memory leaks
    return newHead;
}

int main() {
    int listSize, value, n;

    // Input number of elements
    cout<<"enter size of list"<<endl;
    cin >> listSize;

    if (listSize <= 0) {
        cout << "Invalid size!" << endl;
        return 1;
    }

    // enter values of linked list
    cout<<"enter the values"<<endl;
    cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* current = head;

    for (int i = 1; i < listSize; i++) {
        cin >> value;
        current->next = new ListNode(value);
        current = current->next;
    }

    cout << "Enter the value of n: "<<endl;
    cin >> n;

    if (n <= 0 || n > listSize) {
        cout << "Invalid value of n!" << endl;
        return 1;
    }

    head = removeNthFromEnd(head, n);

    // Print the modified list
    cout << "Ans:\n";
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
