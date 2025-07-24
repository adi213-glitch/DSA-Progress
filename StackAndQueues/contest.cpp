#include <bits/stdc++.h>
using namespace std;








int main(){

    int t;
    cin>>t;
    vector<string> vec(t,"0");
    for(int i=0; i<t;i++){
        cin>>vec[i];
    }
    string a= "FFT", b="NTT";
    for(int i=0; i<t; i++){
        
        int c=0;
        while(vec[i].find(a)!=string::npos  || vec[i].find(b)!=string::npos   ){
            if(vec[i].find(a)!=string::npos) c= vec[i].find(a);
            else  c= vec[i].find(b);
            char f= vec[i][c];
            vec[i].erase(c,1);
            vec[i]=vec[i]+f;

        }
    }
    for(int i=0; i<t;i++){
        cout<<vec[i]<<endl;
    }




    return 0;
}