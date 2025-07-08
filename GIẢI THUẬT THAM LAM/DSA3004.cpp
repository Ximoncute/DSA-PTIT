#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        string s1 = "", s2 = "";
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) s1 += char(a[i] + '0');
            else s2 += char(a[i] + '0');
        }
        long long num1 = s1.empty() ? 0 : stoll(s1);
        long long num2 = s2.empty() ? 0 : stoll(s2);
        cout << num1 + num2 << endl;
    }
    return 0;
}