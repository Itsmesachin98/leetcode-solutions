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

TreeNode* buildTree(vector<optional<int>>& arr) {

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

bool isValidBST(TreeNode* root) {
    vector<int> arr;

    inOrderTraversal(root, arr);

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= arr[i-1]) return false;
    }

    return true;
}

int main() {
    vector<optional<int>> arr = {5, 1, 4, nullopt, nullopt, 3, 6};

    TreeNode* root = buildTree(arr);

    cout << isValidBST(root) << endl;

    return 0;
}