#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, V, E;
vector<int> adj[11];
bool visited[11];
bool found = false;

// Hàm DFS để kiểm tra đường đi Hamilton
void dfs(int u, int count) {
    if (count == V) {
        found = true;
        return;
    }
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(v, count + 1);
            visited[v] = false;
        }
    }
}

bool hasHamiltonianPath() {
    for (int i = 1; i <= V; ++i) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        found = false;
        dfs(i, 1);
        if (found) return true;
    }
    return false;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> V >> E;
        for (int i = 1; i <= V; ++i)
            adj[i].clear();
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);  // vì là đồ thị vô hướng
        }

        if (hasHamiltonianPath())
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
