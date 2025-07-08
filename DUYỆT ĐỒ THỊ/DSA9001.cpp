#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int V, E;
        cin >> V >> E;
        
        // Khởi tạo danh sách kề
        vector<vector<int>> adj(V + 1);
        
        // Đọc các cạnh và xây dựng danh sách kề
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            // Đồ thị vô hướng nên thêm cả 2 chiều
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Sắp xếp danh sách kề của mỗi đỉnh theo thứ tự tăng dần
        for (int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        // In kết quả
        for (int i = 1; i <= V; i++) {
            cout << i << ":";
            for (int neighbor : adj[i]) {
                cout << " " << neighbor;
            }
            cout << endl;
        }
    }
    
    return 0;
} 