#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> ranges(N);
    vector<int> coords;

    for (int i = 0; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        ranges[i] = {u, v};
        coords.push_back(u);
        coords.push_back(v + 1);
    }

    int Q;
    cin >> Q;
    vector<int> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
        coords.push_back(queries[i]);
    }

    // Ép tọa độ
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    unordered_map<int, int> compress;
    for (int i = 0; i < coords.size(); ++i) {
        compress[coords[i]] = i;
    }

    vector<int> cnt(coords.size() + 2, 0);

    // Gán dải
    for (auto [u, v] : ranges) {
        cnt[compress[u]]++;
        cnt[compress[v + 1]]--; // nếu bạn đã lưu v+1 ở trên
    }

    // Prefix sum
    for (int i = 1; i < cnt.size(); ++i)
        cnt[i] += cnt[i - 1];

    // Trả lời truy vấn
    for (int x : queries) {
        cout << cnt[compress[x]] << '\n';
    }

    return 0;
}