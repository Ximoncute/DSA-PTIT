#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n); // Sắp xếp tăng dần để bắt đầu từ hoán vị nhỏ nhất
    do {
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << endl;
    } while (next_permutation(a, a + n));
    return 0;
}