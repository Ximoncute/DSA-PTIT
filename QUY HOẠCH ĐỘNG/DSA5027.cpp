#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, V;
        cin >> N >> V;
        vector<int> A(N), C(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> C[i];
        vector<int> dp(V + 1, 0);
        for (int i = 0; i < N; ++i) {
            for (int v = V; v >= A[i]; --v) {
                dp[v] = max(dp[v], dp[v - A[i]] + C[i]);
            }
        }
        cout << dp[V] << endl;
    }
    return 0;
}