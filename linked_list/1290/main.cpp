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

ListNode* reverseList(ListNode* head) {
    ListNode* prevNode = nullptr;
    ListNode* currentNode = head;
    ListNode* nextNode = head->next;

    while(nextNode) {
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
    }

    currentNode->next = prevNode;

    return currentNode;
}

int getDecimalValue(ListNode* head) {
    ListNode* current = reverseList(head);
    int result = 0;

    int i = 0;

    while (current) {
        if (current->val != 0) {
            result += current->val * pow(2, i);
        }

        i++;
        current = current->next;
    }

    return result;
}

int main() {
    vector<int> binaryArr = {1, 0, 1};

    ListNode* head = convertArrToLinkedList(binaryArr);

    int result = getDecimalValue(head);

    cout << result << endl;

    return 0;
}