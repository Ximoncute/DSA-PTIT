#include <iostream>
using namespace std;

int max_of_two(int a, int b) {
    return (a > b) ? a : b;
}

int stringLength(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int longestPalindromicSubsequence(char s[]) {
    int n = stringLength(s);
    if (n <= 1) return n;
    
    // dp[i][j] = độ dài LPS trong đoạn từ i đến j
    int dp[101][101];
    
    // Khởi tạo: mỗi ký tự đơn là palindrome có độ dài 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Duyệt theo độ dài đoạn con
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            
            if (s[i] == s[j]) {
                // Nếu 2 ký tự đầu cuối giống nhau
                if (len == 2) {
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
            } else {
                // Nếu 2 ký tự đầu cuối khác nhau
                dp[i][j] = max_of_two(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[0][n-1];
}

int minDeletionsForPalindrome(char s[]) {
    int n = stringLength(s);
    int lpsLength = longestPalindromicSubsequence(s);
    return n - lpsLength;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        char s[101];
        cin >> s;
        
        int result = minDeletionsForPalindrome(s);
        cout << result << endl;
    }
    
    return 0;
} 