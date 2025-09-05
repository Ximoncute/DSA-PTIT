#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<int> dp(N+1), prefix(N+1);
        dp[0] = 1;
        prefix[0] = 1;

        for (int i = 1; i <= N; i++) {
            long long sum = prefix[i-1];
            if (i - K - 1 >= 0) sum -= prefix[i-K-1];
            dp[i] = (sum % MOD + MOD) % MOD;
            prefix[i] = (prefix[i-1] + dp[i]) % MOD;
        }

        cout << dp[N] << "\n";
    }
    return 0;
}
