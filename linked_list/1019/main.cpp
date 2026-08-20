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

ListNode* reverseList(ListNode* head, int& cnt) {
    ListNode* prevNode = nullptr;
    ListNode* currentNode = head;
    ListNode* nextNode = head->next;

    while(nextNode) {
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        nextNode = nextNode->next;
        cnt++;
    }

    currentNode->next = prevNode;

    return currentNode;
}

vector<int> nextLargerNodes(ListNode* head) {
    int cnt = 1;
    ListNode* current = reverseList(head, cnt);

    vector<int> result(cnt, 0);
    stack<int> s;


    // Traverse the reversed list and use a stack to find the next
    // greater value for each node. Remove all smaller or equal values
    // from the stack because they cannot be the next greater element.
    int i = 1;
    while(current) {
        while(!s.empty() && current->val >= s.top()) {
            s.pop();
        }

        if (!s.empty() && current->val < s.top()) {
            result[cnt - i] = s.top();
            s.push(current->val);
        } else {
            s.push(current->val);
            result[cnt - i] = 0;
        }

        i++;
        current = current->next;
    }

    return result;
}

int main() {
    vector<int> arr = {1, 9 , 2, 7, 5};

    ListNode* head = convertArrToLinkedList(arr);

    vector<int> result = nextLargerNodes(head);

    for (int num: result) cout << num << " ";
    cout << endl;

    return 0;
}