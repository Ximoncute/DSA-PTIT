#include <iostream>
using namespace std;

int min_of_three(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int string_length(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int editDistance(char str1[], char str2[]) {
    int m = string_length(str1);
    int n = string_length(str2);
    
    // Create a DP table
    int dp[101][101];
    
    // Initialize base cases
    // If str1 is empty, we need n insertions
    for (int i = 0; i <= n; i++) {
        dp[0][i] = i;
    }
    
    // If str2 is empty, we need m deletions
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    
    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // If characters match, no operation needed
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                // If characters don't match, try all three operations
                dp[i][j] = 1 + min_of_three(
                    dp[i-1][j],     // Delete from str1
                    dp[i][j-1],     // Insert into str1
                    dp[i-1][j-1]    // Replace in str1
                );
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        char str1[101], str2[101];
        cin >> str1 >> str2;
        
        int result = editDistance(str1, str2);
        cout << result << endl;
    }
    
    return 0;
} 