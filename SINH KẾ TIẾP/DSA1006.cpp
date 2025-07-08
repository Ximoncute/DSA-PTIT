#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a[11];
        for (int i = 1; i <= n; i++) a[i] = n - i + 1; // Khởi tạo dãy giảm dần
        do {
            for (int i = 1; i <= n; i++) cout << a[i];
            cout << " ";
        } while (prev_permutation(a + 1, a + n + 1));
        cout << endl;
    }
    return 0;
}