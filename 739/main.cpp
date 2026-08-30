#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    
    stack<int> st;
    vector<int> result(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
            st.pop();
        }

        if (!st.empty()) {
            result[i] = st.top() - i;
        }

        st.push(i);
    }

    return result;
}

int main() {
    vector<int> temperatures = {89,62,70,58,47,47,46,76,100,70};

    vector<int> result = dailyTemperatures(temperatures);

    for (int num: result) cout << num << " ";
    cout << endl;

    return 0;
}