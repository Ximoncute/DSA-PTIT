#include<iostream>
#include<vector>
using namespace std;

void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            DFS(v, adj, visited);
        }
    }
}

bool isConnected(int N, vector<vector<int>>& adj) {
    vector<bool> visited(N + 1, false);
    
    // Tìm đỉnh đầu tiên có cạnh để bắt đầu DFS
    int start = -1;
    for(int i = 1; i <= N; i++) {
        if(!adj[i].empty()) {
            start = i;
            break;
        }
    }
    
    // Nếu không có cạnh nào và N = 1 thì là cây
    if(start == -1) {
        return N == 1;
    }
    
    // DFS từ đỉnh start
    DFS(start, adj, visited);
    
    // Kiểm tra tất cả đỉnh đã được thăm
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            return false;
        }
    }
    
    return true;
}

bool hasCycle(int N, vector<vector<int>>& adj) {
    vector<bool> visited(N + 1, false);
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            // DFS để kiểm tra chu trình
            vector<int> stack;
            vector<int> parent(N + 1, -1);
            
            stack.push_back(i);
            visited[i] = true;
            
            while(!stack.empty()) {
                int u = stack.back();
                stack.pop_back();
                
                for(int v : adj[u]) {
                    if(!visited[v]) {
                        visited[v] = true;
                        parent[v] = u;
                        stack.push_back(v);
                    }
                    else if(v != parent[u]) {
                        // Tìm thấy back edge → có chu trình
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

bool isTree(int N, vector<vector<int>>& adj) {
    // Điều kiện 1: Đồ thị phải liên thông
    if(!isConnected(N, adj)) {
        return false;
    }
    
    // Điều kiện 2: Đồ thị không được có chu trình
    if(hasCycle(N, adj)) {
        return false;
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        cin >> N;
        
        // Khởi tạo danh sách kề
        vector<vector<int>> adj(N + 1);
        
        // Đọc N-1 cạnh
        for(int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            if(u >= 1 && u <= N && v >= 1 && v <= N && u != v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        // Kiểm tra có phải cây không
        if(isTree(N, adj)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 