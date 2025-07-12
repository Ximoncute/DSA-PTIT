#include <iostream>
using namespace std;

long long max_of_two(long long a, long long b) {
    return (a > b) ? a : b;
}

long long maxSumNonAdjacent(int n) {
    if (n == 0) return 0;
    
    long long prev2 = 0; // dp[i-2]
    long long prev1 = 0; // dp[i-1]
    long long current = 0; // dp[i]
    
    for (int i = 0; i < n; i++) {
        long long arr_i;
        cin >> arr_i;
        
        if (i == 0) {
            current = arr_i;
        } else if (i == 1) {
            current = max_of_two(prev1, arr_i);
        } else {
            // For each position i, we have two choices:
            // 1. Include arr[i]: then we can't include arr[i-1], so we take prev2 + arr[i]
            // 2. Exclude arr[i]: then we take prev1
            current = max_of_two(prev1, prev2 + arr_i);
        }
        
        // Update for next iteration
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        long long result = maxSumNonAdjacent(N);
        cout << result << endl;
    }
    
    return 0;
} 