#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    adj.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    vector<int> result;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) result.push_back(i);
    }

    if (result.empty()) {
        cout << 0 << endl;
    } else {
        for (int x : result) cout << x << endl;