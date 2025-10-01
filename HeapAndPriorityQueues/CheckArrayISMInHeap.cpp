#include <bits/stdc++.h>
using namespace std;

bool checkifminheap (vector<int> & nums){
    int n = nums.size();
    bool check =1;
    for(int i = (n/2) -1   ; i>=0; i--){
        int lc = 2*i +1, rc= lc+1;
        if(lc<n   &&   nums[lc]<nums[i]  )  check =0;
        if( rc< n &&  nums [rc] < nums[i]) check =0;
        if(!check) break; 
    }
    return check;
}