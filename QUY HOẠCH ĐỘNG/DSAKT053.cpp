#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        string n, m;
        cin >> n >> m;
        
        int len_n = n.length();
        int len_m = m.length();
        
        // Tạo bảng dp để lưu độ dài LCS
        vector<vector<int>> dp(len_n + 1, vector<int>(len_m + 1, 0));
        
        // Tính LCS bằng quy hoạch động
        for (int i = 1; i <= len_n; i++) {
            for (int j = 1; j <= len_m; j++) {
                if (n[i-1] == m[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        cout << dp[len_n][len_m] << endl;
    }
    
    return 0;
} 