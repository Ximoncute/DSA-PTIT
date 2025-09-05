#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int countComponents(int N, const vector<vector<int>>& adj, int skip) {
    vector<bool> visited(N + 1, false);
    visited[skip] = true;
    int components = 0;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return components;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> adj(N + 1);
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxComp = 1, res = 0;
        for (int u = 1; u <= N; ++u) {
            int comp = countComponents(N, adj, u);
            if (comp > maxComp) {
                maxComp = comp;
                res = u;
            }
        }
        cout << res << endl;
    }
    return 0;
}