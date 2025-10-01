#include <bits/stdc++.h>
using namespace std;

string expander(string &s){
    
    int curr=0;
    string ans="";
    string currstr="";
    stack<pair<int,string>> st;
    int i=0; 
    st.push({1,""});

    while(i<s.length()){
        if(s[i]==':') {
            st.top().first = curr;
            curr = 0; // Reset number parser.
            
        }
        else if(isdigit  (s[i])){    
            curr*=10;
            curr += (s[i]-'0');
        }
        else if (islower(s[i]) || isupper(s[i])) st.top().second.push_back(s[i]);
        
        else if(s[i]=='['){
            st.push({0, ""}); 
            // placeholder
            curr=0; 
        }
        else if(s[i]==']') {
            pair<int,string> p=st.top();
            st.pop();
            string temp =p.second;
            for(int j=0; j<p.first;j++){
                st.top().second.append(temp);
            }
        }
        i++;
        
    }
    

    return st.top().second;
   
    


}

