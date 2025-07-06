#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        vector<int> a(m), b(n);
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int i = 0, j = 0, cnt = 0, ans = 0;
        while (i < m && j < n) {
            if (a[i] < b[j]) ans = a[i++];
            else ans = b[j++];
            cnt++;
            if (cnt == k) break;
        }
        while (cnt < k && i < m) {
            ans = a[i++];
            cnt++;
        }
        while (cnt < k && j < n) {
            ans = b[j++];
            cnt++;
        }
        cout << ans << endl;
    }
    return 0;
}