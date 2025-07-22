#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> component;

void dfs(int u) {
    visited[u] = true;
    component.push_back(u);
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

bool isCompleteGraph(const vector<int>& nodes) {
    int n = nodes.size();
    
    // Kiểm tra mỗi cặp đỉnh trong thành phần có kết nối không
    for (int i = 0; i < n; i++) {
        set<int> neighbors;
        for (int neighbor : adj[nodes[i]]) {
            neighbors.insert(neighbor);
        }
        
        // Đỉnh nodes[i] phải kết nối với tất cả đỉnh khác trong thành phần
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (neighbors.find(nodes[j]) == neighbors.end()) {
                    return false;
                }
            }
        }
    }
    
    return true;
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
        
        bool isPerfect = true;
        
        // Kiểm tra từng thành phần liên thông
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) {
                component.clear();
                dfs(i);
                
                // Kiểm tra thành phần này có phải đồ thị đầy đủ không
                if (!isCompleteGraph(component)) {
                    isPerfect = false;
                    break;
                }
            }
        }
        
        if (isPerfect) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 