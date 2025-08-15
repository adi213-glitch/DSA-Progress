#include <iostream>
#include <vector>

using namespace std;

class Deque {
public:
    long long* arr;
    int capacity, count, front_idx, rear_idx;

    Deque(int n) {
        capacity = n + 1;
        arr = new long long[capacity];
        count = 0;
        front_idx = -1;
        rear_idx = -1;
    }

    ~Deque() {
        delete[] arr;
    }

    bool empty() {
        return count == 0;
    }

    void push_back(long long value) {
        if (count == capacity) return;
        if (empty()) {
            front_idx = 0;
            rear_idx = 0;
        } else {
            rear_idx = (rear_idx + 1) % capacity;
        }
        arr[rear_idx] = value;
        count++;
    }

    void pop_front() {
        if (empty()) return;
        if (front_idx == rear_idx) {
            front_idx = -1;
            rear_idx = -1;
        } else {
            front_idx = (front_idx + 1) % capacity;
        }
        count--;
    }

    void pop_back() {
        if (empty()) return;
        if (front_idx == rear_idx) {
            front_idx = -1;
            rear_idx = -1;
        } else {
            rear_idx = (rear_idx - 1 + capacity) % capacity;
        }
        count--;
    }

    long long front() {
        if (empty()) return -1;
        return arr[front_idx];
    }

    long long back() {
        if (empty()) return -1;
        return arr[rear_idx];
    }
};

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + nums[i];
    }

    int min_len = n + 1;
    Deque d(n + 1);

    for (int y = 0; y <= n; y++) {
        while (!d.empty() && prefix_sum[y] - prefix_sum[d.front()] >= k) {
            int current_len = y - (int)d.front();
            if (current_len < min_len) {
                min_len = current_len;
            }
            d.pop_front();
        }

        while (!d.empty() && prefix_sum[y] <= prefix_sum[d.back()]) {
            d.pop_back();
        }

        d.push_back(y);
    }

    return (min_len > n) ? -1 : min_len;
}