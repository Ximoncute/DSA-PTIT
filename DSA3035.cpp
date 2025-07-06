#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n), pos(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int res = 1, cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] > pos[i-1]) cnt++;
        else cnt = 1;
        if (cnt > res) res = cnt;
    }
    cout << n - res << endl;
    return 0;
}