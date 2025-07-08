#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + a[i] * i) % MOD;
        }
        cout << res << endl;
    }
    return 0;
}