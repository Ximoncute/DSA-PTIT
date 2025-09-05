#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    // DP array to store minimum energy to reach each position
    vector<int> dp(N, INT_MAX);
    dp[0] = 0; // Starting position
    
    for (int i = 1; i < N; i++) {
        // Check all possible previous positions within K steps
        for (int j = max(0, i - K); j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(H[i] - H[j]));
        }
    }
    
    cout << dp[N - 1] << endl;
    
    return 0;
}
