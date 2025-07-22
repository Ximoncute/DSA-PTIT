#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Hàm BFS để kiểm tra có thể đi từ start đến target không
bool canReach(vector<vector<int>>& adj, int start, int target, int N) {
    if (start == target) return true;
    
    vector<bool> visited(N + 1, false);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == target) return true;
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    
    return false;
}

int main() {
    int K, N, M;
    cin >> K >> N >> M;
    
    // Đọc vị trí ban đầu của K người
    vector<int> people(K);
    for (int i = 0; i < K; i++) {
        cin >> people[i];
    }
    
    // Xây dựng đồ thị có hướng
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    int count = 0;
    
    // Kiểm tra từng điểm có thể làm điểm họp mặt không
    for (int meeting_point = 1; meeting_point <= N; meeting_point++) {
        bool canAllReach = true;
        
        // Kiểm tra tất cả mọi người có thể đến meeting_point không
        for (int i = 0; i < K; i++) {
            if (!canReach(adj, people[i], meeting_point, N)) {
                canAllReach = false;
                break;
            }
        }
        
        if (canAllReach) {
            count++;
        }
    }
    
    cout << count << "\n";
    
    return 0;
} 