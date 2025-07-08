#include <iostream>
using namespace std;

int main() {
    int n, k, s;
    
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0) break;
        
        // dp[i][j][sum] = số cách chọn j phần tử từ {1,2,...,i} có tổng = sum
        int dp[25][15][160];
        
        // Khởi tạo tất cả = 0
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int sum = 0; sum <= s; sum++) {
                    dp[i][j][sum] = 0;
                }
            }
        }
        
        // Trường hợp cơ sở: chọn 0 phần tử có tổng 0
        for (int i = 0; i <= n; i++) {
            dp[i][0][0] = 1;
        }
        
        // Điền bảng dp
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int sum = 0; sum <= s; sum++) {
                    // Không chọn số i
                    dp[i][j][sum] = dp[i-1][j][sum];
                    
                    // Chọn số i (nếu có thể)
                    if (j > 0 && sum >= i) {
                        dp[i][j][sum] += dp[i-1][j-1][sum-i];
                    }
                }
            }
        }
        
        cout << dp[n][k][s] << endl;
    }
    
    return 0;
} 