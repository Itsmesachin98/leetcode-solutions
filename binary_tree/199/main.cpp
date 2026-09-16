#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* buildBinaryTree(vector<optional<int>>& arr) {

    if (arr.empty() || !arr[0].has_value())
        return nullptr;

    TreeNode* root = new TreeNode(arr[0].value());

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {

        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i].has_value()) {
            current->left = new TreeNode(arr[i].value());
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i].has_value()) {
            current->right = new TreeNode(arr[i].value());
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void helper(TreeNode* root, int level, vector<int> result) {
    if (root == nullptr) return;

    if (level == result.size()) result.push_back(root->val);

    helper(root->right, level+1, result);
    helper(root->left, level+1, result);
}


vector<int> rightSideView(TreeNode* root) {
    if (root == nullptr) return {};

    vector<int> result;
    int level = 0;

    helper(root, level, result);

    return result;
}

int main() {
    vector<optional<int>> arr = {3, 9, 20, nullopt, nullopt, 15, 7};

    TreeNode* root = buildBinaryTree(arr);

    vector<int> result = rightSideView(root);

    for (int num: result) cout << num << " ";
    cout << endl;

    return 0;
}