#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    vector<int> vc;

    // Process every digit
    for (char ch : num) {
        int digit = ch - '0';

        // Remove larger previous digits while possible
        while (k > 0 && !vc.empty() && digit < vc.back()) {
            vc.pop_back();
            k--;
        }

        vc.push_back(digit);
    }

    // If k is still greater than 0, remove digits from the end
    while (k > 0 && !vc.empty()) {
        vc.pop_back();
        k--;
    }

    // Remove leading zeros
    int j = 0;
    while (j < vc.size() && vc[j] == 0) {
        j++;
    }

    // Build the result
    string result;
    while (j < vc.size()) {
        result += vc[j] + '0';
        j++;
    }

    // If everything was removed or only zeros remain
    return result.empty() ? "0" : result;
}

int main() {
    string num = "10200";
    int k = 1;

    string result = removeKdigits(num, k);
    cout << result << endl;

    return 0;
}