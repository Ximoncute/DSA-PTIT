#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<long long> a(n), b(m);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        long long maxA = *max_element(a.begin(), a.end());
        long long minB = *min_element(b.begin(), b.end());
        
        cout << maxA * minB << endl;
    }
    return 0;
} 