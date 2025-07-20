#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        int V, E;
        cin >> V >> E;
        
        // Khởi tạo danh sách kề (local variables)
        vector<vector<int>> adj(V + 1);
        vector<bool> visited(V + 1, false);
        
        // Đọc các cạnh (đồ thị vô hướng nên thêm cả 2 chiều)
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            // Kiểm tra bounds để tránh lỗi
            if(u >= 1 && u <= V && v >= 1 && v <= V) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        // Đếm số thành phần liên thông bằng BFS
        int componentCount = 0;
        
        for(int i = 1; i <= V; i++) {
            if(!visited[i]) {
                // Tìm thấy một thành phần liên thông mới
                // Thực hiện BFS từ đỉnh i
                queue<int> q;
                q.push(i);
                visited[i] = true;
                
                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    
                    // Duyệt tất cả đỉnh kề với u
                    for(int v : adj[u]) {
                        if(!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                
                componentCount++;
            }
        }
        
        cout << componentCount << "\n";
    }
    
    return 0;
} 