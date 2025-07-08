#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a;
        for (int i = 1; i <= n; i++) a.push_back(i);
        vector<string> res;
        do {
            bool ok = true;
            for (int i = 1; i < n; i++) {
                if (abs(a[i] - a[i - 1]) == 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                string s = "";
                for (int i = 0; i < n; i++) s += char(a[i] + '0');
                res.push_back(s);
            }
        } while (next_permutation(a.begin(), a.end()));
        for (auto x : res) cout << x << endl;
        cout << endl;
    }
    return 0;
}