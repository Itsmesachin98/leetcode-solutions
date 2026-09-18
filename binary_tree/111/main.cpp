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

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    queue<TreeNode*> q;
    q.push(root);

    int depth = 1;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
                
            if (node->left == nullptr && node->right == nullptr) return depth;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);            
        }

        depth++;
    }

    return depth;
}

int main() {
    vector<optional<int>> arr = {3, 9, 20, nullopt, nullopt, 15, 7};

    TreeNode* root = buildBinaryTree(arr);

    cout << minDepth(root) << endl;

    return 0;
}       