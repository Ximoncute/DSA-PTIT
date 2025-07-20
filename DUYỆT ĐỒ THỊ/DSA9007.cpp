#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int V, E, s, t;
        cin >> V >> E >> s >> t;
        
        // Khởi tạo danh sách kề
        vector<vector<int>> adj(V + 1);
        vector<bool> visited(V + 1, false);
        vector<int> parent(V + 1, -1);
        
        // Đọc các cạnh (đồ thị vô hướng nên thêm cả 2 chiều)
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // Thêm cạnh ngược vì đồ thị vô hướng
        }
        
        // Sắp xếp các danh sách kề để đảm bảo thứ tự duyệt
        for(int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        // Thực hiện BFS
        queue<int> q;
        q.push(s);
        visited[s] = true;
        bool found = false;
        
        while(!q.empty() && !found) {
            int u = q.front();
            q.pop();
            
            if(u == t) {
                found = true;
                break;
            }
            
            // Duyệt các đỉnh kề
            for(int v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        
        // Tái tạo và in đường đi
        if(found) {
            vector<int> path;
            int current = t;
            
            // Truy ngược từ đích về nguồn
            while(current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            
            // Đảo ngược để có đường đi từ s đến t
            reverse(path.begin(), path.end());
            
            // In đường đi
            for(int i = 0; i < path.size(); i++) {
                cout << path[i];
                if(i < path.size() - 1) cout << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    
    return 0;
} 