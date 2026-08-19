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
    if (arr.size() == 0) return nullptr;

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
    vector<int> arr = {};

    Node* head = convertArrToLinkedList(arr);
    
    if (!head) return 0;

    Node* result = head;
    Node* block1 = head;
    Node* block2 = head->next;

    while(block2) {
        if (block1->val != block2->val) {
            block1->next = block2;
            block1 = block2; 
        }

        block2 = block2->next;
    }

    block1->next = nullptr;

    print(result);
}