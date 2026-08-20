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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* reversedL1 = reverseList(l1);
    ListNode* reversedL2 = reverseList(l2);

    ListNode* sumOfList = new ListNode(-1);
    ListNode* result = sumOfList;

    int carry = 0;

    // Add corresponding digits from both reversed lists, calculate
    // their sum along with the carry, and create a new node for each digit.
    while(reversedL1 && reversedL2) {
        int sum = reversedL1->val + reversedL2->val + carry;

        if (sum >= 10) {
            carry = sum / 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }

        ListNode* newNode = new ListNode(sum);

        sumOfList->next = newNode;
        sumOfList = sumOfList->next;

        reversedL1 = reversedL1->next;
        reversedL2 = reversedL2->next;
    }

    // Continue adding the remaining digits from the longer list,
    // while also including any carry from the previous addition.
    while(reversedL1 || reversedL2) {
        int sum = reversedL1 ? reversedL1->val + carry : reversedL2->val + carry;

        if (sum >= 10) {
            carry = sum / 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }

        ListNode* newNode = new ListNode(sum);

        sumOfList->next = newNode;
        sumOfList = sumOfList->next;

        if (reversedL1) reversedL1 = reversedL1->next;
        else reversedL2 = reversedL2->next;
    }

    // If a carry is still left after processing both lists,
    // add it as the final node of the result.
    if (carry > 0) {
        ListNode* newNode = new ListNode(carry);
        sumOfList->next = newNode;
    }

    ListNode* reversedResult = reverseList(result->next);

    return reversedResult;
}

int main() {
    vector<int> list1 = {7,2,4,3};
    vector<int> list2 = {5,6,4};

    ListNode* l1 = convertArrToLinkedList(list1);
    ListNode* l2 = convertArrToLinkedList(list2);

    print(addTwoNumbers(l1, l2));

    return 0;
}