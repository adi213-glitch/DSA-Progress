#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long operations = 0;
        
        // For each subarray [i,j] where j > i, ensure:
        // sum of elements at even positions >= sum of elements at odd positions
        
        for (int i = 0; i < n; i++) {
            long long even_sum = 0, odd_sum = 0;
            
            for (int j = i; j < n; j++) {
                // Add current element to appropriate sum
                if ((j + 1) % 2 == 0) { // even position (1-indexed)
                    even_sum += a[j];
                } else { // odd position (1-indexed)
                    odd_sum += a[j];
                }
                
                // Check constraint for subarray [i, j] if length >= 2
                if (j > i) {
                    if (even_sum < odd_sum) {
                        long long deficit = odd_sum - even_sum;
                        
                        // We need to decrease odd-indexed elements
                        // Decrease from the current element j backwards
                        for (int k = j; k >= i && deficit > 0; k--) {
                            if ((k + 1) % 2 == 1) { // odd index
                                long long reduce = min(deficit, a[k]);
                                a[k] -= reduce;
                                odd_sum -= reduce;
                                deficit -= reduce;
                                operations += reduce;
                            }
                        }
                    }
                }
            }
        }
        
        cout << operations << "\n";
    }
    
    return 0;
}