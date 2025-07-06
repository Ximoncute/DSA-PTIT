#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        int sundays = s / 7;
        int buy_days = s - sundays;
        int total = s * m;
        if (n < m || total > buy_days * n) cout << -1 << endl;
        else {
            int res = total / n;
            if (total % n) res++;
            cout << res << endl;
        }
    }
    return 0;
}