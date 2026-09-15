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

void levelOrderTraversal(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        TreeNode* current = q.front();
        q.pop();

        arr.push_back(current->val);

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

int main() {
    vector<optional<int>> arr = {1, 2, 3, 4, 5, nullopt, 8, nullopt, nullopt, 6, 7, 9};

    TreeNode* root = buildBinaryTree(arr);

    vector<int> levelOrderArr;

    levelOrderTraversal(root, levelOrderArr);
    
    cout << "Levelorder: ";
    for (int arr: levelOrderArr)  cout << arr << " ";
    cout << endl;

    return 0;
}