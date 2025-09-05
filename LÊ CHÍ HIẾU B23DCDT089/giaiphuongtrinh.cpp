#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double solve(int A, int B, int C) {
    double left = 0.0, right = 100.0;
    for (int iter = 0; iter < 100; ++iter) {
        double mid = (left + right) / 2.0;
        double val = A * mid * mid * mid + B * mid;
        if (val < C) left = mid;
        else right = mid;
    }
    return (left + right) / 2.0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    cout << fixed << setprecision(4);
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        cout << solve(A, B, C) << '\n';
    }
    return 0;
}
