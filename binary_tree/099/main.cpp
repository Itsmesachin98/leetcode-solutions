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

void inOrderTraversal(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;

    inOrderTraversal(root->left, arr);
    arr.push_back(root->val);
    inOrderTraversal(root->right, arr);
}

void helper(TreeNode* root, vector<int>& arr, int& idx) {
    if (root == nullptr) return;

    helper(root->left, arr, idx);

    root->val = (arr[idx]);
    idx++;

    helper(root->right, arr, idx);
}

void recoverTree(TreeNode* root) {
    vector<int> arr;
    int idx = 0;

    inOrderTraversal(root, arr);

    sort(arr.begin(), arr.end());

    helper(root, arr, idx);
}

int main() {
    vector<optional<int>> arr = {3, 1, 4, nullopt, nullopt, 2};

    TreeNode* root = buildBinaryTree(arr);

    recoverTree(root);

    return 0;
}