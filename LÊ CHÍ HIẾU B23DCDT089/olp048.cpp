#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

int main() {
    int K;
    string S;
    cin >> K >> S;
    
    int n = S.size();
    
    // dp[i][j][k] = number of ways to process first i characters
    // with j open parentheses and current degree k
    vector<vector<vector<long long>>> dp(n + 1, 
        vector<vector<long long>>(n + 2, vector<long long>(K + 2, 0)));
    
    dp[0][0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= K; k++) {
                if (dp[i][j][k] == 0) continue;
                
                char c = S[i];
                
                // Try '('
                if (c == '(' || c == '?') {
                    if (j + 1 <= n) {
                        dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + dp[i][j][k]) % MOD;
                    }
                }
                
                // Try ')'
                if (c == ')' || c == '?') {
                    if (j > 0) {
                        int new_k = k;
                        // When we close a pair, we might increase the degree
                        // This happens when we have a complete balanced expression
                        // We need to check if we just closed a balanced expression
                        // This is complex to track directly, so we'll use a different approach
                        
                        // For now, just propagate the current degree
                        dp[i + 1][j - 1][k] = (dp[i + 1][j - 1][k] + dp[i][j][k]) % MOD;
                    }
                }
            }
        }
    }
    
    // The above approach doesn't correctly track the degree
    // Let me implement a better approach
    
    // Reset and use a different DP approach
    // dp[i][j][k] = number of ways to process first i characters
    // with j open parentheses and maximum nesting depth k
    vector<vector<vector<long long>>> dp2(n + 1, 
        vector<vector<long long>>(n + 2, vector<long long>(K + 2, 0)));
    
    dp2[0][0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= K; k++) {
                if (dp2[i][j][k] == 0) continue;
                
                char c = S[i];
                
                // Try '('
                if (c == '(' || c == '?') {
                    if (j + 1 <= n) {
                        int new_k = max(k, j + 1);
                        if (new_k <= K) {
                            dp2[i + 1][j + 1][new_k] = (dp2[i + 1][j + 1][new_k] + dp2[i][j][k]) % MOD;
                        }
                    }
                }
                
                // Try ')'
                if (c == ')' || c == '?') {
                    if (j > 0) {
                        dp2[i + 1][j - 1][k] = (dp2[i + 1][j - 1][k] + dp2[i][j][k]) % MOD;
                    }
                }
            }
        }
    }
    
    cout << dp2[n][0][K] << endl;
    
    return 0;
}
