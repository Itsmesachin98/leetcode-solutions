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

void preorderTraversal(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;

    arr.push_back(root->val);
    preorderTraversal(root->left, arr);
    preorderTraversal(root->right, arr);
}

void inorderTraversal (TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;

    inorderTraversal(root->left, arr);
    arr.push_back(root->val);
    inorderTraversal(root->right, arr);
}

void postorderTraversal(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) return;

    postorderTraversal(root->left, arr);
    postorderTraversal(root->right, arr);
    arr.push_back(root->val);
}

int main() {
    vector<optional<int>> arr = {1, 2, 3, 4, 5, nullopt, 8, nullopt, nullopt, 6, 7, 9};

    TreeNode* root = buildBinaryTree(arr);

    vector<int> preorderArr;
    vector<int> inorderArr;
    vector<int> postorderArr;

    preorderTraversal(root, preorderArr);
    inorderTraversal(root, inorderArr);
    postorderTraversal(root, postorderArr);
    
    cout << "Preorder: ";
    for (int arr: preorderArr)  cout << arr << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int arr: inorderArr) cout << arr << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int arr: postorderArr) cout << arr << " ";
    cout << endl;

    return 0;
}