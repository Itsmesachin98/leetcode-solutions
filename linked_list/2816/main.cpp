#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value, ListNode* address = nullptr) {
        val = value;
        next = address;
    }
};

ListNode* convertArrToLinkedList(vector<int>& arr) {
    if (arr.size() == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

void print(ListNode* head) {
    ListNode* current = head;

    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    } cout << endl;
}

ListNode* reverseList(ListNode* head) {
    ListNode* prevNode = nullptr;
    ListNode* currentNode = head;
    ListNode* nextNode = head->next;

    while(nextNode) {
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
    }

    currentNode->next = prevNode;

    return currentNode;
}

ListNode* doubleIt(ListNode* head) {
    ListNode* previous = nullptr;
    ListNode* current = reverseList(head);
    ListNode* dummy = current;

    int carry = 0;

    while (current) {
        int sum = current->val * 2 + carry;

        if (sum >= 10) {
            carry = sum / 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }

        current->val = sum;
        previous = current;
        current = current->next;
    }

    if (carry > 0) {
        ListNode* node = new ListNode(carry);
        previous->next = node;
    }

    ListNode* result = reverseList(dummy);

    return result;
}

int main() {
    vector<int> arr = {9,9,9};

    ListNode* head = convertArrToLinkedList(arr);

    print(doubleIt(head));

    return 0;
}