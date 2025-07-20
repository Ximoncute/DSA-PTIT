#include<iostream>
#include<vector>
using namespace std;

bool DFS(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            // Nếu tìm thấy chu trình trong subtree
            if(DFS(v, u, adj, visited)) {
                return true;
            }
        }
        // Nếu v đã được thăm và không phải parent của u
        // thì có back edge → tồn tại chu trình
        else if(v != parent) {
            return true;
        }
    }
    
    return false;
}

bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V + 1, false);
    
    // Kiểm tra tất cả các thành phần liên thông
    for(int i = 1; i <= V; i++) {
        if(!visited[i]) {
            if(DFS(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        int V, E;
        cin >> V >> E;
        
        // Khởi tạo danh sách kề
        vector<vector<int>> adj(V + 1);
        
        // Đọc các cạnh
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            if(u >= 1 && u <= V && v >= 1 && v <= V && u != v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        // Kiểm tra chu trình
        if(hasCycle(V, adj)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 