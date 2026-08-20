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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* current = head;
    int cnt = 1;
    vector<int> arr = {};

    // Traverse the linked list up to the 'right' position and store
    // the values from 'left' to 'right' in the vector.
    while(cnt <= right) {
        if (cnt >= left && cnt <= right) {
            arr.push_back(current->val);
        }

        cnt++;
        current = current->next;
    }

    // Reverse the values stored in the vector using two pointers.
    int i = 0;
    int j = arr.size() - 1;

    while (i < j) {
        swap(arr[i], arr[j]);
        i++, j--;
    }

    // Traverse the linked list again and replace the values from
    // 'left' to 'right' with the reversed values from the vector.
    current = head;
    cnt = 1;
    int index = 0;

    while(current) {
        if (cnt >= left && cnt <= right) {
            current->val = arr[index];
            index++;
        }

        cnt++;
        current = current->next;
    }

    return head;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int left = 2;
    int right = 4;

    ListNode* head = convertArrToLinkedList(arr);

    print(reverseBetween(head, left, right));

    return 0;
}