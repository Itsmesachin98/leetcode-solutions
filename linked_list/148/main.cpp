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

ListNode* sortList(ListNode* head) {
    ListNode* current = head;
    vector<int> arr = {};

    // Traverse the linked list and store all node values in the vector.
    while (current) {
        arr.push_back(current->val);
        current = current->next;
    }

    // Sort the values in the vector in ascending order.
    sort(arr.begin(), arr.end());

    // Traverse the linked list again and replace each node's value
    // with the corresponding sorted value from the vector.
    current = head;
    int index = 0;

    while(current) {
        current->val = arr[index];
        index++;
        current = current->next;
    }

    return head;
}

int main() {
    vector<int> arr = {4, 2, 1, 3};

    ListNode* head = convertArrToLinkedList(arr);

    print(sortList(head));

    return 0;
}