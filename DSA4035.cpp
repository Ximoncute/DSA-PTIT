#include <iostream>
using namespace std;
const long long MOD = 1e9+7;

long long power(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    long long a, b;
    while(cin >> a >> b) {
        if(a == 0 && b == 0) break;
        cout << power(a, b) << endl;
    }
    return 0;
}