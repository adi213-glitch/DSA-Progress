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
 
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root== p) return p;
        if(root == q) return q;
        TreeNode * left =  lowestCommonAncestor(root->left, p,q);
        TreeNode * right =  lowestCommonAncestor(root->right, p,q);
        if(!left && !right) return NULL;
        if(left && !right) return left;
        if (!left && right) return right;
        return root;


    }
};