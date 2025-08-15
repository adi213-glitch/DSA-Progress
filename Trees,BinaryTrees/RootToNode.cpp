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
 
void helper(TreeNode * root,int node, vector<int> &ans, bool &check){
    
        if(!root) return;
        if(root->val== node) {
            ans.push_back(node);
            check=1;
            return;
        }
        
        ans.push_back(root->val);
        if(!check){
            helper(root->left, node, ans,check);
            
            helper(root->right, node, ans,check);
        }
        if(!check) ans.pop_back();
    }


vector<int> RoottoNode(TreeNode * root, int node){
    vector<int> ans;
    bool check=0;
    helper(root,node, ans,check);
    return ans;
}