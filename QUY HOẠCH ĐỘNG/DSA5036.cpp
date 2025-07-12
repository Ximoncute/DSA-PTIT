#include <iostream>
using namespace std;

int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidSubsequence(double A[], double B[], int n) {
    if (n == 0) return 0;
    
    // dp[i] represents the length of longest valid subsequence ending at position i
    int dp[500];
    
    // Initialize all positions with length 1 (each element forms a subsequence of length 1)
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }
    
    // Fill dp array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Check if we can extend the subsequence ending at j to include position i
            // Conditions: A[j] < A[i] (strictly increasing) AND B[j] > B[i] (strictly decreasing)
            if (A[j] < A[i] && B[j] > B[i]) {
                dp[i] = max_of_two(dp[i], dp[j] + 1);
            }
        }
    }
    
    // Find the maximum length among all positions
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max_of_two(maxLength, dp[i]);
    }
    
    return maxLength;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        double A[500], B[500];
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
        }
        
        int result = longestValidSubsequence(A, B, N);
        cout << result << endl;
    }
    
    return 0;
} 