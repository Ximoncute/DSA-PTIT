#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[11][11];
vector<string> res;

void Try(int i, int j, string s) {
    if (i == n - 1 && j == n - 1) {
        res.push_back(s);
        return;
    }
    // Đi xuống
    if (i + 1 < n && a[i + 1][j] == 1) {
        a[i][j] = 0;
        Try(i + 1, j, s + "D");
        a[i][j] = 1;
    }
    // Đi sang phải
    if (j + 1 < n && a[i][j + 1] == 1) {
        a[i][j] = 0;
        Try(i, j + 1, s + "R");
        a[i][j] = 1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        res.clear();
        if (a[0][0] == 1) Try(0, 0, "");
        if (res.size() == 0) cout << -1;
        else {
            sort(res.begin(), res.end());
            for (string x : res) cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}