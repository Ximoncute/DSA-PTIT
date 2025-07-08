#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int l = 0, r = n - 1;
        while (l < r) {
            cout << a[r--] << " " << a[l++] << " ";
        }
        if (l == r) cout << a[l];
        cout << endl;
    }
    return 0;
}