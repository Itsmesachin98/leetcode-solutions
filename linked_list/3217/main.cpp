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

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_map<int, int> um;

    // Store all values from nums in the hash map so we can
    // quickly check whether a linked list value should be removed.
    for (int i = 0; i < nums.size(); i++) {
        um[nums[i]] = 1;
    }

    ListNode* node = new ListNode(-1);
    ListNode* result = node;

    // Traverse the linked list and connect only those nodes whose
    // values are not present in the hash map.
    while (head) {
        if (!um[head->val]) {
            node->next = head;
            node = node->next;
        }

        head = head->next;
    }

    node->next = nullptr;

    return result->next;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 1, 2};
    vector<int> nums = {5};

    ListNode* head = convertArrToLinkedList(arr);

    print(modifiedList(nums, head));

    return 0;
}