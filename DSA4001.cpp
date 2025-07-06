#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;

long long power(long long n, long long k) {
    long long res = 1;
    while (k) {
        if (k % 2) res = res * n % MOD;
        n = n * n % MOD;
        k /= 2;
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << power(n, k) << endl;
    }
    return 0;
}