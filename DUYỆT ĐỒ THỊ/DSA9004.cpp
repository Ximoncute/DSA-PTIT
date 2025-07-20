#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> result;

void DFS(int u) {
    visited[u] = true;
    result.push_back(u);
    
    // Duyệt tất cả các đỉnh kề của u theo thứ tự tăng dần
    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int V, E, start;
        cin >> V >> E >> start;
        
        // Khởi tạo
        adj.assign(V + 1, vector<int>());
        visited.assign(V + 1, false);
        result.clear();
        
        // Đọc các cạnh và xây dựng danh sách kề
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // Đồ thị vô hướng
        }
        
        // Sắp xếp danh sách kề của mỗi đỉnh theo thứ tự tăng dần
        for (int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        // Thực hiện DFS từ đỉnh start
        DFS(start);
        
        // In kết quả
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    
    return 0;
} 