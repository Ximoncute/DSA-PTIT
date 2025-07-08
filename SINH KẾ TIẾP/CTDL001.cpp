#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10];
    int total = 1 << ((n + 1) / 2);
    for (int mask = 0; mask < total; ++mask) {
        // Gán nửa đầu (bit cao nhất trước)
        for (int i = 0; i < (n + 1) / 2; ++i) {
            a[i] = (mask >> ((n + 1) / 2 - i - 1)) & 1;
        }
        // Gán nửa sau đối xứng
        for (int i = 0; i < n / 2; ++i) {
            a[n - i - 1] = a[i];
        }
        // In ra xâu
        for (int i = 0; i < n; ++i) {
            cout << a[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}