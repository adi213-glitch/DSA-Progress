
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
    TreeNode * helper(vector<int> &postorder,int postst,int postend, int inst, int inend, unordered_map<int,int> &inorder){

        if(postst>postend || inst> inend) return NULL;
        int it = inorder[(postorder[postend])];
        int midele = it - inst;
        TreeNode * root = new TreeNode (postorder[postend]);
       
        root->left = helper(postorder,postst, postst+midele-1, inst,it-1 , inorder);
        root->right = helper(postorder, postst+midele, postend-1,it+1,inend , inorder);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        int n = inorder.size();
        for(int i=0; i<n;i++){
            m[inorder[i]]=i;
        }
       


        return helper(postorder,0,n-1,0,n-1, m);
    }
};