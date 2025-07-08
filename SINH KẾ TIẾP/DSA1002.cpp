#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int a[1005];
        for (int i = 1; i <= k; i++) cin >> a[i];
        int i = k;
        // Tìm vị trí tăng được
        while (i > 0 && a[i] == n - k + i) i--;
        if (i == 0) {
            // Đã là tập con cuối cùng, in ra tập đầu tiên
            for (int j = 1; j <= k; j++) cout << j << (j < k ? " " : "\n");
        } else {
            a[i]++;
            for (int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
            for (int j = 1; j <= k; j++) cout << a[j] << (j < k ? " " : "\n");
        }
    }
    return 0;
}