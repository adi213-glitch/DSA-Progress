#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque <int> q;
        int n = nums.size(),j=0;
        
        while(j<n){
            int i=j-k+1;
            if(i>=0 &&  !q.empty() && (i-1==q.front())) q.pop_front();
            while(!q.empty() && nums[j]>=nums[q.back()]){
                q.pop_back();
            }
            q.push_back(j);
            if(i>=0) ans.push_back(nums[q.front()]);
           
            j++;
        }



        return ans;
    }
};











