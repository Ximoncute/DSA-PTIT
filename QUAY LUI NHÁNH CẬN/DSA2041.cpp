#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        // Mảng dp[i] lưu số bước ít nhất để đưa i về 1
        vector<int> dp(n + 1, 0);
        
        // Trường hợp cơ sở
        dp[1] = 0;
        
        // Tính dp cho từng số từ 2 đến n
        for (int i = 2; i <= n; i++) {
            // Thao tác giảm i đi 1
            dp[i] = dp[i - 1] + 1;
            
            // Nếu i chia hết cho 2, thử thao tác chia 2
            if (i % 2 == 0) {
                dp[i] = min(dp[i], dp[i / 2] + 1);
            }
            
            // Nếu i chia hết cho 3, thử thao tác chia 3
            if (i % 3 == 0) {
                dp[i] = min(dp[i], dp[i / 3] + 1);
            }
        }
        
        cout << dp[n] << endl;
    }
    
    return 0;
} 