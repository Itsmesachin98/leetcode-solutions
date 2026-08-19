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
    vector<int> list1 = {1, 2, 4};
    vector<int> list2 = {1, 3, 4};

    Node* head1 = convertArrToLinkedList(list1);
    Node* head2 = convertArrToLinkedList(list2);

    Node* newHead = new Node(-1);
    Node* ans = newHead;

    while(head1 && head2) {
        if (head1->val <= head2->val) {
            newHead->next = head1;
            head1 = head1->next;
        } else {
            newHead->next = head2;
            head2 = head2->next;
        }

        newHead = newHead->next;
    }

    if (head1) {
        newHead->next = head1;
    } else {
        newHead->next = head2;
    }

    print(ans->next);
}