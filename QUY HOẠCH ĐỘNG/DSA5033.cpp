#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestPalindromicSubsequence(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Every single character is a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Check for palindromes of length 2 and more
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[0][n-1];
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string str;
        cin >> str;
        
        int n = str.length();
        int lps = longestPalindromicSubsequence(str);
        
        // Minimum deletions = n - LPS
        cout << n - lps << endl;
    }
    
    return 0;
} 