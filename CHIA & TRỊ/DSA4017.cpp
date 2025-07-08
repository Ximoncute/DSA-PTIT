#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n), b(n-1);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n-1; i++) cin >> b[i];
        int pos = n; // giả sử phần tử khác nằm cuối
        for (int i = 0; i < n-1; i++) {
            if (a[i] != b[i]) {
                pos = i + 1; // vị trí tính từ 1
                break;
            }
        }
        cout << pos << endl;
    }
    return 0;
}