#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
    int arr[100];
    int size;

    MaxHeap(){
        size=0;
        arr[0]=-1;
    }

    void insert(int val){
        if(size==100) {
            cout<<"cant insert"<<endl; 
            return;
        }
        size++;
        arr[size]=val;
        int index= size;
        while(index >1){
            int par = index/2;
            if(arr[par]<arr[index] ) {
                swap(arr[par], arr[index]);
                index=par;
            }
            else return;
        }
    }
    void pop(){
        if(size==0) {
            cout<<"cant delete"<<endl;
            return;
        }
        swap(arr[1], arr[size]);
        size--;
        int i=1;
        while(i <= size){
            int lc = 2*i;
            int rc = lc + 1;

            if(lc <= size && rc <= size){ // both children exist
                if(arr[lc] > arr[rc] && arr[lc] > arr[i]){
                    swap(arr[i], arr[lc]);
                    i = lc;
                }
                else if(arr[rc] > arr[i]){
                    swap(arr[i], arr[rc]);
                    i = rc;
                }
                else return;
            }
            else if(lc <= size){ // only left child exists
                if(arr[lc] > arr[i]){
                    swap(arr[i], arr[lc]);
                    i = lc;
                }
                else return;
            }
            else return; // no children, stop
        }
    }
};
void heapify_0(int arr[], int n , int i){
        int largest =  i;
        int lc= 2*i+1, rc= lc+1;
        if(lc<n  && arr[largest]<arr[lc]) largest = lc;
        if(rc<n  && arr[largest]<arr[rc]) largest = rc;
        if (largest !=i){
            swap(arr[largest], arr[i]);
            heapify_0(arr,n,largest);
        }    
    }
    void BuildMaxHeap_0(int arr[], int size){
            for(int i= (size/2) -1; i>=0; i--){
                heapify_0(arr,size,i);
            }
    }
void heapify_1(int arr[], int n , int i){
        int largest =  i;
        int lc= 2*i, rc= lc+1;
        if(lc<=n  && arr[largest]<arr[lc]) largest = lc;
        if(rc<=n  && arr[largest]<arr[rc]) largest = rc;
        if (largest !=i){
            swap(arr[largest], arr[i]);
            heapify_1(arr,n,largest);
        }    
}
void BuildMaxHeap_1(int arr[], int size){
        for(int i= size/2; i>0; i--){
            heapify_1(arr,size,i);
        }
}
void HeapSort_1(int arr[], int n){
        
        for(int i = n ; i>1; i--){
            swap(arr[1], arr[i]);

            heapify_1(arr,i-1,1);
        }
}
void HeapSort_0(int arr[], int n){
    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);        
        heapify_0(arr, i, 0);       
    }
}

