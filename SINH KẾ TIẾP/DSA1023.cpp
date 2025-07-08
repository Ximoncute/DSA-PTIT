#include <iostream>
using namespace std;

// Hàm tính C(n, k)
int C(int n, int k) {
    if (k == 0 || k == n) return 1;
    int res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        int a[20];
        for (int i = 0; i < K; ++i) cin >> a[i];
        int ans = 0, prev = 0;
        for (int i = 0; i < K; ++i) {
            for (int j = prev + 1; j < a[i]; ++j) {
                ans += C(N - j, K - i - 1);
            }
            prev = a[i];
        }
        cout << ans + 1 << endl;
    }
    return 0;
}