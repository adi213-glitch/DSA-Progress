#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin>> t;
    for(int T=0; T<t; T++){
        int a,b,c,d;
        cin>>a;
        cin>>b;
        cin>>c;
        cin>>d;
        
        int bigger = max(a,b);
        
        if(bigger %2==1) bigger++;
        int maxpossiblesmaller = (bigger /2 ) -1;
        
        if(  (maxpossiblesmaller >=0)  &&(maxpossiblesmaller > min(a,b))) {
            cout<<"NO"<<endl;
            continue;
        }

        int nc= c-a;
        int nd= d-b;
        int nbigger= max(nc,nd);
        if(nbigger%2 ==1) nbigger++;
        int maxpossiblensmaller = (nbigger /2 ) -1;
        if(maxpossiblensmaller<0) { 
            cout<<"YES"<<endl; 
            continue;
        }
        else if((maxpossiblensmaller > min(nc,nd))) {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;








    }
}
