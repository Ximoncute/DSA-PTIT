#include <iostream>
using namespace std;

char solve(int n, int k) {
    if(n == 1) return 'A';
    int mid = (1 << (n-1));
    if(k == mid) return 'A' + n - 1;
    if(k < mid) return solve(n-1, k);
    return solve(n-1, k - mid);
}

int main() {
    int T; cin >> T;
    while(T--) {
        int n, k; cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}