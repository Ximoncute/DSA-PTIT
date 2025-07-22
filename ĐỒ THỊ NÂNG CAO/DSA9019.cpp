#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

bool dfs(int v, int parent) {
    visited[v] = true;
    
    for (int u : adj[v]) {
        if (!visited[u]) {
            if (dfs(u, v))
                return true;
        }
        else if (u != parent) {
            return true; // Tìm thấy chu trình
        }
    }
    return false;
}

bool hasCycle(int n) {
    visited.assign(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        adj.assign(n + 1, vector<int>());
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if (hasCycle(n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 