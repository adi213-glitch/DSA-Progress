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
    int helper ( TreeNode * root){
        if(!root ) return 0;
        int hl = helper(root->left ),hr = helper(root->right);
        if(hl==-1 || hr==-1) return -1;
        
        if(!(abs((hl-hr)) <=1) ) return -1;
        
        int ans = 1+ max(hl,hr);
        
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return (helper(root)==-1)? 0 : 1;
    }
};