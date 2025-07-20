#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int V, E, start;
        cin >> V >> E >> start;
        
        // Khởi tạo danh sách kề
        vector<vector<int>> adj(V + 1);
        vector<bool> visited(V + 1, false);
        vector<int> result;
        
        // Đọc các cạnh
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        // Sắp xếp các danh sách kề để đảm bảo thứ tự duyệt
        for(int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        // Thực hiện BFS
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            
            // Duyệt các đỉnh kề
            for(int v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        // In kết quả
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
} 