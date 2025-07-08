#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int l = 0, r = n - 1, res = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] <= x) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (res == -1) cout << -1 << endl;
        else cout << res + 1 << endl; // vị trí tính từ 1
    }
    return 0;
}