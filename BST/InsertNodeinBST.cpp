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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * temp = root, *store =NULL;
        
        while(temp){
            if(temp->val <= val ){
                store = temp;
                temp = temp->right;
                
            }else {
                temp=temp->left;
            }
                
        }
        TreeNode * n = new TreeNode (val);
        if(store){
            TreeNode * righ = store ->right;
            store ->right = n;
            n->right = righ;
            return root;
        }else{
            n->right = root;
            return n;
        }
        return NULL;

    }
};