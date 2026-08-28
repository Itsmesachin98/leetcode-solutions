#include <bits/stdc++.h>
using namespace std;

int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    vector<int> st;

    for (int i = 0; i < n; i++) {
        if (st.empty() || nums[i] < nums[st.back()]) {
            st.push_back(i);
        }
    }

    int maxWidth = 0;

    for (int j = n - 1; j >= 0; j--) {
        while (!st.empty() && nums[st.back()] <= nums[j]) {
            maxWidth = max(maxWidth, j - st.back());
            st.pop_back();
        }
    }

    return maxWidth;
}

int main() {
    vector<int> nums = {6,0,8,2,1,5};

    int result = maxWidthRamp(nums);

    cout << result << endl;

    return 0;
}