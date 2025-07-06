#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> a, tmp;
vector<vector<int>> res;

void Try(int i, int sum) {
    if (sum == k) {
        res.push_back(tmp);
        return;
    }
    for (int j = i; j < n; j++) {
        if (sum + a[j] <= k) {
            tmp.push_back(a[j]);
            Try(j + 1, sum + a[j]);
            tmp.pop_back();
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        res.clear(); tmp.clear();
        Try(0, 0);
        if (res.empty()) cout << -1;
        else {
            for (auto v : res) {
                cout << "[";
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i];
                    if (i < v.size() - 1) cout << " ";
                }
                cout << "] ";
            }
        }
        cout << endl;
    }
    return 0;
}