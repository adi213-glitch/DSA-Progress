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


void changetree (TreeNode * root){
    if(!root  ) return;
    int temp =((root->left)? root->left->val :0)  + ((root->right)? root->right->val :0);
    
    if(root->val > temp){
        if(root->left) root->left->val =root->val;
        if(root->right) root->right->val =root->val;
    }else if(root->val < temp){
        root->val= temp;
    }
    
    
    changetree(root->left);
    changetree(root->right);
    root->val= ((root->left)? root->left->val :0)  + ((root->right)? root->right->val :0) ;
    
}