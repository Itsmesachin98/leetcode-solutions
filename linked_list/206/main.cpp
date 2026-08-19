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
    vector<int> arr = {1, 2};

    Node* head = convertArrToLinkedList(arr);

    // Logic here
    if (!head || head->next == nullptr) return 0;

    Node* i = new Node(-10000);
    Node* j = head;
    Node* k = head->next;

    while(k) {
        if (i->val == -10000) {
            j->next = nullptr;
        } else {
            j->next = i;
        }

        i = j;
        j = k;
        k = k->next; 
    }

    j->next = i;

    print(j);
}