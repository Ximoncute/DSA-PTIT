#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<int> depth;

// DFS để tính parent và depth của mỗi node
void dfs(int node, int par, int d) {
    parent[node] = par;
    depth[node] = d;
    
    for (int neighbor : adj[node]) {
        if (neighbor != par) {
            dfs(neighbor, node, d + 1);
        }
    }
}

// Tìm LCA của hai node u và v
int findLCA(int u, int v) {
    // Đưa u và v về cùng độ sâu
    while (depth[u] > depth[v]) {
        u = parent[u];
    }
    while (depth[v] > depth[u]) {
        v = parent[v];
    }
    
    // Tìm ancestor chung
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    
    return u;
}

// Tính khoảng cách giữa hai node
int getDistance(int u, int v) {
    int lca = findLCA(u, v);
    return depth[u] + depth[v] - 2 * depth[lca];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        // Khởi tạo
        adj.assign(N + 1, vector<int>());
        parent.assign(N + 1, -1);
        depth.assign(N + 1, 0);
        
        // Đọc cạnh
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // DFS từ node gốc để tính parent và depth
        dfs(1, -1, 0);
        
        int Q;
        cin >> Q;
        
        // Xử lý truy vấn
        for (int i = 0; i < Q; i++) {
            int u, v;
            cin >> u >> v;
            cout << getDistance(u, v) << endl;
        }
    }
    
    return 0;
}