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

void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    ListNode* current = head;
    vector<ListNode*> v;
    
    while(current) {
        v.push_back(current);
        current = current->next;
    }

    int left = 0;
    int right = v.size() - 1;

    ListNode* dummy = nullptr;

    while (left < right) {
        if (left == 0) {
            dummy = v[left];  
        } else {
            dummy->next = v[left];
            dummy = dummy->next;
        }

        dummy->next = v[right];
        dummy = dummy->next;

        left++, right--;
    }

    if (left == right) {
        dummy->next = v[left];
        dummy = dummy->next;
    }

    dummy->next = nullptr;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    ListNode* head = convertArrToLinkedList(arr);

    reorderList(head);

    print(head);

    return 0;
}