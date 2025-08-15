#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};
// Function for iterative preorder traversal
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();

        std::cout << current->val << " ";

        // Push right child first so that left is processed first
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
    std::cout << std::endl;
}