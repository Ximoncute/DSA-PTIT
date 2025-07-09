#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll primes[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
ll result;

ll power(ll base, ll exp) {
    ll res = 1;
    for (ll i = 0; i < exp; i++) {
        if (res > 1e18 / base) return 1e19;
        res *= base;
    }
    return res;
}

void backtrack(ll n, ll currentValue, int primeIndex) {
    if (n == 1) {
        result = min(result, currentValue);
        return;
    }
    
    if (primeIndex >= 20) return;
    if (currentValue >= result) return;
    
    for (ll div = 2; div * div <= n; div++) {
        if (n % div == 0) {
            ll newValue = power(primes[primeIndex], div - 1);
            if (newValue < 1e18 && currentValue <= 1e18 / newValue) {
                backtrack(n / div, currentValue * newValue, primeIndex + 1);
            }
            
            ll other = n / div;
            if (other != div) {
                newValue = power(primes[primeIndex], other - 1);
                if (newValue < 1e18 && currentValue <= 1e18 / newValue) {
                    backtrack(div, currentValue * newValue, primeIndex + 1);
                }
            }
        }
    }
    
    if (n > 1) {
        ll newValue = power(primes[primeIndex], n - 1);
        if (newValue < 1e18 && currentValue <= 1e18 / newValue) {
            backtrack(1, currentValue * newValue, primeIndex + 1);
        }
    }
}

ll solve(ll n) {
    if (n == 1) return 1;
    result = 1e18;
    backtrack(n, 1, 0);
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
} 