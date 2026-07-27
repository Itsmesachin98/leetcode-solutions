#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    string ans = "";

    for (char c: s) {
        if(isalnum(c)) {
            ans += tolower(c);
        }
    }

    int i = 0, j = ans.size() - 1;
    while (i < j) {
        if (ans[i] != ans[j]) return false;
        i++, j--;
    }

    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    isPalindrome(s);
    return 0;
}