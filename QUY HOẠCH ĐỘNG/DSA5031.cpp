#include <iostream>
using namespace std;

int min_of_two(int a, int b) {
    return (a < b) ? a : b;
}

int minPerfectSquares(int n) {
    // dp[i] represents minimum number of perfect squares needed to sum to i
    int dp[10001];
    
    // Initialize with large values
    for (int i = 0; i <= n; i++) {
        dp[i] = i; // At most i 1's are needed (worst case)
    }
    
    // Base case
    dp[0] = 0;
    
    // Fill dp array
    for (int i = 1; i <= n; i++) {
        // Try all perfect squares j*j <= i
        for (int j = 1; j * j <= i; j++) {
            int square = j * j;
            dp[i] = min_of_two(dp[i], dp[i - square] + 1);
        }
    }
    
    return dp[n];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int result = minPerfectSquares(N);
        cout << result << endl;
    }
    
    return 0;
} 