#include <bits/stdc++.h>
using namespace std;

// Equivalent definition using the 'class' keyword.
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> ALLTRAVERSALS (TreeNode * root){
    if(!root) return {{},{},{}};
    stack<pair<TreeNode * ,int>> s;
    vector<int> pre,in,po;
    s.push({root,1});
    while(!s.empty()){
        switch (s.top().second){
        case 1 :
            pre.push_back(s.top().first->val);
            s.top().second ++;
            if(s.top().first->left) s.push({s.top().first->left,1});
            break;
        case 2:
            in.push_back(s.top().first->val);
            s.top().second ++;
            if(s.top().first->right) s.push({s.top().first->right,1});
            break;
        case 3:
            po.push_back(s.top().first->val);
            s.pop();
            break;

        }
    }
    return {pre, in,po};





}