#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countWays(const string& s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // empty string
    dp[1] = 1; // first char is not '0'
    for (int i = 2; i <= n; ++i) {
        if (s[i-1] != '0') dp[i] += dp[i-1];
        int two = stoi(s.substr(i-2, 2));
        if (s[i-2] != '0' && two >= 10 && two <= 26) dp[i] += dp[i-2];
    }
    return dp[n];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string M;
        cin >> M;
        cout << countWays(M) << endl;
    }
    return 0;
}