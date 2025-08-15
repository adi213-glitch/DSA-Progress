#include <bits/stdc++.h>
using namespace std;

int fruitinbasket (vector<int> vec){
    int n =vec.size(),l=0, maxlen=0;
    unordered_map<int,int> s;
    for(int r=0; r<n;r++){
        
        s[vec[r]]++;
        
        if(s.size()>2){
            s[vec[l]]--;
            if(s[vec[l]]==0) s.erase(vec[l]);
            l++;
        }else{            
            maxlen=max(maxlen, r-l+1);
        }
    }
    
    return maxlen;
}

int main(){





    return 0;
}