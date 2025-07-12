#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // dp[i][j] = maximum length of subsequence ending at or before index i
        // with sum having remainder j when divided by k
        vector<vector<int>> dp(n + 1, vector<int>(k, -1));
        
        // Base case: empty subsequence has sum 0, remainder 0, length 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            // Copy previous state
            for (int j = 0; j < k; j++) {
                dp[i][j] = dp[i-1][j];
            }
            
            // Try including current element
            int current_element = arr[i-1];
            int current_remainder = current_element % k;
            
            for (int prev_remainder = 0; prev_remainder < k; prev_remainder++) {
                if (dp[i-1][prev_remainder] != -1) {
                    int new_remainder = (prev_remainder + current_remainder) % k;
                    int new_length = dp[i-1][prev_remainder] + 1;
                    
                    if (dp[i][new_remainder] == -1 || dp[i][new_remainder] < new_length) {
                        dp[i][new_remainder] = new_length;
                    }
                }
            }
        }
        
        cout << dp[n][0] << endl;
    }
    
    return 0;
} 