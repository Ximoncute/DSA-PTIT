#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        b = a;
        sort(b.begin(), b.end());
        bool ok = true;
        for (int i = 0; i < n / 2 + 1; i++) {
            vector<int> v1 = {a[i], a[n-1-i]};
            vector<int> v2 = {b[i], b[n-1-i]};
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            if (v1 != v2) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}