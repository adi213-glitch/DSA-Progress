#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin>> t;
    for(int T=0; T<t; T++){
        int n;
        cin>>n;
        vector<int> teeth(n);
        for(int i =0; i<n;i++)  cin>>teeth[i];

        int curr= teeth[0];

        sort(teeth.begin(), teeth.end());

        bool found =0;
        for(int i=1; i<n;i++){
            if(teeth[i]==teeth[i-1]) {
                cout<<"YES"<<endl;
                found=1;
                break;
            }
        }
        if(!found) cout<<"NO"<<endl;





    }
}