#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int vertex, int color, vector<vector<int>>& adj, vector<int>& colors, int V) {
    // Kiểm tra xem có thể tô màu 'color' cho đỉnh 'vertex' hay không
    for(int i = 1; i <= V; i++) {
        if(adj[vertex][i] && colors[i] == color) {
            return false; // Đỉnh kề đã có màu này
        }
    }
    return true;
}

bool graphColoringUtil(int vertex, vector<vector<int>>& adj, vector<int>& colors, int V, int M) {
    // Nếu đã tô màu hết tất cả đỉnh
    if(vertex > V) {
        return true;
    }
    
    // Thử tô từng màu cho đỉnh hiện tại
    for(int color = 1; color <= M; color++) {
        if(isSafe(vertex, color, adj, colors, V)) {
            colors[vertex] = color;
            
            // Đệ quy tô màu cho đỉnh tiếp theo
            if(graphColoringUtil(vertex + 1, adj, colors, V, M)) {
                return true;
            }
            
            // Backtrack
            colors[vertex] = 0;
        }
    }
    
    return false;
}

bool canColorGraph(vector<vector<int>>& adj, int V, int M) {
    vector<int> colors(V + 1, 0); // Khởi tạo tất cả đỉnh chưa có màu
    return graphColoringUtil(1, adj, colors, V, M);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        int V, E, M;
        cin >> V >> E >> M;
        
        // Khởi tạo ma trận kề
        vector<vector<int>> adj(V + 1, vector<int>(V + 1, 0));
        
        // Đọc các cạnh
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            if(u >= 1 && u <= V && v >= 1 && v <= V && u != v) {
                adj[u][v] = 1;
                adj[v][u] = 1; // Đồ thị vô hướng
            }
        }
        
        // Kiểm tra có thể tô màu hay không
        if(canColorGraph(adj, V, M)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 