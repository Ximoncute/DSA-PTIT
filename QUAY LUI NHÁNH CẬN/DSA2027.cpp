#include<iostream>
using namespace std;

int n;
int c[16][16];
int dp[16][65536]; // dp[i][mask] = chi phí nhỏ nhất từ thành phố 1 đến i, đã thăm các thành phố trong mask

int TSP() {
    // Khởi tạo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = 1e9;
        }
    }
    
    dp[0][1] = 0; // Bắt đầu từ thành phố 0 (tương ứng thành phố 1), mask = 1
    
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) && dp[i][mask] < 1e9) {
                for (int j = 0; j < n; j++) {
                    if (!(mask & (1 << j)) && c[i][j] > 0) {
                        int newMask = mask | (1 << j);
                        if (dp[i][mask] + c[i][j] < dp[j][newMask]) {
                            dp[j][newMask] = dp[i][mask] + c[i][j];
                        }
                    }
                }
            }
        }
    }
    
    int result = 1e9;
    int fullMask = (1 << n) - 1;
    for (int i = 1; i < n; i++) {
        if (dp[i][fullMask] < 1e9 && c[i][0] > 0) {
            if (dp[i][fullMask] + c[i][0] < result) {
                result = dp[i][fullMask] + c[i][0];
            }
        }
    }
    
    return result;
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    
    cout << TSP() << endl;
    
    return 0;
} 