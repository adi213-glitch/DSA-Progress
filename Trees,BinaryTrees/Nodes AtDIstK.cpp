
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (!root) return {};

        // Step 1: Build parent map with BFS
        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        q.push(root);
        parentMap[root] = nullptr;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }

        // Step 2: BFS from target node to find nodes at distance k
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(target);
        visited.insert(target);

        int dist = 0;
        while (!bfsQueue.empty()) {
            int size = bfsQueue.size();
            if (dist == k) {
                vector<int> ans;
                while (!bfsQueue.empty()) {
                    ans.push_back(bfsQueue.front()->val);
                    bfsQueue.pop();
                }
                return ans;
            }
            for (int i = 0; i < size; i++) {
                TreeNode* curr = bfsQueue.front();
                bfsQueue.pop();

                // Explore neighbors: left, right, parent
                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left);
                    bfsQueue.push(curr->left);
                }
                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right);
                    bfsQueue.push(curr->right);
                }
                TreeNode* par = parentMap[curr];
                if (par && !visited.count(par)) {
                    visited.insert(par);
                    bfsQueue.push(par);
                }
            }
            dist++;
        }

        return {};  // if no nodes found at distance k
    }
};
