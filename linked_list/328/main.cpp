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

ListNode* oddEvenList(ListNode* head) {
    ListNode* current = head;

    vector<int> odd = {};
    vector<int> even = {};
    int index = 1;

    // Traverse the linked list and store values at odd and even
    // positions separately in their respective vectors.
    while (current) {
        if (index % 2 == 0) even.push_back(current->val);
        else odd.push_back(current->val);

        index++;
        current = current->next;
    }

    // Traverse the linked list again and overwrite its values
    // with all odd-position values first, followed by even-position values.
    current = head;

    for (int value: odd) {
        current->val = value;
        current = current->next;
    }

    for (int value: even) {
        current->val = value;
        current = current->next;
    }

    return head;
}

int main() {
    vector<int> arr = {2,1,3,5,6,4,7};

    ListNode* head = convertArrToLinkedList(arr);

    print(oddEvenList(head));

    return 0;
}