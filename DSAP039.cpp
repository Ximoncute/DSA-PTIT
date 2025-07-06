#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, a[21][21];
int dp[1 << 20];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        int N = 1 << n;
        fill(dp, dp + N, 0);
        for (int mask = 0; mask < N; mask++) {
            int row = __builtin_popcount(mask);
            if (row >= n) continue;
            for (int col = 0; col < n; col++) {
                if (!(mask & (1 << col))) {
                    int new_mask = mask | (1 << col);
                    dp[new_mask] = max(dp[new_mask], dp[mask] + a[row][col]);
                }
            }
        }
        cout << dp[N - 1] << endl;
    }
    return 0;
}