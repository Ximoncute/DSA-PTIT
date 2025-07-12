#include <iostream>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, X, Y, Z;
        cin >> N >> X >> Y >> Z;
        
        // dp[i] represents minimum time to get exactly i characters
        int dp[101];
        
        // Initialize with large values
        for (int i = 0; i <= 100; i++) {
            dp[i] = 1000000;
        }
        
        // Base case: 0 characters costs 0 time
        dp[0] = 0;
        
        // Fill dp array
        for (int i = 0; i <= 100; i++) {
            if (dp[i] == 1000000) continue;
            
            // Insert operation: i -> i+1
            if (i + 1 <= 100) {
                dp[i + 1] = min(dp[i + 1], dp[i] + X);
            }
            
            // Delete operation: i -> i-1
            if (i > 0) {
                dp[i - 1] = min(dp[i - 1], dp[i] + Y);
            }
            
            // Copy operation: i -> 2*i
            if (i > 0 && 2 * i <= 100) {
                dp[2 * i] = min(dp[2 * i], dp[i] + Z);
            }
        }
        
        // Run multiple passes to ensure we find optimal solution
        for (int pass = 0; pass < 3; pass++) {
            for (int i = 0; i <= 100; i++) {
                if (dp[i] == 1000000) continue;
                
                // Insert operation
                if (i + 1 <= 100) {
                    dp[i + 1] = min(dp[i + 1], dp[i] + X);
                }
                
                // Delete operation
                if (i > 0) {
                    dp[i - 1] = min(dp[i - 1], dp[i] + Y);
                }
                
                // Copy operation
                if (i > 0 && 2 * i <= 100) {
                    dp[2 * i] = min(dp[2 * i], dp[i] + Z);
                }
            }
        }
        
        cout << dp[N] << endl;
    }
    
    return 0;
} 