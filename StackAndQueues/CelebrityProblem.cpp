#include <bits/stdc++.h>
using namespace std;



int celeb(vector<vector<int>> mat){
    int n = mat.size();
    int a =0 , b=n-1;
    while(b>a){
        if(mat[a][b]==0) b--;
        else a++;
    }
    bool ans=true;
    for(int i=0;i<n;i++){
        if(mat[a][i]==1){
            ans=false;
            break;
        }
    }
    if(ans){
        for(int i=0;i<n;i++){
            if(a==i) continue;
            if(mat[i][a]==0) {
                ans=false;
                return -1;
            }
        }
    }
    return a;



    
    
}











int main(){
    int n;
    cin>> n;
    cout<<n;
    ;


    return 0;
}