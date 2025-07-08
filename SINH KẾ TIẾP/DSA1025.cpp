#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<string> res;
vector<char> a;

void Try(int idx, string s) {
    if (s.size() == k) {
        res.push_back(s);
        return;
    }
    for (int i = idx; i < n; ++i) {
        Try(i + 1, s + a[i]);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.clear();
        res.clear();
        for (int i = 0; i < n; ++i) a.push_back('A' + i);
        Try(0, "");
        for (auto &x : res) cout << x << endl;
    }
    return 0;
}