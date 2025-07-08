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
        for (int i = 1; i <= n; i++) a[i] = i;
        do {
            for (int i = 1; i <= n; i++) cout << a[i];
            cout << " ";
        } while (next_permutation(a + 1, a + n + 1));
        cout << endl;
    }
    return 0;
}