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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* current = head;
    int len = 0;

    while(current) {
        current = current->next;
        len++;
    }

    int index = len - n;

    if (index == 0) return head->next;

    ListNode* i = head;
    ListNode* j = head->next;
    int cnt = 1;

    while (j) {
        if (cnt == index) {
            j = j->next;
            i->next = j;
            break;
        }

        cnt++;
        i = i->next;
        j = j->next;
    }

    return head;
}

int main() {
    vector<int> arr = {1};
    int n = 1;

    ListNode* head = convertArrToLinkedList(arr);

    print(removeNthFromEnd(head, n));

    return 0;
}