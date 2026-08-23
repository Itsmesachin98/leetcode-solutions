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

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        if (slow == fast) return true;

        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

int main() {
    vector<int> arr = {3, 2, 0, -4};
    int pos = 1;

    ListNode* head = convertArrToLinkedList(arr);
    ListNode* current = head;

    while (current->next) {
        current = current->next;
    }

    ListNode* tail = current;

    current = head;

    int i = 0;

    while (current) {
        if (i == pos) {
            tail->next = current;
            break;
        }

        i++;
        current = current->next;
    }

    return 0;
}