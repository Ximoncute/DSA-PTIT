#include <iostream>
using namespace std;

int gt(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, a[10], used[10] = {0};
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j < a[i]; j++)
                if (!used[j]) cnt++;
            ans += cnt * gt(n - i);
            used[a[i]] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}