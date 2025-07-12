#include <iostream>
using namespace std;

const int MOD = 1000000007;

int countWays(int arr[], int n, int k) {
    // dp[i] represents number of ways to make sum i
    long long dp[1001];
    
    // Initialize dp array
    for (int i = 0; i <= k; i++) {
        dp[i] = 0;
    }
    
    // Base case: one way to make sum 0 (take nothing)
    dp[0] = 1;
    
    // For each target sum from 1 to k
    for (int i = 1; i <= k; i++) {
        // Try each element in the array
        for (int j = 0; j < n; j++) {
            if (arr[j] <= i) {
                dp[i] = (dp[i] + dp[i - arr[j]]) % MOD;
            }
        }
    }
    
    return dp[k];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        int arr[1000];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        int result = countWays(arr, N, K);
        cout << result << endl;
    }
    
    return 0;
} 