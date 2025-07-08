#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> c;
        
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            c.push_back(x);
        }
        
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            c.push_back(x);
        }
        
        sort(c.begin(), c.end());
        
        for (int i = 0; i < c.size(); i++) {
            if (i > 0) cout << " ";
            cout << c[i];
        }
        cout << endl;
    }
    return 0;
} 