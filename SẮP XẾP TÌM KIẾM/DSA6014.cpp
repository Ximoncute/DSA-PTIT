#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool found = false;
        for (int i = 2; i <= n/2; i++) {
            if (isPrime(i) && isPrime(n - i)) {
                cout << i << " " << n - i << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0;
} 