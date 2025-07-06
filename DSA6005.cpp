#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];
        set<int> sa(a.begin(), a.end()), sb(b.begin(), b.end());
        // Union
        vector<int> uni;
        set_union(sa.begin(), sa.end(), sb.begin(), sb.end(), back_inserter(uni));
        for (int x : uni) cout << x << " ";
        cout << endl;
        // Intersection
        vector<int> inter;
        set_intersection(sa.begin(), sa.end(), sb.begin(), sb.end(), back_inserter(inter));
        for (int x : inter) cout << x << " ";
        cout << endl;
    }
    return 0;
}