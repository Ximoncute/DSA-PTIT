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
            adj[u].push_back(v); // Thêm v vào danh sách kề của u
        }
        
        // Sắp xếp danh sách kề của mỗi đỉnh theo thứ tự tăng dần
        for (int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        // In ra danh sách kề
        for (int i = 1; i <= V; i++) {
            cout << i << ":";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << " " << adj[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
} 