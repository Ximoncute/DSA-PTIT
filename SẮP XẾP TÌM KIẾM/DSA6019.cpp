#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second > b.second; // Tần suất cao hơn đứng trước
    }
    return a.first < b.first; // Nếu tần suất bằng nhau, số nhỏ hơn đứng trước
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        map<int, int> freq;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        
        vector<pair<int, int>> v;
        for (auto x : freq) {
            v.push_back({x.first, x.second});
        }
        
        sort(v.begin(), v.end(), compare);
        
        for (auto x : v) {
            for (int i = 0; i < x.second; i++) {
                cout << x.first << " ";
            }
        }
        cout << endl;
    }
    return 0;
} 