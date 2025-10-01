#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

bool helper(TreeNode* root, int lower, int upper){
    if(!root) return 1;

    if(lower <root->val  && root->val < upper) {
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
    return 0;

}
bool validateBST(TreeNode * root){
    return helper(root, INT_MIN, INT_MAX);
}