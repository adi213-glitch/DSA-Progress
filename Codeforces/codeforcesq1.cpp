#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; 
    cin>>t;
    for(int i=0; i<t; i++){
        int n; 
        cin>>n;
        string a;
        cin >> a;
        int m; 
        cin>>m;
        string b;
        cin >> b;
        string c;
        cin>>c;
        queue<pair<char,char>> q;
        for(int i =0 ; i<m; i++){
            q.push({b[i],c[i]});
        }
        while(!q.empty()){
            pair<char,char> curr = q.front();
            q.pop();
            string temp (1,curr.first);
            if(curr.second=='V') a.insert(0,temp);
            else a.push_back(curr.first);
        }
        cout<< a<<endl;







    }




    return 0;
}
