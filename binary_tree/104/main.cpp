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

void helper(TreeNode* root, int level, int& maxLevel) {
    if (root == nullptr) return;

    level++;
    maxLevel = max(maxLevel, level);

    helper(root->left, level, maxLevel);
    helper(root->right, level, maxLevel);
}

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int level = 0;
    int maxLevel = INT_MIN;

    helper(root, level, maxLevel);

    return maxLevel;
}

int main() {
    vector<optional<int>> arr = {3, 9, 20, nullopt, nullopt, 15, 7};

    TreeNode* root = buildBinaryTree(arr);

    cout << maxDepth(root) << endl;

    return 0;
}       