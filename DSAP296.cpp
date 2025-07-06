#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        int L, R;
        cin >> L >> R;
        int max_sum = 0, cur_sum = 0;
        for (int i = L; i <= R; i++) {
            cur_sum = max(0, cur_sum + a[i]);
            max_sum = max(max_sum, cur_sum);
        }
        cout << max_sum << endl;
    }
    return 0;
}