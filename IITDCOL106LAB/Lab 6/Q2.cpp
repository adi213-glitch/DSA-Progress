#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class minHeap{
public:
// implementing 0 indezed min heap
    vector<long long int> vec;
    minHeap(){
        
    }
    void push(long long x){
        vec.push_back(x);
        int i = vec.size()-1;
        while(i>0){
            int par = (i-1 )/ 2;
            if(vec[par]> vec[i]){
                swap(vec[par], vec[i]);
                i=par;
            }else return;
        }
    }
    long long int top(){
        if(vec.size()==0) return -1;
        return vec[0];
    }
    void heapify(vector<long long int> &vec, int n, int i){
        int smallest =i;
        int lc = (2* i) + 1, rc = lc+1;
        if(lc<n    &&   vec[smallest] > vec[lc]) smallest =lc;
        if(rc<n    &&   vec[smallest] > vec[rc]) smallest =rc;
        if(smallest != i){
            swap(vec[smallest], vec[i]);
            heapify (vec,n, smallest);
        }
        // tc is O(logn) 
    }
    long long int pop(){
        int n = vec.size();
        if(n==0) return -1;
        long long int ans = vec[0];
        swap(vec[0], vec[n-1]);
        
        vec.pop_back();
        heapify(vec,n-1,0);
        return ans;
        // tc is O(logn)
    }
    int size(){
        return vec.size();
    }
    bool empty(){
        return vec.size()==0;
    }
};

long long int minCost(vector<int> w){
    minHeap pq;
    for(int i : w) pq.push(i);
    long long sum =0;
    while(pq.size()!=1){
        long long temp = (pq.pop() + pq.pop());
        sum+=temp;
        pq.push(temp);
    }
    return sum;
}
