#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int timer;

void DFS(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited, 
         vector<int>& disc, vector<int>& low, vector<bool>& isAP) {
    
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            children++;
            DFS(v, u, adj, visited, disc, low, isAP);
            
            // Cập nhật low value của u
            low[u] = min(low[u], low[v]);
            
            // Kiểm tra điều kiện đỉnh trụ
            // Trường hợp 1: u là root và có >= 2 con trong DFS tree
            if(parent == -1 && children > 1) {
                isAP[u] = true;
            }
            
            // Trường hợp 2: u không phải root và low[v] >= disc[u]
            if(parent != -1 && low[v] >= disc[u]) {
                isAP[u] = true;
            }
        }
        // Nếu v đã được thăm và không phải parent của u
        else if(v != parent) {
            low[u] = min(low[u], disc[v]);
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
        
        // Khởi tạo
        vector<vector<int>> adj(V + 1);
        vector<bool> visited(V + 1, false);
        vector<int> disc(V + 1);
        vector<int> low(V + 1);
        vector<bool> isAP(V + 1, false);
        timer = 0;
        
        // Đọc các cạnh
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            if(u >= 1 && u <= V && v >= 1 && v <= V && u != v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        
        // Tìm các đỉnh trụ
        for(int i = 1; i <= V; i++) {
            if(!visited[i]) {
                DFS(i, -1, adj, visited, disc, low, isAP);
            }
        }
        
        // Thu thập và sắp xếp kết quả
        vector<int> articulationPoints;
        for(int i = 1; i <= V; i++) {
            if(isAP[i]) {
                articulationPoints.push_back(i);
            }
        }
        
        sort(articulationPoints.begin(), articulationPoints.end());
        
        // In kết quả
        for(int i = 0; i < articulationPoints.size(); i++) {
            cout << articulationPoints[i];
            if(i < articulationPoints.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
} 