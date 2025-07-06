#include <iostream>
using namespace std;

int n, k, a[20];

void Try(int pos, int cnt) {
    if (pos > n) {
        if (cnt == k) {
            for (int i = 1; i <= n; i++) cout << a[i];
            cout << endl;
        }
        return;
    }
    // Đặt 0 ở vị trí pos
    a[pos] = 0;
    Try(pos + 1, cnt);
    // Đặt 1 ở vị trí pos nếu còn đủ chỗ cho bit 1
    if (cnt < k) {
        a[pos] = 1;
        Try(pos + 1, cnt + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        Try(1, 0);
    }
    return 0;
}