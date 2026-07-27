#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int ans = 0;

    while (i < j) {
        int water = min(height[i], height[j]) * (j - i);
        ans = max(ans, water);
        
        if (height[i] < height[j]) i++;
        else j--;
    }

    cout << ans << endl;
    return ans;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    maxArea(height);
    return 0;
}