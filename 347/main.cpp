#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    unordered_map<int, int> um;
    
    for (int i = 0; i < nums.size(); i++) {
        um[nums[i]]++;
    }
    
    vector<pair<int, int>> pairs(um.begin(), um.end());

    sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    
    for (int i = 0; i < k; i++) {
        result.push_back(pairs[i].first);
    }

    return result;
}

int main() {
    vector<int> nums = {4, 4, 6, 6, 5, 5, 1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);

    for (int num: result) cout << num << " ";
    cout << endl;

    return 0;
}