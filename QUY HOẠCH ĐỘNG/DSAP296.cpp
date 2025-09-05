#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int prefixSum[n + 1] = {0};
    int curSum = 0;
    for (int i = 1; i <= n; i++) {
        curSum = max(curSum, curSum + a[i]);
        prefixSum[i] = curSum;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefixSum[r] - prefixSum[l - 1] << endl;
    }
}