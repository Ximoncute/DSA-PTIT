#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> A[i][j];
        vector<vector<int>> dp(N, vector<int>(M, 0));
        dp[0][0] = A[0][0];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (i == 0 && j == 0) continue;
                int mn = 1e9;
                if (i > 0) mn = min(mn, dp[i-1][j]);
                if (j > 0) mn = min(mn, dp[i][j-1]);
                if (i > 0 && j > 0) mn = min(mn, dp[i-1][j-1]);
                dp[i][j] = A[i][j] + mn;
            }
        }
        cout << dp[N-1][M-1] << endl;
    }
    return 0;
}