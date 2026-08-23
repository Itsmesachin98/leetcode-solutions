#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    
    for (int i = 0; i < nums.size() - 2; i++) {
        // Skip duplicate values for the first number
        if (i > 0 && nums[i] == nums[i-1]) continue;

        int left = i + 1;
        int right =  nums.size() - 1;

        // Find two numbers that, together with nums[i], sum to 0
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0) left++; 
            else if (sum > 0) right--; 
            else {
                // Found a valid triplet
                result.push_back({nums[i], nums[left], nums[right]});

                // Move both pointers
                left++, right--;

                // Skip duplicate values on the left
                while (left < right && nums[left] == nums[left - 1]) left++;

                // Skip duplicate values on the right
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
        }
    }
    
    return result;
}

int main () {
    vector<int> nums = {1, 2, 0, 1, 0, 0 , 0, 0};

    vector<vector<int>> result = threeSum(nums);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        } cout << endl;
    }

    return 0;
}