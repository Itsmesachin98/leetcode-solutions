#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    int frequency[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        frequency[s[i] - 'a']++;
        frequency[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (frequency[i] != 0) return false;
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    cout << isAnagram(s, t) << endl;

    return 0;
}