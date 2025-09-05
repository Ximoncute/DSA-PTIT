#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (S[j] <= S[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int res = *max_element(dp.begin(), dp.end());
    cout << res << endl;
    return 0;
}