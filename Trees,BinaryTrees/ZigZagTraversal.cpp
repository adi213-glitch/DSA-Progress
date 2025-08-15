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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        deque <TreeNode *> d;
        vector<vector<int>> ans;
        d.push_back(root);
        bool check=1;
        while(!d.empty()){
            vector<int> lvl;
            int sz= d.size();
            if(check){
                
                for(int i=0; i<sz;i++){
                    TreeNode * temp= d.back();
                    if(temp->left) d.push_front(temp->left);
                    if(temp->right) d.push_front(temp->right);
                    lvl.push_back(temp->val);
                    d.pop_back();
                }
                check=0;
                ans.push_back(lvl);
                
            }else{
                for(int i=0; i<sz;i++){
                    TreeNode * temp= d.front();
                    if(temp->right) d.push_back(temp->right);
                    if(temp->left) d.push_back(temp->left);
                    
                    lvl.push_back(temp->val);
                    d.pop_front();
                }
                check=1;
                ans.push_back(lvl);
            }
        }
        return ans;
    }
};