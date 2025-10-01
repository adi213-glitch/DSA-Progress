#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int minCost(vector<int> a){
    int  n = a.size();
    if(n<3) return -1;
    sort(a.begin(),a.end());
    int ans= INT64_MAX;
    for(int i =0; i<=n-3; i++){
        ans=min(ans, a[i+2]-a[i]);
    }
    return ans;   

    
}