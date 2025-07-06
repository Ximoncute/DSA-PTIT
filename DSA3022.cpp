#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int res = max(a[n-1]*a[n-2], a[0]*a[1]);
    res = max(res, a[n-1]*a[n-2]*a[n-3]);
    res = max(res, a[0]*a[1]*a[n-1]);
    cout << res << endl;
    return 0;
}