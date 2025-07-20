#include<iostream>
#include<vector>
using namespace std;

bool DFS(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;  // Đánh dấu u đang trong recursion stack
    
    for(int v : adj[u]) {
        // Nếu v chưa được thăm và tìm thấy chu trình trong subtree
        if(!visited[v] && DFS(v, adj, visited, recStack)) {
            return true;
        }
        // Nếu v đang trong recursion stack → có chu trình
        else if(recStack[v]) {
            return true;
        }
    }
    
    recStack[u] = false;  // Loại u khỏi recursion stack
    return false;
}

bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V + 1, false);
    vector<bool> recStack(V + 1, false);
    
    // Kiểm tra tất cả các thành phần liên thông
    for(int i = 1; i <= V; i++) {
        if(!visited[i]) {
            if(DFS(i, adj, visited, recStack)) {
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
        
        // Đọc các cạnh (đồ thị có hướng)
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            if(u >= 1 && u <= V && v >= 1 && v <= V && u != v) {
                adj[u].push_back(v);  // Chỉ thêm một chiều u → v
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