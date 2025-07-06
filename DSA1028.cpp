#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, K;
vector<int> arr, comb;

void Try(int start, int cnt) {
    if (cnt == K) {
        for (int i = 0; i < K; ++i) {
            cout << comb[i] << (i == K-1 ? "\n" : " ");
        }
        return;
    }
    for (int i = start; i <= arr.size() - (K - cnt); ++i) {
        comb[cnt] = arr[i];
        Try(i + 1, cnt + 1);
    }
}

int main() {
    cin >> N >> K;
    set<int> s;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        s.insert(x);
    }
    arr.assign(s.begin(), s.end());
    sort(arr.begin(), arr.end());
    comb.resize(K);
    Try(0, 0);
    return 0;
}