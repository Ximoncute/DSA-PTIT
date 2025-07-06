#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<string> a, tmp;

void Try(int i, int cnt) {
    if (cnt == k) {
        for (int j = 0; j < k; j++) cout << tmp[j] << (j == k-1 ? "\n" : " ");
        return;
    }
    for (int j = i; j < a.size(); j++) {
        tmp.push_back(a[j]);
        Try(j + 1, cnt + 1);
        tmp.pop_back();
    }
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    Try(0, 0);
    return 0;
}