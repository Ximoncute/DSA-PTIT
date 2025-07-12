#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        // Special case: already at boundary
        if (n == 0 || m == 0) {
            cout << 1 << endl;
            continue;
        }
        
        // dp[i][j] = number of ways to reach (0,0) from (i,j)
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
        
        // Base case: from (0,0) there's 1 way (stay there)
        dp[0][0] = 1;
        
        // From boundary positions (0,m) and (n,0), we can reach (0,0) in 1 way
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        cout << dp[n][m] << endl;
    }
    
    return 0;
} 