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

bool helper(TreeNode* p, TreeNode* q, bool& result) {
    if (!result)
        return false;

    if (p == nullptr && q == nullptr)
        return true;

    if (p == nullptr || q == nullptr) {
        result = false;
        return false;
    }

    if (p->val != q->val) {
        result = false;
        return false;
    }

    helper(p->left, q->left, result);
    helper(p->right, q->right, result);

    return result;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    bool result = true;

    helper(p, q, result);

    return result;
}

int main() {
    vector<optional<int>> p = {1, 2};
    vector<optional<int>> q = {1, nullopt, 2};

    TreeNode* rootP = buildBinaryTree(p);
    TreeNode* rootQ = buildBinaryTree(q);

    cout << isSameTree(rootP, rootQ) << endl;

    return 0;
}