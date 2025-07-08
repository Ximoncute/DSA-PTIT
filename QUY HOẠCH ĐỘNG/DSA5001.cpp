#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lcs(const string &a, const string &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

int main() {
    int T; cin >> T;
    while(T--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}