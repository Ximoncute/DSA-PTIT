#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    long long dp[51] = {0};
    dp[0] = 1;
    for(int i=1; i<=50; i++) {
        dp[i] = dp[i-1];
        if(i >= 2) dp[i] += dp[i-2];
        if(i >= 3) dp[i] += dp[i-3];
    }
    while(T--) {
        int n; cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}