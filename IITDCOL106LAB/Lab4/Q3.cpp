#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isalphabet(char c){
    return (islower(c) || isupper(c));
}
string decodeMessage(string& s){
    stack<pair<char,string>> st;
    st.push({'#', ""});
    int i=0, curridx=0;
    while(i<s.length()){
        if(s[i]=='[') {
            st.push({s[i+1], ""}); 
            i+=2;
            continue;
            // skip the next char coz already inserted
        }
        // s[i+1] is obviously safe since question says tag:content 
        // tag is always a single lowercase letter 
        // so after a [ there must be an alphabet
        else if(s[i]==']'){
            pair<char,string> send = st.top();
            st.pop();
            string reversedstringtoadd = "[" + string(1,send.first) + ":" + send.second + "]";
            st.top().second.append(reversedstringtoadd);
        }else if(isalphabet(s[i])) {
            string temp (1,s[i]);
            
            st.top().second.insert(0,temp);
            
        }
        // else if(s[i]==':'){
            
        // }


        i++;

    }
    return st.top().second;
    


}
int main(){
    string s= "[a:hello[b:world]]";
    cout<< decodeMessage(s);
    return 0;
}