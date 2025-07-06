#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Đếm số y trong Y[] sao cho xy > yx
int count(int x, const vector<int>& Y, vector<int>& cntY) {
    if (x == 0) return 0;
    if (x == 1) return cntY[0];
    int m = Y.size();
    // lower_bound tìm số y > x
    int idx = upper_bound(Y.begin(), Y.end(), x) - Y.begin();
    int res = m - idx;
    // Cộng thêm số y = 0, y = 1
    res += cntY[0] + cntY[1];
    // Trừ trường hợp đặc biệt
    if (x == 2) res -= (cntY[3] + cntY[4]);
    if (x == 3) res += cntY[2];
    return res;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> X(n), Y(m), cntY(5, 0);
        for (int &x : X) cin >> x;
        for (int &y : Y) {
            cin >> y;
            if (y < 5) cntY[y]++;
        }
        sort(Y.begin(), Y.end());
        long long ans = 0;
        for (int x : X) {
            ans += count(x, Y, cntY);
        }
        cout << ans << "\n";
    }
    return 0;
}