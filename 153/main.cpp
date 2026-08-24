#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    vector<int> nums = {2, 3, -2, 4};
    cout << findMin(nums) << endl;
    return 0;
}