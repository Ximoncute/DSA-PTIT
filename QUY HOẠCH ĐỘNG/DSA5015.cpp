#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long permutation(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    
    long long result = 1;
    
    // Calculate n × (n-1) × ... × (n-k+1)
    for (int i = 0; i < k; i++) {
        result = (result * (n - i)) % MOD;
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        
        long long result = permutation(n, k);
        cout << result << endl;
    }
    
    return 0;
} 