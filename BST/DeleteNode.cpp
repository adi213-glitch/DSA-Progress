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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode* dummy = new TreeNode(-1,NULL,root);
        TreeNode* temp = NULL, * parent = dummy;
        while(parent->left || parent->right){
            if(parent == dummy || parent->val <key){
                if(parent->right && parent ->right->val == key){
                    temp = parent->right;
                    break;
                }
                parent = parent ->right;
            }else{
                if(parent->left && parent ->left->val == key){
                    temp = parent ->left;
                    break;
                }
                parent=parent->left;
            }
        }
        if(temp){
            if(temp->left && !temp->right){
                if(parent ->left == temp) parent ->left = temp->left;
                else parent ->right = temp->left;
            }else if(!temp->left && temp->right){
                if(parent ->left == temp) parent ->left = temp->right;
                else parent ->right = temp->right;
            }else if(temp->left && temp->right){
                TreeNode* travel = temp->right;
                while(travel->left) travel = travel ->left;
                travel->left= temp->left;
                temp->left =NULL;
                 
                if(parent->left==temp){
                    parent ->left = temp->right;
                }else{
                    parent->right = temp->right;
                }
            }else {
                if(parent ->left == temp) parent ->left =NULL;
                else parent ->right = NULL;
            }
            delete temp;
        }
        TreeNode* ans = dummy ->right;
        delete dummy;
        return ans;




    }

};