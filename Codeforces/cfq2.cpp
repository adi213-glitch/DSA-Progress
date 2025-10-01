#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> g(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> g[i];
    }

    std::sort(g.begin(), g.end());
    
    // DP state: dp[i] = min cost to connect villagers g[0]...g[i]
    std::vector<long long> dp(n);

    // Base Cases
    if (n >= 1) {
        dp[0] = g[0];
    }
    if (n >= 2) {
        dp[1] = g[1];
    }

    // DP Recurrence for all remaining villagers
    for (int i = 2; i < n; ++i) {
        dp[i] = g[i] + std::min(dp[i-1], dp[i-2]);
    }

    std::cout << dp[n - 1] << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}