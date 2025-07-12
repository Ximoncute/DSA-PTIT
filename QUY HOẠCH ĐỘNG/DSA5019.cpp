#include <iostream>
using namespace std;

int min_of_three(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}

int largestSquare(int matrix[][500], int N, int M) {
    if (N == 0 || M == 0) return 0;
    
    // dp[i][j] represents the side length of largest square ending at (i,j)
    int dp[500][500];
    int maxSide = 0;
    
    // Initialize first row and first column
    for (int i = 0; i < N; i++) {
        dp[i][0] = matrix[i][0];
        maxSide = max_of_two(maxSide, dp[i][0]);
    }
    
    for (int j = 0; j < M; j++) {
        dp[0][j] = matrix[0][j];
        maxSide = max_of_two(maxSide, dp[0][j]);
    }
    
    // Fill the dp table
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (matrix[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min_of_three(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                maxSide = max_of_two(maxSide, dp[i][j]);
            }
        }
    }
    
    return maxSide;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        int matrix[500][500];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        
        int result = largestSquare(matrix, N, M);
        cout << result << endl;
    }
    
    return 0;
} 