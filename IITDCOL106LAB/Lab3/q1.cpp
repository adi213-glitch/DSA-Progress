#include <iostream>
#include <vector>
using namespace std;
class stack{
public:
    vector<int> vec;
    int topIndex;
    int n;
    stack(int capacity){
        n=capacity;
        topIndex=-1;
    }
    void push(int x) {
        if(vec.size()==n) { cout<<"STACKOVERFLOW"; return; }
        vec.push_back(x);
        topIndex++;
    } 
    void pop(){
        if(vec.size()==0) { cout<< "STACKUNDERFLOW"; return; }
        vec.pop_back();
        topIndex--;
    }
    int top(){
        if(vec.size()==0) { cout<<"EMPTYSTACK"; return -1; }
        return vec.back();
    }
    int size(){
        return vec.size();
    }
    bool empty(){
        return vec.empty();
    }

};
vector<int> signalSpan(const vector<int>& A){
    int size =A.size();
    
    vector<int> ans;
    stack s(size);
    stack idx(size);
    
    for(int i=0; i<size; i++){
        
        while(!s.empty() && s.top() <= A[i]){
            s.pop(); idx.pop();
        }
        int span= (s.empty())? i+1 : i-idx.top();
        s.push(A[i]); 
        idx.push(i);
        
        ans.push_back(span);
        
    }
    return ans;

}


    