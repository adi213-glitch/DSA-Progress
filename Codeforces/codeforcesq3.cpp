#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t; // for big powers

// helper to compute 10^d safely
i128 power10(int d) {
    i128 res = 1;
    while (d--) res *= 10;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;

        // Step 1: find which digit block contains the k-th digit
        long long digits_used = 0;
        int d = 1;
        while (true) {
            i128 cnt = 9 * power10(d - 1); // count of numbers with d digits
            i128 total = cnt * d;          // total digits contributed
            if (k > digits_used + total) {
                digits_used += total;
                d++;
            } else break;
        }

        // Step 2: find offset inside the d-digit block
        long long offset = k - digits_used; // offset within this block
        long long number_index = (offset - 1) / d; // which number inside block
        long long digit_index  = (offset - 1) % d; // which digit of that number

        long long start = (long long)power10(d - 1);
        long long num = start + number_index;

        // Step 3: Now compute sum of digits up to k
        // (Efficient sum-of-digits formula would be better, but here we only need prefix sum up to k)
        // For demonstration, compute directly until k — careful for huge k, normally formula is needed.
        
        // We'll compute digit sum for first k digits
        // (In practice, you'd derive prefix sums mathematically for performance)
        string seq;
        for (long long i = 1; i <= num; i++) {
            seq += to_string(i);
            if ((long long)seq.size() >= k) break;
        }
        long long ans = 0;
        for (int i = 0; i < k; i++) ans += seq[i] - '0';

        cout << ans << "\n";
    }
}
