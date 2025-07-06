#include <iostream>
using namespace std;

long long f[94];

char solve(int n, long long k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= f[n-2]) return solve(n-2, k);
    else return solve(n-1, k - f[n-2]);
}

int main() {
    int t; cin >> t;
    f[1] = f[2] = 1;
    for (int i = 3; i <= 93; i++) f[i] = f[i-2] + f[i-1];
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}