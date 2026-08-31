#include <bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    stack<int> st;
    vector<int> result(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && prices[st.top()] > prices[i]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = prices[i] - prices[st.top()];
        } else {
            result[i] = prices[i];
        }

        st.push(i);
    }

    return result;
}

int main() {
    vector<int> prices = {8,4,6,2,3};

    vector<int> result = finalPrices(prices);

    for (int num: result) cout << num << " ";
    cout << endl;

    return 0;
}