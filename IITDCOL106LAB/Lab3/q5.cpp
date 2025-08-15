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

int additional_boxes(vector<int>& height) {
    
    int total_boxes = 0;
    int n = height.size();
    Stack s(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && height[i] > height[s.top()]) {
            // s.top() wale height pe boxes count karo
            int bottom_idx = s.top(); 
            s.pop();

            if (s.empty()) {
                // no valid boxes since no left boundary exists
                break;
            }

            int left_wall_idx = s.top();
            //  right_wall_idx is (i)
            int distance = i - left_wall_idx - 1;
            int valid_height = min(height[left_wall_idx], height[i]);
            
            total_boxes += ((valid_height - height[bottom_idx]) * distance);
        }
        s.push(i);
    }
    return total_boxes;
}