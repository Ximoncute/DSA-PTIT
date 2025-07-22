#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        // Tạo danh sách kề
        vector<vector<int>> adj(N + 1);
        
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // BFS từ node gốc (node 1) để tìm độ cao tối đa
        vector<int> dist(N + 1, -1);
        queue<int> q;
        
        // Bắt đầu từ node gốc 1
        q.push(1);
        dist[1] = 0;
        int maxHeight = 0;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : adj[curr]) {
                if (dist[neighbor] == -1) {  // Chưa thăm
                    dist[neighbor] = dist[curr] + 1;
                    maxHeight = max(maxHeight, dist[neighbor]);
                    q.push(neighbor);
                }
            }
        }
        
        cout << maxHeight << endl;
    }
    
    return 0;
}