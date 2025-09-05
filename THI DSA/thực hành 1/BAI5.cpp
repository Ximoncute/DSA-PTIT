#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<double> A(N), B(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i] >> B[i];
        }
        vector<int> dp(N, 1);
        int res = 1;
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j] < A[i] && B[j] > B[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
    return 0;
}