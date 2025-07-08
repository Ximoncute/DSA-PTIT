#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool found = binary_search(a.begin(), a.end(), x);
        
        if (found) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
} 