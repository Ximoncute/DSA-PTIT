#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int max_sum = a[0], curr = a[0];
        for (int i = 1; i < n; i++) {
            curr = max(a[i], curr + a[i]);
            max_sum = max(max_sum, curr);
        }
        cout << max_sum << endl;
    }
    return 0;
}