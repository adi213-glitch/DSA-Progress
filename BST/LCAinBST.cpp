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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        TreeNode * temp = root, *temq=root;
        bool pover=0, qover=0;
        TreeNode * lca = root;
        while( !qover || !pover){
            if(temp==temq) lca = temp;
            else return lca;
            if(!pover){
                
                if(temp->val < p->val){
                    
                    temp=temp->right;
                }else if(temp->val > p->val){
                    
                    temp=temp->left;
                }
                else pover =1;
            }
            if(!qover){
                
                if(temq->val < q->val){
                    
                    temq=temq->right;
                }else if(temq->val > q->val){
                   
                    temq=temq->left;
                }else qover =1;
            }
        }
        
        
        return lca;
    }
};