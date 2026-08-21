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

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    // Find the node just before index a
    ListNode* beforeA = list1;

    for (int i = 0; i < a - 1; i++) {
        beforeA = beforeA->next;
    }

    // Find the node at index b
    ListNode* atB = beforeA->next;

    for (int i = a; i < b; i++) {
        atB = atB->next;
    }

    // Find the last node of list2
    ListNode* current2 = list2;
    
    while(current2->next) {
        current2 = current2->next;
    }

    // Connect the nodes
    beforeA->next = list2;
    current2->next = atB->next;

    return list1;
}

int main() {
    vector<int> arr1 = {10,1,13,6,9,5};
    vector<int> arr2 = {1000000,1000001,1000002};
    int a = 3, b = 4;

    ListNode* list1 = convertArrToLinkedList(arr1);
    ListNode* list2 = convertArrToLinkedList(arr2);

    print(mergeInBetween(list1, a, b, list2));

    return 0;
}