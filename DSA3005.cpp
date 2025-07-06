#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        int s1 = 0, s2 = 0;
        for (int i = 0; i < k; i++) s1 += a[i];
        for (int i = 0; i < k; i++) s2 += a[n - 1 - i];
        int ans = max(abs(sum - 2 * s1), abs(sum - 2 * s2));
        cout << ans << endl;
    }
    return 0;
}