#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k, a[41], b[41];
        cin >> n >> k;
        for (int i = 1; i <= k; i++) cin >> a[i];
        // Tìm tổ hợp tiếp theo
        int i = k;
        while (i > 0 && a[i] == n - k + i) i--;
        if (i == 0) {
            // Đã là tổ hợp cuối cùng
            cout << k << endl;
        } else {
            for (int j = 1; j <= k; j++) b[j] = a[j];
            a[i]++;
            for (int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
            // Đếm số phần tử mới
            int cnt = 0;
            for (int j = 1; j <= k; j++) {
                bool found = false;
                for (int t = 1; t <= k; t++) {
                    if (a[j] == b[t]) {
                        found = true;
                        break;
                    }
                }
                if (!found) cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}