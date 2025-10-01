#include <bits/stdc++.h>
using namespace std;
bool even(int n){
    return (n%2==0) ;
}
string helper(int n, int a, int b){
    if(!even(n)){
        if(!even(b) && ((a<=b)  || !even(a))  ) {
            return "YES";
        }
        // else if(even(b)){
        //     return "NO";
        // }
    }else{
        if( (even(b)  )  && ( a<=b    ||  even(a))) return "YES";
    }

    


    return "NO";




}
int main(){
    int t ;
    cin>> t;
    for(int T=0; T<t; T++){
        int n,a,b;
        cin>>n;
        cin>>a;
        cin>>b;
        cout<<helper(n,a,b)<< endl;
    }
}