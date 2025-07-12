#include <iostream>
using namespace std;

const long long MOD = 1000000007;

// Function to calculate modular inverse using Fermat's little theorem
long long modInverse(long long a) {
    long long result = 1;
    long long power = MOD - 2;
    a = a % MOD;
    
    while (power > 0) {
        if (power & 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        power >>= 1;
    }
    
    return result;
}

// Function to calculate C(n, r) mod MOD
long long combination(int n, int r) {
    if (r > n || r < 0) return 0;
    if (r == 0 || r == n) return 1;
    
    long long numerator = 1;
    long long denominator = 1;
    
    // Calculate C(n, r) = n! / (r! * (n-r)!)
    // We'll calculate it as (n * (n-1) * ... * (n-r+1)) / (r * (r-1) * ... * 1)
    for (int i = 0; i < r; i++) {
        numerator = (numerator * (n - i)) % MOD;
        denominator = (denominator * (i + 1)) % MOD;
    }
    
    return (numerator * modInverse(denominator)) % MOD;
}

int countNonDecreasingNumbers(int n) {
    // This is equivalent to finding the number of ways to choose n digits
    // from {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} with repetition allowed
    // in non-decreasing order.
    // This is a stars and bars problem: C(n + 10 - 1, n) = C(n + 9, n)
    return combination(n + 9, n);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int result = countNonDecreasingNumbers(N);
        cout << result << endl;
    }
    
    return 0;
} 