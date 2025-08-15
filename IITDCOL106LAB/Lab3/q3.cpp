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
    ~Stack() {
        delete[] arr;
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
    int size(){
        return currsize;
    }
};
int mod (int n){
    return (n>=0)? n : (-1)*n ;
}
vector<int> collisionSimulator(const vector<int>& A){
    int n =A.size();
    Stack s(n);
    
    for(int i =0; i<n;i++){
        bool asteroidbreak=0;
        while(!s.empty() &&  (s.top()>0 && A[i]<0 )  && (mod(A[i]) >= mod(s.top())) ){
            if(mod(s.top()) == mod(A[i]) ){ s.pop(); asteroidbreak=1; break;}
            s.pop();
        }
        if( asteroidbreak ||  ((!s.empty()) && (mod(A[i]) <mod(s.top()))) ) continue;
        s.push(A[i]);

    }
    vector<int> ans(s.size());
    for(int i = s.size()-1 ; i>=0; i--){
        ans[i]= s.top();
        s.pop();
    }
    return ans;


}