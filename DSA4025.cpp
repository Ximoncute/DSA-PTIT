#include <iostream>
using namespace std;
const int MOD = 1e9+7;

struct Matrix {
    long long m[2][2];
    Matrix() {
        m[0][0] = m[0][1] = m[1][0] = m[1][1] = 0;
    }
};

Matrix mul(Matrix a, Matrix b) {
    Matrix res;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                res.m[i][j] = (res.m[i][j] + a.m[i][k]*b.m[k][j]%MOD)%MOD;
    return res;
}

Matrix power(Matrix a, long long n) {
    Matrix res;
    res.m[0][0] = res.m[1][1] = 1;
    while(n) {
        if(n&1) res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

long long fib(long long n) {
    if(n == 0) return 0;
    Matrix base;
    base.m[0][0] = 1; base.m[0][1] = 1;
    base.m[1][0] = 1; base.m[1][1] = 0;
    Matrix res = power(base, n-1);
    return res.m[0][0];
}

int main() {
    int T; cin >> T;
    while(T--) {
        long long n; cin >> n;
        cout << fib(n) << endl;
    }
    return 0;
}