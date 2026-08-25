#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    stack<pair<int, int>> st;

    int n = matrix.size();
    int m = matrix[0].size();

    // First, find and store the positions of all original zeros so that
    // changing elements later doesn't create new zeros that we accidentally process.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) st.push({i, j});
        }
    }

    while (!st.empty()) {
        int first = st.top().first;
        int second = st.top().second;

        // Set every element in the column containing the original zero to zero.
        for (int i = 0; i < n; i++) matrix[i][second] = 0;

        // Set every element in the row containing the original zero to zero.
        for (int j = 0; j < m; j++) matrix[first][j] = 0;

        st.pop();
    }
}

int main() {
    vector<vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};

    setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        } cout << endl;
    }

    return 0;
}