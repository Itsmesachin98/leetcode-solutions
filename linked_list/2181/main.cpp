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

ListNode* mergeNodes(ListNode* head) {
    ListNode* current = head->next;
    ListNode* write = head;

    int sum = 0;

    while (current) {
        if (current->val == 0) {
            write = write->next;
            write->val = sum;
            sum = 0;
        } else {
            sum += current->val;
        }

        current = current->next;
    }

    write->next = nullptr;

    return head->next;
}

int main() {
    vector<int> arr = {0,1,0,3,0,2,2,0};

    ListNode* head = convertArrToLinkedList(arr);

    print(mergeNodes(head));

    return 0;
}