#include <iostream>
using namespace std;
const long long MOD = 123456789;

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        cout << power(2, n - 1) << endl;
    }
    return 0;
}