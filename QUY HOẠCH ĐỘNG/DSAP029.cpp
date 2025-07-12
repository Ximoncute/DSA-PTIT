#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> c(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> c[i][j];
            }
        }
        
        // dp[mask][i] = chi phí nhỏ nhất để đi qua các thành phố trong mask và kết thúc tại thành phố i
        vector<vector<int>> dp(1 << n, vector<int>(n, INF));
        
        // Khởi tạo: bắt đầu từ mỗi thành phố
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 0;
        }
        
        // Tính toán DP
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u)) || dp[mask][u] == INF) continue;
                
                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue; // v đã được thăm
                    
                    int new_mask = mask | (1 << v);
                    dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + c[u][v]);
                }
            }
        }
        
        // Tìm kết quả tối ưu
        int full_mask = (1 << n) - 1;
        int result = INF;
        
        for (int i = 0; i < n; i++) {
            result = min(result, dp[full_mask][i]);
        }
        
        cout << result << endl;
    }
    
    return 0;
} 