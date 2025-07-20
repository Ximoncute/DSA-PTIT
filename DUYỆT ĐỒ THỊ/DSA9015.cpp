#include<iostream>
#include<vector>
using namespace std;

// 0: WHITE (chưa thăm), 1: GRAY (đang xử lý), 2: BLACK (đã xử lý xong)
bool DFS(int u, vector<vector<int>>& adj, vector<int>& color) {
    color[u] = 1; // Đánh dấu đang xử lý (GRAY)
    
    for(int v : adj[u]) {
        if(color[v] == 1) {
            // Nếu v đang được xử lý → back edge → có chu trình
            return true;
        }
        if(color[v] == 0 && DFS(v, adj, color)) {
            // Nếu v chưa thăm và tìm thấy chu trình trong subtree
            return true;
        }
    }
    
    color[u] = 2; // Đánh dấu đã xử lý xong (BLACK)
    return false;
}

bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<int> color(V + 1, 0); // Tất cả đỉnh ban đầu là WHITE
    
    // Kiểm tra tất cả các thành phần liên thông
    for(int i = 1; i <= V; i++) {
        if(color[i] == 0) {
            if(DFS(i, adj, color)) {
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
                adj[u].push_back(v); // Chỉ thêm một chiều u → v
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