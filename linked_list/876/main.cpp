#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int value, Node* address = nullptr) {
        val = value;
        next = address;
    }
};

Node* convertArrToLinkedList(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < arr.size(); i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

void print(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    } cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    Node* head = convertArrToLinkedList(arr);
    
    Node* slow = head;
    Node* fast = head->next;

    while(fast) {
        slow = slow->next;
        fast = fast->next ? fast->next->next : fast->next;
    }

    print(slow);
}