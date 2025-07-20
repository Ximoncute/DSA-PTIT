#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> BFS(vector<vector<int>>& adj, int start, int V) {
    vector<bool> visited(V + 1, false);
    vector<int> result;
    queue<int> q;
    
    // Bắt đầu từ đỉnh start
    visited[start] = true;
    q.push(start);
    result.push_back(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        // Duyệt tất cả các đỉnh kề của u theo thứ tự tăng dần
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                result.push_back(v);
            }
        }
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int V, E, start;
        cin >> V >> E >> start;
        
        // Khởi tạo danh sách kề
        vector<vector<int>> adj(V + 1);
        
        // Đọc các cạnh từ E dòng riêng biệt
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
        
        // Thực hiện BFS từ đỉnh start
        vector<int> result = BFS(adj, start, V);
        
        // In kết quả
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    
    return 0;
} 