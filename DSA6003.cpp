#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) v[i] = {arr[i], i};
    sort(v.begin(), v.end());
    vector<bool> visited(n, false);
    int swaps = 0;
    for (int i = 0; i < n; ++i) {
        if (visited[i] || v[i].second == i) continue;
        int cycle = 0, j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = v[j].second;
            ++cycle;
        }
        if (cycle > 0) swaps += cycle - 1;
    }
    return swaps;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << minSwaps(a) << endl;
    }
    return 0;
}