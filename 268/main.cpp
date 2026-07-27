#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    if (n == 1) {
        if (nums[0] == 1) return 0;
        else return 1;
    }

    sort(nums.begin(), nums.end());

    if (nums[0] != 0) return 0;

    int i = 0, j = 1;
    while (j < n) {
        if (nums[i] + 1 != nums[j]) {
            ans = nums[i] + 1;
            break;
        }

        i++, j++;
    }

    if (ans == 0) ans = nums[n-1] + 1;

    return ans;
}

int main() {
    vector<int> nums = {1};
    cout << missingNumber(nums) << endl;
    return 0;
}