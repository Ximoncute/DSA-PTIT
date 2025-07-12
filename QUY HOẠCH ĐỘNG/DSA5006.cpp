#include <iostream>
using namespace std;

int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}

int maxSumIncreasingSubsequence(int arr[], int n) {
    if (n == 0) return 0;
    
    // dp[i] stores the maximum sum of increasing subsequence ending at index i
    int dp[1000]; // Since N <= 1000 according to constraints
    
    // Initialize dp array with the array elements themselves
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }
    
    // Fill dp array using dynamic programming
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // If arr[j] < arr[i], we can extend the subsequence ending at j
            if (arr[j] < arr[i]) {
                dp[i] = max_of_two(dp[i], dp[j] + arr[i]);
            }
        }
    }
    
    // Find the maximum sum among all dp values
    int maxSum = dp[0];
    for (int i = 1; i < n; i++) {
        maxSum = max_of_two(maxSum, dp[i]);
    }
    
    return maxSum;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int arr[1000]; // Since N <= 1000 according to constraints
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        int result = maxSumIncreasingSubsequence(arr, N);
        cout << result << endl;
    }
    
    return 0;
} 