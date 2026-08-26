#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {
    int result = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
        if (i == maxi) result++;
    }

    return result;
}

int main() {
    vector<int> arr = {2, 1, 0, 3, 5, 4};

    int result = maxChunksToSorted(arr);

    cout << result << endl;

    return 0;
}