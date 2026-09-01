#include <bits/stdc++.h>
using namespace std;

int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();

    int left = 0;

    // Find sorted prefix
    while (left + 1 < n && arr[left] <= arr[left + 1]) left++;

    // Already sorted
    if (left == n - 1) return 0;

    int right = n - 1;

    // Find sorted suffix
    while (right > 0 && arr[right - 1] <= arr[right]) right--;

    // Option 1:
    // Remove everything after the prefix
    int ans = n - left - 1;

    // Option 2:
    // Remove everything before the suffix
    ans = min(ans, right);

    // Option 3:
    // Connect prefix and suffix
    int i = 0;
    int j = right;

    while (i <= left && j < n) {

        if (arr[i] <= arr[j]) {
            // Remove elements between i and j
            ans = min(ans, j - i - 1);
            i++;
        }
        else {
            // arr[i] is too large,
            // so try a larger suffix element
            j++;
        }
    }

    return ans;
}

int main() {
    vector<int> arr =  {17,32,32,29,4,29,19,5,26,35,35,6,10,27,11,35,0,31};

    int result = findLengthOfShortestSubarray(arr);

    cout << result << endl;

    return 0;
}