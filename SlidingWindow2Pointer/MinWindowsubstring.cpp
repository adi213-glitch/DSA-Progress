#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    void insertchar(int arr[], char c){
        if(isupper(c)) arr[c-'A'+26]++;
        else arr[c-'a']++;
    }
    bool isvalid( int mt[], int ms[]){
        for(int k=0; k<52; k++){
            if(mt[k]>ms[k]) return 0;
            
        }
        return 1;
    }
    
    string minWindow(string s, string t) {
        int m=s.length(), n=t.length(),l=0,minlen=INT_MAX,minst=-1,minend=-1;
        if(n>m) return "";
        int mt[52]={0};
        for(char c : t){
            insertchar(mt,c);
        }

        int ms[52]={0};
        for(int r=0; r<m; r++){
            insertchar(ms, s[r]);
            while(isvalid(mt,ms)){
                if(isupper(s[l])) ms[s[l]-'A'+26]--;
                else ms[s[l]-'a']--;

                if(minlen>r-l+1){
                    minlen=r-l+1;
                    minst=l;
                    minend=r;
                }
                l++;
            }
            
            
        }
        if(minst==-1 && minend==-1) return "";
        else{
            return s.substr(minst, minend-minst+1);
        }

        

    }
};