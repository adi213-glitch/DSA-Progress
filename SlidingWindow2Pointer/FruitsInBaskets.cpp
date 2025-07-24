#include <bits/stdc++.h>
using namespace std;

int fruitinbasket (vector<int> vec){
    int n =vec.size(),maxlen=0;
    
    for(int i=0; i<n;i++){
        unordered_set<int> s;
        for(int j=i;j<n;j++){
            s.insert(vec[j]);
            if(s.size()>2){
                break;
            }            
            maxlen=max(maxlen, j-i+1);
        }
    }
    return maxlen;
}

int main(){





    return 0;
}