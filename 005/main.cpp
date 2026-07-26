#include <bits/stdc++.h>
using namespace std;


void expand(const string &s, int left, int right, int &st, int &max_len) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        if (right - left + 1 > max_len) {
            st = left;
            max_len = right - left + 1;
        }

        left--;
        right++;
    }
}

string longestPalindrome(string s) {
    int st = 0;
    int max_len = 1;

    for (int i = 0; i < s.size(); i++) {
        expand(s, i, i, st, max_len);
        expand(s, i, i + 1, st, max_len);
    }

    cout << s.substr(st, max_len) << endl;

    return s.substr(st, max_len);
}

int main() {
    string s = "babad";
    longestPalindrome(s);
    return 0;
}