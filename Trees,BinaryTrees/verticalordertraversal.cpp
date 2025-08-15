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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if (!root) return {};

        queue <pair<int,TreeNode*>> q;
        map<int, map<int, multiset<int>>> m;

        q.push({0,root});

        
        
        
        int height=0;
        while (!q.empty()) {
            int levelSize = q.size();
            
            height++;
            for (int i = 0; i < levelSize; ++i) {
                auto curr = q.front();
                q.pop();
                
                m[curr.first][height-1].insert(curr.second->val);
                
                
                if (curr.second->left) {
                    
                    q.push({curr.first-1, curr.second->left});
                    
                }
                if (curr.second->right) q.push({curr.first+1, curr.second->right});
            }

           
        }
        vector<vector<int>> result;
        int msize= m.size();
        for( auto it: m){
            vector<int> ans;
            
            for( auto mp : it.second){
                for(auto ele : mp.second){
                    ans.push_back(ele);
                }
            }
            result.push_back(ans);
        }
        return result;


    }
    
};