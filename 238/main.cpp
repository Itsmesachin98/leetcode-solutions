#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();

    // If there are more than one zero in nums, every answer will remain 0.
    vector<int> result(n, 0);

    int totalZeros = 0;
    int product = 1;

    // Calculate the product of all non-zero numbers and count the zeros.
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            totalZeros++;

            // If there are two or more zeros, every product except self
            // will still contain at least one zero, so all answers are 0.
            if (totalZeros > 1) return result;
        } else product *= nums[i];
    }

    // Build the result array based on whether the input contains a zero.
    for (int i = 0; i < nums.size(); i++) {
        if (totalZeros && nums[i] == 0) result[i] = product;
        else if (totalZeros && nums[i] != 0) result[i] = 0;
        else result[i] = product / nums[i];
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 0, 4};

    vector<int> result = productExceptSelf(nums);

    for (int num: result) cout << num << " ";
    cout << endl;

    return 0;
}