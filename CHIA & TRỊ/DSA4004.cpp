#include <iostream>
using namespace std;

int solve(int n, long long k) {
    if (n == 1) return 1;
    long long mid = (1LL << (n - 1));
    if (k == mid) return n;
    if (k < mid) return solve(n - 1, k);
    return solve(n - 1, k - mid);
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}