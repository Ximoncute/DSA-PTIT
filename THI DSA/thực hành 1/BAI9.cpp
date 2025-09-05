#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> dp(M + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = M; j >= x; --j) {
            dp[j] = max(dp[j], dp[j - x] + y);
        }
    }
    cout << dp[M] << endl;
    return 0;
}