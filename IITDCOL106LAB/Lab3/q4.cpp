#include <iostream>
#include <vector>
using namespace std;



class Queue {
public:
    int* arr;
    int capacity, currsize, frontele, rear;

    Queue(int n) {
        capacity = n;
        arr = new int[capacity];
        currsize = 0;
        frontele = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void push(int value) {
        if (currsize == capacity) {
            cout << "Queue is full. Cannot push element." << endl;
            return;
        }
        if (empty()) {
            frontele = 0;
        }
        
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        currsize++;
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty. Cannot pop element." << endl;
            return;
        }

        if (frontele == rear) {
            frontele = -1;
            rear = -1;
        } else {
            frontele = (frontele + 1) % capacity;
        }
        currsize--;
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[frontele];
    }

    bool empty() {
        return currsize == 0;
    }

    int size() {
        return currsize;
    }
};
string predictPolicyVictory(string p){
    
    int n = p.length();
    if(n==1)  return (p=="L")? "Loktantrik" : "Janmat";
    Queue ql(n), qj(n);
    // queue for indices of both L and J party MPs
    for(int i=0; i<n;i++){
        switch (p[i]){
            case 'L' : ql.push(i); break;
            default : qj.push(i) ; break;
        }
    }
    //  run loop for all voting  rounds to finish
    while(!ql.empty() && !qj.empty()){
        int l_index = ql.front();
        int j_index = qj.front();
        if (l_index < j_index) {
    //   L mp in ql uses his vote to eliminate turn of J mp with lowest index in qj
            ql.pop();
            qj.pop();
            ql.push(l_index + n); 
        } else {
            // vice versa
            ql.pop();
            qj.pop();
            qj.push(j_index + n);
        }
    }
    // whoever remains. their party wins.
    return (ql.size() > qj.size())? "Loktantrik" : "Janmat";
    

}