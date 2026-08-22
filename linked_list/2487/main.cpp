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

ListNode* removeNodes(ListNode* head) {
    ListNode* previous = reverseList(head);
    ListNode* current = previous->next;

    ListNode* dummy = previous;

    while (current) {
        if (current->val >= previous->val) {
            previous->next = current;
            previous = current;
        }

        current = current->next;
    }

    previous->next = nullptr;

    ListNode* result = reverseList(dummy);

    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    ListNode* head = convertArrToLinkedList(arr);

    print(removeNodes(head));

    return 0;
}