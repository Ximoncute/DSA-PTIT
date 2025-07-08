#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // dp[i][j] = số dãy con tăng dần có j phần tử kết thúc tại vị trí i
    vector<vector<int>> dp(N, vector<int>(K + 1, 0));
    
    // Khởi tạo: mỗi phần tử có thể tạo thành 1 dãy con có 1 phần tử
    for (int i = 0; i < N; i++) {
        dp[i][1] = 1;
    }
    
    // Tính dp
    for (int j = 2; j <= K; j++) {
        for (int i = 1; i < N; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (a[prev] < a[i]) {
                    dp[i][j] += dp[prev][j-1];
                }
            }
        }
    }
    
    // Tính tổng số dãy con tăng dần bậc K
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += dp[i][K];
    }
    
    cout << result << endl;
    
    return 0;
} 