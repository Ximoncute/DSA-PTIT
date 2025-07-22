#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int u) {
    visited[u] = true;
    int count = 1; // Đếm đỉnh hiện tại
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            count += dfs(v);
        }
    }
    
    return count;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        // Khởi tạo
        adj.assign(N + 1, vector<int>());
        visited.assign(N + 1, false);
        
        // Đọc các cạnh
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int maxSize = 0;
        
        // Duyệt tất cả các đỉnh để tìm thành phần liên thông
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                int componentSize = dfs(i);
                maxSize = max(maxSize, componentSize);
            }
        }
        
        cout << maxSize << "\n";
    }
    
    return 0;
} 