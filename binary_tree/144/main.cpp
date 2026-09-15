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

void preOrderTraversal(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;

    arr.push_back(root->val);
    preOrderTraversal(root->left, arr);
    preOrderTraversal(root->right, arr);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    preOrderTraversal(root, ans);

    return ans;
}

int main() {
    vector<optional<int>> arr = {1, 2, 3, 4, 5, nullopt, 8, nullopt, nullopt, 6, 7, 9};

    TreeNode* root = buildBinaryTree(arr);

    vector<int> result = preorderTraversal(root);

    for (int num: result) cout << num << " ";
    cout << endl;

    return 0;
}