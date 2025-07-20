#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> disc, low, parent;
vector<pair<int, int>> bridges;
int timer;

void bridgeUtil(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            bridgeUtil(v);
            
            // Cập nhật low[u]
            low[u] = min(low[u], low[v]);
            
            // Nếu low[v] > disc[u] thì (u,v) là cạnh cầu
            if (low[v] > disc[u]) {
                int a = min(u, v);
                int b = max(u, v);
                bridges.push_back({a, b});
            }
        }
        else if (v != parent[u]) {
            // Cạnh ngược (back edge)
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridges(int V) {
    // Khởi tạo
    visited.assign(V + 1, false);
    disc.assign(V + 1, -1);
    low.assign(V + 1, -1);
    parent.assign(V + 1, -1);
    bridges.clear();
    timer = 0;
    
    // Gọi DFS từ tất cả các đỉnh chưa thăm
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            bridgeUtil(i);
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int V, E;
        cin >> V >> E;
        
        // Khởi tạo danh sách kề
        adj.assign(V + 1, vector<int>());
        
        // Đọc các cạnh
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Tìm các cạnh cầu
        findBridges(V);
        
        // Sắp xếp các cạnh cầu theo thứ tự từ điển
        sort(bridges.begin(), bridges.end());
        
        // In kết quả
        for (int i = 0; i < bridges.size(); i++) {
            if (i > 0) cout << " ";
            cout << bridges[i].first << " " << bridges[i].second;
        }
        cout << endl;
    }
    
    return 0;
} 