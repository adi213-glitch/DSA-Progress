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
// Function for iterative postorder traversal using one stack
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::stack<TreeNode*> s;
    TreeNode* lastVisited = nullptr;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        if (current != nullptr) {
            s.push(current);
            current = current->left;
        } else {
            TreeNode* peekNode = s.top();
            // If right child exists and traversing right child is not done yet
            if (peekNode->right != nullptr && peekNode->right != lastVisited) {
                current = peekNode->right;
            } else {
                // Process the node
                std::cout << peekNode->val << " ";
                lastVisited = peekNode;
                s.pop();
            }
        }
    }
    std::cout << std::endl;
}