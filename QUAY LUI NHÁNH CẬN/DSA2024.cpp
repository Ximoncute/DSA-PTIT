#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, a[25];
vector<string> res;

void Try(int i, vector<int> v) {
    if (v.size() >= 2) {
        string s = "";
        for (int k = 0; k < v.size(); k++) {
            s += to_string(v[k]);
            if (k < v.size() - 1) s += " ";
        }
        res.push_back(s);
    }
    for (int j = i + 1; j < n; j++) {
        if (a[j] > v.back()) {
            v.push_back(a[j]);
            Try(j, v);
            v.pop_back();
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    res.clear();
    for (int i = 0; i < n; i++) {
        vector<int> v;
        v.push_back(a[i]);
        Try(i, v);
    }
    sort(res.begin(), res.end());
    for (auto s : res) cout << s << endl;
    return 0;
}