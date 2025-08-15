
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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
    
        queue<pair<TreeNode *,long long>> q;
        q.push({root,0});
        long long ans=0;
        
        while(!q.empty()){
            int levelsize = q.size();
           
            long long first=-1, second=-1;
            // bool check =0;
            for(long long i=0 ; i<levelsize; i++){              
                TreeNode * fro = q.front().first;
                long long temp= q.front().second;
                q.pop();
                if(i==0){
                    first=temp;
                }
                if(i==levelsize-1) second =temp; 
                
                if(fro->left) {
                    q.push({fro->left,2*(temp-first) +1 });  
                }
                if(fro->right) {
                    q.push({fro ->right,2*(temp-first)+2});
                    
                }
                
                 
            }
            
            ans= max(ans,1LL *(second-first+1));
            
           
            
        }
        
        return ans;
    }
};