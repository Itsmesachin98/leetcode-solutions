#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();

    int left = -1;
    int right = -1;

    // Find the right boundary
    int maxSeen = INT_MIN;

    for (int i = 0; i < n; i++) {
        maxSeen = max(maxSeen, nums[i]);

        if (nums[i] < maxSeen) {
            right = i;
        }
    }

    // Find the left boundary
    int minSeen = INT_MAX;

    for (int i = n - 1; i >= 0; i--) {
        minSeen = min(minSeen, nums[i]);

        if (nums[i] > minSeen) {
            left = i;
        }
    }

    // Array is already sorted
    if (right == -1) return 0;

    return right - left + 1;
}

int main() {
    vector<int> nums = {2,6,4,8,10,9,15};

    int result = findUnsortedSubarray(nums);

    cout << result << endl;

    return 0;
}