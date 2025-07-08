#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        set<int> s;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        
        int minVal = *min_element(a.begin(), a.end());
        int maxVal = *max_element(a.begin(), a.end());
        
        int totalNumbers = maxVal - minVal + 1;
        int existingNumbers = s.size();
        
        cout << totalNumbers - existingNumbers << endl;
    }
    return 0;
} 