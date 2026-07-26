#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return 1;

    sort(nums.begin(), nums.end());

    int ans = 0;
    int cnt = 1;

    int i = 0, j = 1;
    while (j < nums.size()) {
        if (nums[i]+1 == nums[j]) {
            cnt++, i++, j++;
        } else if (nums[i] == nums[j]) {
            i++, j++;
        } else {
            ans = max(ans, cnt);
            cnt = 1;
            i++, j++;
        };
    }

    ans = max(ans, cnt);

    cout << ans << endl;

    return ans;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    longestConsecutive(nums);
    return 0;
}

