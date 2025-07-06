#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int>> v;
        v.push_back(a);
        while (v.back().size() > 1) {
            vector<int> b;
            for (int i = 0; i < v.back().size() - 1; i++)
                b.push_back(v.back()[i] + v.back()[i + 1]);
            v.push_back(b);
        }
        for (int i = v.size() - 1; i >= 0; i--) {
            cout << "[";
            for (int j = 0; j < v[i].size(); j++) {
                cout << v[i][j];
                if (j < v[i].size() - 1) cout << " ";
            }
            cout << "] ";
        }
        cout << endl;
    }
    return 0;
}