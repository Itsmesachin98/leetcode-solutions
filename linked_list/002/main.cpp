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

Node* addTwoNumbers(Node* l1, Node* l2) {
    Node* dummy = new Node(-1);
    Node* result = dummy;
    int carry = 0;

    while(l1 && l2) { 
        int sum = l1->val + l2->val + carry;

        if (sum >= 10) {
            carry = sum / 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }

        Node* newNode = new Node(sum);
        dummy->next = newNode;
        dummy = dummy->next;

        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1) {
        int sum = l1->val + carry;

        if(sum >= 10) {
            carry = sum / 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }

        Node* newNode = new Node(sum);
        dummy->next = newNode;
        dummy = dummy->next;

        l1 = l1->next;
    }

    while(l2) {
        int sum = l2->val + carry;

        if(sum >= 10) {
            carry = sum / 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }

        Node* newNode = new Node(sum);
        dummy->next = newNode;
        dummy = dummy->next;

        l2 = l2->next;
    }

    if (carry > 0) {
        Node* newNode = new Node(carry);
        dummy->next = newNode;
    }

    print(result->next);
    return result->next;
}

int main() {
    vector<int> list1 = {9, 2, 8, 9, 9, 5};
    vector<int> list2 = {8, 3, 6};

    Node* l1 = convertArrToLinkedList(list1);
    Node* l2 = convertArrToLinkedList(list2);

    addTwoNumbers(l1, l2);

    return 0;
}