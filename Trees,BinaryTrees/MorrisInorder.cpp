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
 
vector<int> inorderTraversal (TreeNode * root){
    vector<int> ans;
    TreeNode* curr= root;

    while(curr){
        
        if(!curr->left) {
            ans.push_back(curr->val);
            curr=curr->right;
        }else{
            
            

            TreeNode * pre = curr->left;
            while( pre->right  && pre->right !=curr){
                pre=pre->right;
               
            }
            if(!pre->right) {
                pre->right = curr;
                
                curr=curr->left;
            }
            else {
                pre->right= NULL;
                ans.push_back(curr->val);
                
                curr=curr->right;
            }
            
          
        }
    }



    return ans;
}