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

ListNode* deleteDuplicates(ListNode* head) {
    unordered_map<int, int> mp;

    ListNode* current = head;
    ListNode* newNode = new ListNode(-1);
    ListNode* result = newNode;

    while(current) {
        mp[current->val]++;
        current = current->next;
    }

    current = head;

    while(current) {
        if (mp[current->val] == 1) {
            ListNode* node = new ListNode(current->val);
            newNode->next = node;
            newNode = newNode->next;
        }

        current = current->next;
    }

    return result->next;
}

int main() {
    vector<int> arr = {1,1,1,2,3};

    ListNode* head = convertArrToLinkedList(arr);

    print(deleteDuplicates(head));

    return 0;
}