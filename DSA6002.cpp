#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        stable_sort(a.begin(), a.end(), [X](int u, int v) {
            return abs(X - u) < abs(X - v);
        });
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}