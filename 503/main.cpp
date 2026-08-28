#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<pair<int, int>> st;
    vector<int> result(n, -1);

    // Traverse the array twice to simulate a circular array
    for (int i = 0; i < 2 * n; i++) {
        int index = i % n;

        while (!st.empty() && nums[index] > st.top().first) {
            result[st.top().second] = nums[index];
            st.pop();
        }

        // Only push elements during the first traversal
        if (i < n) {
            st.push({nums[index], index});
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 1};

    vector<int> result = nextGreaterElements(nums);

    for (int num: result) cout << num << " ";
    cout << endl;

    return 0;
}