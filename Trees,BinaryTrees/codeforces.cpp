#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin>> t;
    for(int T=0; T<t; T++){
        int n;
        cin>>n;
        int suma=0, sumb=0;
        vector<int> a(n), b(n);
        for(int i=0; i<n;i++) {
            cin>> a[i];
            suma+=a[i];
        }
        for(int i=0; i<n;i++) {
            cin>> b[i];
            sumb+=b[i];
        }
        int ans=0;
        
        while(true){
            ans++;
            bool firstoccur =0;
            bool secondoccur=0;
            int storefir=-1, storesec=-1;
            for(int j=0; j<n;j++){
                if(a[j]> b[j]){
                    storefir=j;
                    firstoccur=1;
                    break;
                }
            }
            for(int i=0; i<n;i++){
                if(a[i]<b[i]) {
                    storesec=i;;         
                    secondoccur =1;
                    break;
                }   
            }          
            if(firstoccur) a[storefir]--;
            if(secondoccur) a[storesec]++;
           
            if(!firstoccur) {
                break; 
            }        
        }   
        cout<< ans<<endl;
    }



    return 0;
}