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

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* current = head;
    int len = 0;

    // Traverse the entire linked list to calculate its total length.
    while (current) {
        len++;
        current = current->next;
    }

    // Calculate the position of the node from the end that corresponds
    // to the kth node from the beginning.
    int k2 = len - k + 1;

    current = head;
    int i = 1;

    // Pointers to store the addresses of the kth node from the beginning
    // and the kth node from the end.
    ListNode* firstNode = nullptr;
    ListNode* secondNode = nullptr;

    // Traverse the list and find the kth node from the beginning
    // and the kth node from the end.
    while (current) {
        if (i == k) {
            firstNode = current;
        }

        if (i == k2) {
            secondNode = current;
        } 

        i++;
        current = current->next;
    }

    // Swap the values of the two identified nodes.
    int temp = firstNode->val;
    firstNode->val = secondNode->val;
    secondNode->val = temp;

    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    ListNode* head = convertArrToLinkedList(arr);

    print(swapNodes(head, k));

    return 0;
}