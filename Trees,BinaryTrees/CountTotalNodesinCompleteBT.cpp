
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
    int height(TreeNode * root , char s){
        if(!root) return 0;
        if(s == 'l'){
            return 1+height(root->left, 'l');
        }else {
            return 1+height(root->right, 'r');
        }
    }
    int countNodes(TreeNode* root) {
        if(! root) return 0;


        int lh = height(root,'l');
        int rh= height(root,'r');
        if(lh == rh) return (pow(2, lh)-1);
        return 1+ countNodes(root->left) + countNodes(root->right);
         


    }
};