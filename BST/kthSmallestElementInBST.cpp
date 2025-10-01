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
    void helper( TreeNode * root, int & count, int k,int &ans){
        if(!root) return;
        // else if(count ==k) {
        //     ans = root->val;
        //     return;
        // }
        helper(root->left,count,k,ans);
        if(count!=k){
            count++;
            if(count ==k) {
                ans = root->val;
                return;
            }
            helper(root->right,count,k,ans);
        } 
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans =0;
        int count =0;
        helper(root,count,k,ans);
        return ans;
    }
};