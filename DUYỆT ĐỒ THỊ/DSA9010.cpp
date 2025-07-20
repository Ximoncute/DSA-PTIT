#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishStack) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            DFS1(v, adj, visited, finishStack);
        }
    }
    finishStack.push(u);
}

void DFS2(int u, vector<vector<int>>& adjT, vector<bool>& visited) {
    visited[u] = true;
    for(int v : adjT[u]) {
        if(!visited[v]) {
            DFS2(v, adjT, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--) {
        int V, E;
        cin >> V >> E;
        
        // Khởi tạo đồ thị gốc và đồ thị chuyển vị
        vector<vector<int>> adj(V + 1);        // Đồ thị gốc
        vector<vector<int>> adjT(V + 1);       // Đồ thị chuyển vị (transpose)
        
        // Đọc các cạnh
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            if(u >= 1 && u <= V && v >= 1 && v <= V) {
                adj[u].push_back(v);    // Cạnh u -> v trong đồ thị gốc
                adjT[v].push_back(u);   // Cạnh v -> u trong đồ thị chuyển vị
            }
        }
        
        // Bước 1: DFS trên đồ thị gốc để tìm thứ tự finish time
        vector<bool> visited(V + 1, false);
        stack<int> finishStack;
        
        for(int i = 1; i <= V; i++) {
            if(!visited[i]) {
                DFS1(i, adj, visited, finishStack);
            }
        }
        
        // Bước 2: DFS trên đồ thị chuyển vị theo thứ tự finish time giảm dần
        fill(visited.begin(), visited.end(), false);
        int componentCount = 0;
        
        while(!finishStack.empty()) {
            int u = finishStack.top();
            finishStack.pop();
            
            if(!visited[u]) {
                DFS2(u, adjT, visited);
                componentCount++;
            }
        }
        
        // Nếu có đúng 1 thành phần liên thông mạnh thì đồ thị liên thông mạnh
        if(componentCount == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
} 