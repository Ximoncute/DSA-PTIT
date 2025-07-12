#include <iostream>
#include <string>
using namespace std;

int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}

int lcs_three_strings(string X, string Y, string Z) {
    int m = X.length();
    int n = Y.length();
    int o = Z.length();
    
    // Create a 3D DP table using dynamic allocation
    int*** dp = new int**[m + 1];
    for (int i = 0; i <= m; i++) {
        dp[i] = new int*[n + 1];
        for (int j = 0; j <= n; j++) {
            dp[i][j] = new int[o + 1];
            for (int k = 0; k <= o; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    
    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= o; k++) {
                // If characters match in all three strings
                if (X[i-1] == Y[j-1] && Y[j-1] == Z[k-1]) {
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                } else {
                    // Take maximum of all possible combinations
                    int max_val = dp[i-1][j][k];
                    max_val = max_of_two(max_val, dp[i][j-1][k]);
                    max_val = max_of_two(max_val, dp[i][j][k-1]);
                    max_val = max_of_two(max_val, dp[i-1][j-1][k]);
                    max_val = max_of_two(max_val, dp[i-1][j][k-1]);
                    max_val = max_of_two(max_val, dp[i][j-1][k-1]);
                    max_val = max_of_two(max_val, dp[i-1][j-1][k-1]);
                    dp[i][j][k] = max_val;
                }
            }
        }
    }
    
    int result = dp[m][n][o];
    
    // Clean up memory
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            delete[] dp[i][j];
        }
        delete[] dp[i];
    }
    delete[] dp;
    
    return result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int len1, len2, len3;
        cin >> len1 >> len2 >> len3;
        
        string X, Y, Z;
        cin >> X >> Y >> Z;
        
        int result = lcs_three_strings(X, Y, Z);
        cout << result << endl;
    }
    
    return 0;
} 