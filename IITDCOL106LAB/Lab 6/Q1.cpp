#include <vector>
#include <iostream>
using namespace std;
class queue{
public: 
    int * arr ;
    int capacity;
    int size;
    int r,l;

    queue(int n){
        capacity=n;
        arr= new int[n];
        size=0;
        r=-1;
        l=-1;
    }
    ~queue() {
        delete  []arr;
    }
    void push(int x){
        if(capacity ==size) return;
        if(size==0) l++;
        size++;
        r=(r+1)%capacity;
        arr[r]=x;
    }
    void pop(){
        if(size==0) return;
        
        if(size==1) {
            r=-1;
            l=-1;
        }
        else{
            l=(l+1)%capacity;
        }
        size--;
    }
    int front(){
        if(size==0) return -1;
        return arr[l];
    }
    int size(){
        return size;
    }
    bool empty(){
        return (size==0);
    }
};
class minHeap{
public:
// implementing 0 indezed min heap
    vector<int> vec;
    minHeap(){
        
    }
    void push(int x){
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
    int top(){
        if(vec.size()==0) return -1;
        return vec[0];
    }
    void heapify(vector<int> &vec, int n, int i){
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
    int pop(){
        int n = vec.size();
        if(n==0) return -1;
        int ans = vec[0];
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

vector<int> findSeq (vector<int> A){
    int n = A.size();
    vector<int> ans;

    queue  q(n);
    minHeap pq;
    int mosturgent = INT32_MIN;
    for(int i =0; i<n; i++){
        // arrivals need to process
        pq.push(A[i]);
        if(pq.size()<=2) {
            mosturgent = pq.top();
        }else if(pq.size()>2){
            mosturgent = pq.pop();            
            q.push(mosturgent);
        }
        if(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
    }
    // all arrivals done now just cure patients and record
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }
    while(!pq.empty()){
        ans.push_back(pq.pop());
    }
    return ans;


}
