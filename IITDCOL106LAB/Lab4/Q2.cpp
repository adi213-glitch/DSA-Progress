#include <iostream>
#include <vector>
using namespace std;



class Deque {
public:
    int* arr;
    int capacity, currsize, frontele, rear;

    Deque(int n) {
        capacity = n;
        arr = new int[capacity];
        currsize = 0;
        frontele = -1;
        rear = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    void push_back(int value) {
        if (currsize == capacity) {
            cout << "Queue is full. Cannot push element." << endl;
            return;
        }
        if (empty()) {
            frontele = 0;
            rear=0;
        }
        else{
            rear = (rear + 1) % capacity;
            
        }
        arr[rear] = value;
        currsize++;
    }
    void push_front(int value) {
        if (currsize == capacity) {
            cout << "Queue is full. Cannot push element." << endl;
            return;
        }
        if (empty()) {
            rear = 0;
            frontele=0;
        }
        else{ 
            frontele = (frontele - 1+ capacity) % capacity;
           
        }
         arr[frontele] = value;
        currsize++;
    }

    void pop_front() {
        if (empty()) {
            cout << "Queue is empty. Cannot pop element." << endl;
            return;
        }

        if (currsize==1) {
            frontele = -1;
            rear = -1;
        } else {
            frontele = (frontele + 1) % capacity;
        }
        currsize--;
    }
    void pop_back() {
        if (empty()) {
            cout << "Queue is empty. Cannot pop element." << endl;
            return;
        }

        if (currsize==1) {
            frontele = -1;
            rear = -1;
        } else {
            rear= (rear-1+capacity)%capacity;
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
    int back() {
        if (empty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[rear];
    }

    bool empty() {
        return currsize == 0;
    }

    int size() {
        return currsize;
    }
};