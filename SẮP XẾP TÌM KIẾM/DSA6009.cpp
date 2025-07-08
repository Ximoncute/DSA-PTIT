#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> A(n);
        for (int &x : A) cin >> x;
        unordered_map<int, int> cnt;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += cnt[k - A[i]];
            cnt[A[i]]++;
        }
        cout << res << "\n";
    }
    return 0;
}