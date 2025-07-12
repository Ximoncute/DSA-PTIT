#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        if (n == 1) {
            cout << a[0] << endl;
            continue;
        }
        
        // dp[i] = tổng tài sản lớn nhất có thể lấy từ nhà 0 đến nhà i
        vector<long long> dp(n);
        
        // Trường hợp cơ sở
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        
        // Tính toán quy hoạch động
        for (int i = 2; i < n; i++) {
            // Có hai lựa chọn:
            // 1. Không lấy nhà i: dp[i-1]
            // 2. Lấy nhà i: dp[i-2] + a[i]
            dp[i] = max(dp[i-1], dp[i-2] + a[i]);
        }
        
        cout << dp[n-1] << endl;
    }
    
    return 0;
} 