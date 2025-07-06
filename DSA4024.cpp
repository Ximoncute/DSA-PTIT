#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9+7;

typedef vector<vector<long long>> matrix;

matrix mul(const matrix &a, const matrix &b, int n) {
    matrix res(n, vector<long long>(n, 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]%MOD)%MOD;
    return res;
}

matrix power(matrix a, long long k, int n) {
    matrix res(n, vector<long long>(n, 0));
    for(int i=0;i<n;i++) res[i][i]=1;
    while(k) {
        if(k&1) res = mul(res, a, n);
        a = mul(a, a, n);
        k >>= 1;
    }
    return res;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int n; long long k;
        cin >> n >> k;
        matrix a(n, vector<long long>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];
        matrix x = power(a, k, n);
        long long ans = 0;
        for(int i=0;i<n;i++)
            ans = (ans + x[i][n-1])%MOD;
        cout << ans << endl;
    }
    return 0;
}