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
 
bool checkifmaxheap (TreeNode * root){
    if(!root) return 1;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i=0; i<sz;i++){
            TreeNode * curr = q.front();
            q.pop();
            if(curr->left  && curr->right){
                if(curr->val >= max(curr->left->val, curr->right->val)){
                    q.push(curr->left);
                    q.push(curr->right);
                }else return 0;
            }else if(curr->left){
                if(curr->val >= curr->left->val){
                    q.push(curr->left);
                }else return 0;
            }else if(curr->right) return 0;
        }
    }


    return 1;

}