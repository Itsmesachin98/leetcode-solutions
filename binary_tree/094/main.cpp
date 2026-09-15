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

void helper (TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;

    helper(root->left, arr);
    arr.push_back(root->val);
    helper(root->right, arr);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> arr;

    helper(root, arr);

    return arr;
}

int main() {
    vector<optional<int>> arr = {1, nullopt, 2, 3};

    TreeNode* root = buildBinaryTree(arr);

    vector<int> result = inorderTraversal(root);

    for (int num: result) cout << num << " ";
    cout << endl;
    
    return 0;
}