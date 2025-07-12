#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, v;
        cin >> n >> v;
        
        vector<int> a(n), c(n);
        
        // Đọc mảng thể tích
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Đọc mảng giá trị
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        
        // Tạo bảng dp để lưu giá trị lớn nhất
        // dp[i][j] = giá trị lớn nhất với i đồ vật đầu tiên và thể tích j
        vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));
        
        // Tính toán quy hoạch động
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= v; j++) {
                // Không lấy đồ vật thứ i
                dp[i][j] = dp[i-1][j];
                
                // Nếu có thể lấy đồ vật thứ i (thể tích đủ)
                if (j >= a[i-1]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-a[i-1]] + c[i-1]);
                }
            }
        }
        
        cout << dp[n][v] << endl;
    }
    
    return 0;
} 