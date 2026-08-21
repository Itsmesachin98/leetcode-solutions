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

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int> result = {-1, -1};

    if (!head || !head->next || !head->next->next) return result;

    ListNode* before = head;
    ListNode* current = head->next;
    ListNode* after = head->next->next;

    int index = 2;
    int firstCritical = -1;
    int previousCritical = -1;
    int minDistance = INT_MAX;

    while (after) {
        // Check whether current node is a local maximum or minimum.
        bool isCritical =
            (current->val > before->val && current->val > after->val) ||
            (current->val < before->val && current->val < after->val);


        if (isCritical) {
            if (firstCritical == -1) {
                // This is the first critical point.
                firstCritical = index;
            } else {
                // Distance from the previous critical point.
                minDistance = min(minDistance, (index - previousCritical));
            }

            // Remember the latest critical point.
            previousCritical = index;
        }

        index++;
        before = before->next;
        current = current->next;
        after = after->next;
    }

    // Fewer than two critical points.
    if (firstCritical == -1 || previousCritical == firstCritical) return result;

    // Distance between the first and last critical points.
    int maxDistance = previousCritical - firstCritical;

    result[0] = minDistance;
    result[1] = maxDistance;

    return result;
}

int main() {
    vector<int> arr = {1,3,2,2,3,2,2,2,7};

    ListNode* head = convertArrToLinkedList(arr);

    vector<int> result = nodesBetweenCriticalPoints(head);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}