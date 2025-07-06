#include <iostream>
#include <cmath>
using namespace std;

const long long MOD = 1000000007;

// Hàm tìm số đảo của n
long long reverse(long long n) {
    long long rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

// Hàm tính lũy thừa nhanh a^b mod MOD
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        long long r = reverse(n);
        long long result = power(n, r, MOD);
        
        cout << result << endl;
    }
    
    return 0;
}
