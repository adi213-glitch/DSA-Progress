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
    vector<int> verticalTraversal(TreeNode* root) {
        
        if (!root) return {};

        queue <pair<int,TreeNode*>> q;
        map<int, int> m;

        q.push({0,root});

        
        
        
        
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                auto curr = q.front();
                q.pop();
                if(m.find(curr.first)  ==m.end()){
                    m[curr.first]=(curr.second->val);
                }
                
                
                
                if (curr.second->left) {
                    
                    q.push({curr.first-1, curr.second->left});
                    
                }
                if (curr.second->right) q.push({curr.first+1, curr.second->right});
            }

           
        }
        vector <int> result;
       
        for( auto it: m){
            result.push_back(it.second);
        }
        return result;


    }
    
};