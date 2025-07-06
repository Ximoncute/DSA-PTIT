#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[1005];
        for (int i = 1; i <= n; i++) cin >> a[i];
        // Tìm hoán vị tiếp theo
        int i = n - 1;
        while (i > 0 && a[i] > a[i + 1]) i--;
        if (i == 0) {
            // Nếu là hoán vị cuối cùng, in ra hoán vị đầu tiên
            for (int j = 1; j <= n; j++) cout << j << (j < n ? " " : "\n");
        } else {
            int k = n;
            while (a[k] < a[i]) k--;
            swap(a[i], a[k]);
            reverse(a + i + 1, a + n + 1);
            for (int j = 1; j <= n; j++) cout << a[j] << (j < n ? " " : "\n");
        }
    }
    return 0;
}