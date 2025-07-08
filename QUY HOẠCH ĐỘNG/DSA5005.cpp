#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int LIS(vector<int>& pos) {
    vector<int> tail;
    for(int x : pos) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if(it == tail.end()) {
            tail.push_back(x);
        } else {
            *it = x;
        }
    }
    return tail.size();
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        sort(a.begin(), a.end());
        
        vector<int> positions(n);
        for(int i = 0; i < n; i++) {
            positions[i] = a[i].second;
        }
        
        int lis = LIS(positions);
        cout << n - lis << endl;
    }
    return 0;
}
