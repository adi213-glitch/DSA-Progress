#include <bits/stdc++.h>
using namespace std;

int slidsum(vector<int> vec,int k){
    int n =vec.size();
    int sum=0,mx=0;
    for(int i =0; i<n;i++){
        sum=0;
        for(int j =i; j<n;j++){
            sum+=vec[j];
            if(sum<=k){
                mx=max(mx,j-i+1);
            }
        }
        
    }
    return mx;
    
}