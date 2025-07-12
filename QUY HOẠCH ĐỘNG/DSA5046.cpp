#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long power(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

long long modInverse(long long a, long long mod) {
    return power(a, mod - 2, mod);
}

long long solve(long long n, int k) {
    if (n == 0) return 0;
    
    // We need k+2 points to interpolate a polynomial of degree k+1
    int points = k + 2;
    vector<long long> y(points);
    
    // Calculate y[i] = sum of k-th powers from 1 to i
    y[0] = 0;
    for (int i = 1; i < points; i++) {
        y[i] = (y[i-1] + power(i, k, MOD)) % MOD;
    }
    
    // If n is small enough, we can return directly
    if (n < points) {
        return y[n];
    }
    
    // Use Lagrange interpolation
    long long result = 0;
    
    for (int i = 0; i < points; i++) {
        long long term = y[i];
        long long num = 1, den = 1;
        
        for (int j = 0; j < points; j++) {
            if (i != j) {
                num = (num * ((n - j) % MOD + MOD)) % MOD;
                den = (den * ((i - j) % MOD + MOD)) % MOD;
            }
        }
        
        term = (term * num) % MOD;
        term = (term * modInverse(den, MOD)) % MOD;
        result = (result + term) % MOD;
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        int k;
        cin >> n >> k;
        
        cout << solve(n, k) << endl;
    }
    
    return 0;
} 