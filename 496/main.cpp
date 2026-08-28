#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> nextGreater;
    stack<int> st;

    // Find the Next Greater Element for every number in nums2
    for (int num : nums2) {   
        // Current number is the Next Greater Element
        // for all smaller numbers waiting in the stack
        while (!st.empty() && num > st.top()) {
            nextGreater[st.top()] = num;
            st.pop();
        }

        // This number is now waiting for a greater number
        st.push(num);
    }

    // Create the answer for nums1
    vector<int> result;

    for (int num : nums1) {
        if (nextGreater.count(num)) {
            result.push_back(nextGreater[num]);
        } else {
            result.push_back(-1);
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {8, 2, 6, 1, 9, 3};
    vector<int> nums2 = {4, 8, 2, 1, 6, 3, 9, 5, 7, 10};

    vector<int> result = nextGreaterElement(nums1, nums2);

    for (int num: result) cout << num << " ";
    cout << endl;

    return 0;
}