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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    
    if (root == nullptr) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        int levelSize = q.size();
        vector<int> currentLevel;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();

            currentLevel.push_back(current->val);

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }

        result.push_back(currentLevel);    
    }

    return result;
}

int main() {
    vector<optional<int>> arr = {3, 9, 20, nullopt, nullopt, 15, 7};

    TreeNode* root = buildBinaryTree(arr);

    vector<vector<int>> result = levelOrder(root);

    for (vector<int> vec: result) {
        for (int val: vec) {
            cout << val << " ";
        }

        cout << endl;
    }

    return 0;
}