#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(a[i]);
        }
        
        if (s.size() < 2) {
            cout << -1 << endl;
        } else {
            auto it = s.begin();
            int first = *it;
            it++;
            int second = *it;
            cout << first << " " << second << endl;
        }
    }
    return 0;
} 