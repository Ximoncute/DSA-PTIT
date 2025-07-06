#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Act {
    int s, f;
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<Act> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].s;
        for (int i = 0; i < n; i++) cin >> a[i].f;
        sort(a.begin(), a.end(), [](Act x, Act y) { return x.f < y.f; });
        int cnt = 1, last = a[0].f;
        for (int i = 1; i < n; i++) {
            if (a[i].s >= last) {
                cnt++;
                last = a[i].f;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}