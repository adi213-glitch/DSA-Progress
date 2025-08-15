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
    vector<int> leftSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return {};

        queue <TreeNode*> q;
       

        q.push(root);

        
        
        int store=root->val;
        int height=0;
        while (!q.empty()) {
            int levelSize = q.size();
            store= q.front()->val;
            height++;
            for (int i = 0; i < levelSize; ++i) {
                auto curr = q.front();
                q.pop();
                
                
                
                
                if (curr->left) q.push( curr->left);             
                if (curr->right) q.push( curr->right);
            }
            ans.push_back(store);

           
        }
        
        
        
        return ans;


    }
    
};