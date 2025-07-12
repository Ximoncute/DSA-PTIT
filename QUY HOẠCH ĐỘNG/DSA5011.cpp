#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MOD = 1000000007;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        // dp[i][j] = number of ways to form i-digit number with digit sum j
        // We need to handle the first digit separately (can't be 0)
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        
        // Base case: 0 digits with sum 0
        dp[0][0] = 1;
        
        // Fill for first digit (1-9, can't be 0)
        for (int digit = 1; digit <= 9 && digit <= k; digit++) {
            dp[1][digit] = 1;
        }
        
        // Fill for remaining digits (0-9)
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int digit = 0; digit <= 9; digit++) {
                    if (j >= digit) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-digit]) % MOD;
                    }
                }
            }
        }
        
        cout << dp[n][k] << endl;
    }
    
    return 0;
} 