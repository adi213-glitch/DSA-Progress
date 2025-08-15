#include <iostream>
#include <vector>
using namespace std;


class Stack {
public:
    int* arr;
    int capacity, topsize,currsize;
    Stack(int n) {
        capacity = n;
        arr = new int[capacity];
        topsize = -1;
        currsize = 0;
    }

    void push(int value) {
        if (currsize==capacity) {
            cout << "Stack Overflow: Cannot push element." << endl;
            return;
        }

        arr[++topsize] = value;
        currsize++;
    }

    void pop() {
        if (empty()) {
            cout << "Stack Underflow: Cannot pop from an empty stack." << endl;
            return;
        }
        topsize--;
        currsize--;
    }

    int top() {
        
        return arr[topsize];
    }


    bool empty() {
        return topsize == -1;
    }
};
vector<int> monotonicJump(const vector<int>& A){
    int n = A.size();
    Stack s(n);
    vector<int> ans(n,-1);
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && A[i]>= A[s.top()]){
            s.pop();
        }
        if(!s.empty()) ans[i]=s.top(); 
        s.push(i);
    }
    return ans;
    



}