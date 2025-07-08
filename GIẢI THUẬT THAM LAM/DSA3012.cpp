#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt[256] = {0}, n = s.size(), ok = 1;
        for (char c : s) cnt[c]++;
        int mx = 0;
        for (int i = 'a'; i <= 'z'; i++) mx = max(mx, cnt[i]);
        if (mx > (n + 1) / 2) ok = -1;
        cout << ok << endl;
    }
    return 0;
}