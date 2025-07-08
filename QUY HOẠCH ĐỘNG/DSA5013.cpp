#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int T; cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        vector<int> dp(N+1, 0);
        dp[0] = 1;
        int sum = 1;
        for(int i=1; i<=N; i++) {
            dp[i] = sum;
            if(i < K) sum = (sum + dp[i]) % MOD;
            else sum = (sum + dp[i] - dp[i-K] + MOD) % MOD;
        }
        cout << dp[N] << endl;
    }
    return 0;
}