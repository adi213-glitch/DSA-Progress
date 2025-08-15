// Equivalent definition using the 'class' keyword.
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
// Function for iterative inorder traversal
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        // Reach the left most Node of the current Node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Current must be nullptr at this point
        current = s.top();
        s.pop();

        std::cout << current->val << " ";

        // We have visited the node and its left subtree. Now, it's right subtree's turn
        current = current->right;
    }
    std::cout << std::endl;
}