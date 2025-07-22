#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int n, vector<vector<int>>& adj) {
    vector<int> color(n + 1, -1); // -1: chưa tô màu, 0: màu 0, 1: màu 1
    
    // Kiểm tra từng thành phần liên thông
    for (int start = 1; start <= n; start++) {
        if (color[start] == -1) {
            // BFS để tô màu
            queue<int> q;
            q.push(start);
            color[start] = 0;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        // Tô màu khác với đỉnh u
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        // Hai đỉnh kề nhau cùng màu -> không phải đồ thị hai phía
                        return false;
                    }
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
        
        vector<vector<int>> adj(N + 1);
        
        // Đọc các cạnh
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Kiểm tra và in kết quả
        if (isBipartite(N, adj)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 