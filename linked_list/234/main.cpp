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

bool isPalindrome(Node* head) {
    vector<int> arr = {};

    while(head) {
        arr.push_back(head->val);
        head = head->next;
    }

    int i = 0;
    int j = arr.size() - 1;

    while (i < j) {
        if (arr[i] != arr[j]) return false;
        i++, j--;
    }

    return true;
}

int main() {
    vector<int> arr = {1, 1};

    Node* head = convertArrToLinkedList(arr);

    cout << isPalindrome(head) << endl;

    return 0;
}