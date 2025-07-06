#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        int l = 0, r = n - 1;
        // Tìm l
        while (l < n - 1 && a[l] <= a[l + 1]) l++;
        // Nếu đã sắp xếp
        if (l == n - 1) {
            cout << "0 0\n";
            continue;
        }
        // Tìm r
        while (r > 0 && a[r] >= a[r - 1]) r--;

        // Tìm min, max trong đoạn l..r
        int mn = *min_element(a.begin() + l, a.begin() + r + 1);
        int mx = *max_element(a.begin() + l, a.begin() + r + 1);

        // Mở rộng l sang trái nếu cần
        while (l > 0 && a[l - 1] > mn) l--;
        // Mở rộng r sang phải nếu cần
        while (r < n - 1 && a[r + 1] < mx) r++;

        cout << l + 1 << " " << r + 1 << "\n";
    }
    return 0;
}