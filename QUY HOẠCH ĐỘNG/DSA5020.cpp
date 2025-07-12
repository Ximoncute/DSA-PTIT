#include <iostream>
using namespace std;

int min_of_three(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int min_of_two(int a, int b) {
    return (a < b) ? a : b;
}

int minPathSum(int matrix[][1000], int N, int M) {
    // dp[i][j] represents minimum sum to reach position (i,j)
    int dp[1000][1000];
    
    // Initialize the starting position
    dp[0][0] = matrix[0][0];
    
    // Fill first row (can only come from left)
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j-1] + matrix[0][j];
    }
    
    // Fill first column (can only come from top)
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }
    
    // Fill the rest of the table
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            // Can come from three directions:
            // 1. From top: dp[i-1][j]
            // 2. From left: dp[i][j-1]
            // 3. From diagonal: dp[i-1][j-1]
            dp[i][j] = min_of_three(
                dp[i-1][j],      // from top
                dp[i][j-1],      // from left
                dp[i-1][j-1]     // from diagonal
            ) + matrix[i][j];
        }
    }
    
    return dp[N-1][M-1];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        int matrix[1000][1000];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        
        int result = minPathSum(matrix, N, M);
        cout << result << endl;
    }
    
    return 0;
} 