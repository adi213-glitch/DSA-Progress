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
 
void flatten (TreeNode * root){
        TreeNode * dummy = new TreeNode(-1,NULL,root);

        TreeNode* curr= root;
        TreeNode* temp= dummy;

        while(curr){
            
            temp->right = curr;
            temp=curr;
            if(!curr->left) {
                curr=curr->right;
            }else{
                
                

                TreeNode * pre = curr->left;
                while( pre->right  ){
                    pre=pre->right;
                
                }
                if(!pre->right) {
                    pre->right = curr->right;
                    
                    curr=curr->left;
                    temp->left=NULL;
                }
                
                
            
            }
        }



        
}