#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> ordered_nums;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        ordered_nums.push_back({nums[i], i});
    }

    sort(ordered_nums.begin(), ordered_nums.end());

    int i = 0; int j = nums.size() - 1;
    while (i < j) {
        if (ordered_nums[i].first + ordered_nums[j].first > target) j--;
        else if (ordered_nums[i].first + ordered_nums[j].first < target) i++;
        else {
            ans = {ordered_nums[i].second, ordered_nums[j].second};
            break;
        }
    }

    cout << ans[0] << " " << ans[1] << endl;

    return ans;
}

int main() {
    vector<int> nums = {2,7,11,15}; 
    int target = 9;
    twoSum(nums, target);
    return 0;
}