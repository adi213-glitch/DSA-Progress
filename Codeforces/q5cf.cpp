#include <bits/stdc++.h>
using namespace std;


int main(){
    int t ;
    cin>> t;
    for(int T=0; T<t; T++){
        int n,k;
        cin>>n;
        cin>>k;
        vector<int> vec(n);
        for(int i =0; i<n;i++){
            cin>>vec[i];   
        }

        // if(k%2!=0){
        //     for(int j: vec){
        //         if(j %2!=0 ) cout<< (j+k)<<" "; 
        //         else cout<< j <<" ";
        //     }
        //     cout<<endl;
        //     continue;
        // }
        for(int j=0; j<n;j++){
            int rem = vec[j] % (k+1);
            cout<<(vec[j] + ((1LL * rem)*k)) <<" ";
        }
        cout<<endl;







       
        
    }
}