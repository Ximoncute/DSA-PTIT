#include <iostream>
using namespace std;

int m, n, ans;

void Try(int i, int j) {
    if (i == m - 1 && j == n - 1) {
        ans++;
        return;
    }
    if (i + 1 < m) Try(i + 1, j);
    if (j + 1 < n) Try(i, j + 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        int a[105][105];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        ans = 0;
        Try(0, 0);
        cout << ans << endl;
    }
    return 0;
}