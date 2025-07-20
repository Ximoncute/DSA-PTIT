#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void DFS(int u) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}

bool isConnected(int x, int y, int n) {
    // Reset mảng visited
    visited.assign(n + 1, false);
    
    // Thực hiện DFS từ đỉnh x
    DFS(x);
    
    // Kiểm tra xem có thể đến được đỉnh y hay không
    return visited[y];
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int N, M;
        cin >> N >> M;
        
        // Khởi tạo danh sách kề
        adj.assign(N + 1, vector<int>());
        
        // Đọc các cạnh (đồ thị vô hướng nên thêm cả 2 chiều)
        for(int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int Q;
        cin >> Q;
        
        // Xử lý các truy vấn
        while(Q--) {
            int x, y;
            cin >> x >> y;
            
            if(isConnected(x, y, N)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    
    return 0;
} 