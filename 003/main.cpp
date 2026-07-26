#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> v(128, 0);

    int ans = 0;
    int i = 0, j = 0;

    while (j < s.size()) {

        while (v[s[j]]) {
            v[s[i]]--;
            i++;
        }

        v[s[j]]++;
        ans = max(ans, j - i + 1);
        j++;
    }

    cout << ans << endl;

    return ans;
}

int main() {
    string s = "pwwkew";
    lengthOfLongestSubstring(s);
    return 0;
}