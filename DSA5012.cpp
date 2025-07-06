#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int T; cin >> T;
    vector<vector<int>> C(1001, vector<int>(1001, 0));
    for(int n=0; n<=1000; n++) {
        C[n][0] = C[n][n] = 1;
        for(int k=1; k<n; k++) {
            C[n][k] = (C[n-1][k-1] + C[n-1][k]) % MOD;
        }
    }
    while(T--) {
        int n, k; cin >> n >> k;
        cout << C[n][k] << endl;
    }
    return 0;
}