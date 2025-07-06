#include <iostream>
#include <cmath>
using namespace std;

int n, ans, x[15];

bool check(int i, int j) {
    for (int k = 1; k < i; k++)
        if (x[k] == j || abs(x[k] - j) == abs(k - i))
            return false;
    return true;
}

void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (check(i, j)) {
            x[i] = j;
            if (i == n) ans++;
            else Try(i + 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        Try(1);
        cout << ans << endl;
    }
    return 0;
}