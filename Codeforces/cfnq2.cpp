#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin>> t;
    for(int T=0; T<t; T++){
        int n,k;
        cin>>n;
        cin>>k;
        
        string s;
        cin>>s;
        vector<int> p(n);

        int count =1;
        for(int i =0 ; i< n; i++){
            if(s[i]=='1') p[i]=count++;
        }
        for(int i =0 ; i< n; i++){
            if(s[i]=='0') p[i]=count++;
        }
        bool movnext=0;
        for(int i =0; i<n;i++){
            if(s[i]=='1'){
                int q=i;
                bool check=0;
                if(i-k+1>=0){
                    while ( q>= i-k+1){
                        if(s[q]=='0' ){
                            check=1;
                            break;
                        }
                        q--;
                    }
                }else{
                    check=1;
                }
                if(check) continue;
                else {
                    cout<<"NO"<<endl;
                    movnext=1;
                    break;
                }
            }
        }
        if(movnext) continue;
        else {
            cout<<"YES"<<endl;
            for(int j : p) cout<< j<<" ";

            cout<<endl;
        }

    }
}

