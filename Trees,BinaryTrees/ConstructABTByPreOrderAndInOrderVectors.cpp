
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
    TreeNode * helper(vector<int> &preorder,int & pre, int is, int ie, unordered_map<int,int> &inorder){
        if(ie<is) return NULL;
        int it = inorder[(preorder[pre])];
        TreeNode * root = new TreeNode (preorder[pre]);
        pre++;
        root->left = helper(preorder, pre, is, it - 1, inorder);
        root->right = helper(preorder, pre, it + 1, ie, inorder);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        int n = inorder.size();
        for(int i=0; i<n;i++){
            m[inorder[i]]=i;
        }
        int pre=0;


        return helper(preorder,pre,0,n-1, m);
    }
};