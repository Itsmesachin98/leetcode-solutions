#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    int ans = -1;

    while(i < j) {
        if (nums[i] == target) return i;
        if (nums[j] == target) return j;

        i++, j--;
    }

    if (i == j && nums[i] == target) return i;
    
    return ans;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 8;

    cout << search(nums, target) << endl;
    return 0;
}