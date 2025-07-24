#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size() , count0= 0,l=0,count=0,mxcount=0;
        for(int r=0; r<n;r++){
            if(nums[r]==0) count0++ ;
            if(count0>k){
                if(nums[l]==0) count0--   ;
                l++;
            }
            mxcount = max(mxcount , r-l+1);




        }
        return mxcount;
    }
};