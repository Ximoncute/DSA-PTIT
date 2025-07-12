#include <bits/stdc++.h>
using namespace std;

const int INF = -1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> a(4, vector<int>(n));
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        
        // Tạo tất cả các trạng thái hợp lệ cho 1 cột (không có 2 ô kề nhau theo chiều dọc)
        vector<int> valid_states;
        vector<int> state_values(n, 0);
        
        for (int mask = 0; mask < 16; mask++) { // 2^4 = 16 trạng thái
            bool valid = true;
            // Kiểm tra không có 2 bit liền kề nào cùng bằng 1
            for (int i = 0; i < 3; i++) {
                if ((mask & (1 << i)) && (mask & (1 << (i + 1)))) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                valid_states.push_back(mask);
            }
        }
        
        // dp[j][mask] = điểm lớn nhất tại cột j với trạng thái mask
        vector<vector<int>> dp(n, vector<int>(16, INF));
        
        // Khởi tạo cột đầu tiên
        for (int mask : valid_states) {
            int sum = 0;
            for (int i = 0; i < 4; i++) {
                if (mask & (1 << i)) {
                    sum += a[i][0];
                }
            }
            dp[0][mask] = sum;
        }
        
        // Tính toán DP cho các cột tiếp theo
        for (int j = 1; j < n; j++) {
            for (int curr_mask : valid_states) {
                int curr_sum = 0;
                for (int i = 0; i < 4; i++) {
                    if (curr_mask & (1 << i)) {
                        curr_sum += a[i][j];
                    }
                }
                
                for (int prev_mask : valid_states) {
                    // Kiểm tra không có ô nào kề nhau giữa 2 cột
                    bool can_transition = true;
                    for (int i = 0; i < 4; i++) {
                        if ((curr_mask & (1 << i)) && (prev_mask & (1 << i))) {
                            can_transition = false;
                            break;
                        }
                    }
                    
                    if (can_transition && dp[j-1][prev_mask] != INF) {
                        dp[j][curr_mask] = max(dp[j][curr_mask], dp[j-1][prev_mask] + curr_sum);
                    }
                }
            }
        }
        
        // Tìm kết quả tối ưu
        int result = INF;
        for (int mask : valid_states) {
            result = max(result, dp[n-1][mask]);
        }
        
        cout << result << endl;
    }
    
    return 0;
} 