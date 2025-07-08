#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int min_sum = a[0] + a[1];

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = a[i] + a[j];
                if (abs(sum) < abs(min_sum)) {
                    min_sum = sum;
                }
            }
        }

        cout << min_sum << endl;
    }
    return 0;
}
